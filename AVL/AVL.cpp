#include "AVL.h"
#include<iostream>
#include<algorithm>

void AVL::R_InOrder(Node* node)
{
   if (node) {
      R_InOrder(node->left_child);
      std::cout << node->data << " , ";
      R_InOrder(node->right_child);
   }
}

void AVL::Traversal()
{
   R_InOrder(root);
}

Node* AVL::getPredecessor(Node* node)
{
   if (node->right_child != nullptr) {
      return getPredecessor(node->right_child);
   }
   return node;
}

int AVL::Height(Node* node)
{
   if (node == nullptr) {
      return -1;
   }
   return node->height;
}

void AVL::updateHeight(Node* node)
{
   node->height = std::max(Height(node->left_child), Height(node->right_child)) + 1;
}

int AVL::BalanceFactor(Node* node)
{
   if (node == nullptr) {
      return 0;
   }
   return Height(node->left_child) - Height(node->right_child);
}

void AVL::RightRotation(Node* node)
{
   Node* tempLeftChild = node->left_child;
   Node* grandChild = tempLeftChild->right_child;

   //Make rotation - new root node will be tempLeftChild
   tempLeftChild->right_child = node;
   node->left_child = grandChild;

   //Update parent node
   if (grandChild != nullptr) {
      grandChild->parent_node = node;
   }

   //Handle parents for the node
   Node* tempParent = node->parent_node;
   node->parent_node = tempLeftChild;
   tempLeftChild->parent_node = tempParent;

   //Hanlde the parent
   if (tempLeftChild->parent_node != nullptr && tempLeftChild->parent_node->left_child == node) {
      tempLeftChild->parent_node->left_child = tempLeftChild;
   }
   if (tempLeftChild->parent_node != nullptr && tempLeftChild->parent_node->right_child == node) {
      tempLeftChild->parent_node->right_child = tempLeftChild;
   }

   if (node == root) {
      root = tempLeftChild;
   }

   //Update height after rotation
   updateHeight(node);
   updateHeight(tempLeftChild);
}

void AVL::LeftRotation(Node* node)
{
   Node* tempRightChild = node->right_child;
   Node* grandChild = tempRightChild->left_child;

   //Make rotation - new root node will be tempRightChild
   tempRightChild->left_child = node;
   node->right_child = grandChild;

   //Update parent node
   if (grandChild != nullptr) {
      grandChild->parent_node = node;
   }

   //Handle parents for the node
   Node* tempParent = node->parent_node;
   node->parent_node = tempRightChild;
   tempRightChild->parent_node = tempParent;

   //Hanlde the parent
   if (tempRightChild->parent_node != nullptr && tempRightChild->parent_node->left_child == node) {
      tempRightChild->parent_node->left_child = tempRightChild;
   }
   if (tempRightChild->parent_node != nullptr && tempRightChild->parent_node->right_child == node) {
      tempRightChild->parent_node->right_child = tempRightChild;
   }

   if (node == root) {
      root = tempRightChild;
   }

   //Update height after rotation
   updateHeight(node);
   updateHeight(tempRightChild);
}

void AVL::FixViolation(Node* node)
{
   while (node != nullptr) {
      updateHeight(node);
      FixViolationHelper(node);
      node = node->parent_node;
   }
}

void AVL::FixViolationHelper(Node* node)
{
   int balance = BalanceFactor(node);
   if (balance > 1) {
      //left-right situation => left rotation
      if (BalanceFactor(node->left_child) < 0) {
         LeftRotation(node->left_child);
      }
      //left-left situation => right rotation
      RightRotation(node);
   }
   else if(balance < -1) {
      //right-left situation => right rotation
      if (BalanceFactor(node->right_child) < 0) {
         RightRotation(node->right_child);
      }
      //right-right situation => left rotation
      LeftRotation(node);
   }
}

void AVL::R_Insert(int key, Node* node)
{
   if (node == nullptr) return;

   if (key < node->data) {
      if (node->left_child != nullptr) {
         R_Insert(key, node->left_child);
      }
      else {
         node->left_child = new Node(key, node);
      }
   }
   else if (key > node->data) {
      if (node->right_child != nullptr) {
         R_Insert(key, node->right_child);
      }
      else {
         node->right_child = new Node(key, node);
      }
   }
   else {
      // If key equal to current data node,
      // Nothing to do
      return;
   }

   //Update again height of node
   updateHeight(node);

   //Fix violation
   FixViolation(node);
}

void AVL::Insert(int key)
{
   if (root == nullptr) {
      // Insert the first node into BST
      root = new Node(key, nullptr);
   }
   else {
      R_Insert(key, root);
   }
}

void AVL::R_Remove(int key, Node* node)
{
   if (key < node->data) {
      R_Remove(key, node->left_child);
   }
   else if (key > node->data) {
      R_Remove(key, node->right_child);
   }
   else {
      //If the node is a leaf node
      if (node->left_child == nullptr && node->right_child == nullptr) {
         Node* parent = node->parent_node;
         //Node is a left child
         if (parent != nullptr && parent->left_child == node) {
            parent->left_child = nullptr;
         }
         //Node is a right child
         else if (parent != nullptr && parent->right_child == node) {
            parent->right_child = nullptr;
         }
         //Root node is a delete node
         if (parent == nullptr) {
            root = nullptr;
         }

         //Remove node
         node = nullptr;

         //Update again height of node
         updateHeight(parent);
         FixViolation(parent);
      }
      //Remove if it has a single right child
      else if (node->left_child == nullptr && node->right_child != nullptr) {
         Node* parent = node->parent_node;
         //Node is a left child
         if (parent != nullptr && parent->left_child == node) {
            parent->left_child = node->right_child;
         }
         //Node is a right child
         else if (parent != nullptr && parent->right_child == node) {
            parent->right_child = node->right_child;
         }
         //Root node is a delete node
         if (parent == nullptr) {
            root = node->right_child;
         }
         //Update right child's parent
         node->right_child = parent;
         node = nullptr;

         //Update again height of node
         updateHeight(parent);
         FixViolation(parent);
      }
      //Remove if it has a single left child
      else if (node->left_child != nullptr && node->right_child == nullptr) {
         Node* parent = node->parent_node;
         //Node is a left child
         if (parent != nullptr && parent->left_child == node) {
            parent->left_child = node->left_child;
         }
         //Node is a right child
         else if (parent != nullptr && parent->right_child == node) {
            parent->right_child = node->left_child;
         }
         //Root node is a delete node
         if (parent == nullptr) {
            root = node->left_child;
         }
         //Update left child's parent
         node->left_child = parent;
         node = nullptr;

         //Update again height of node
         updateHeight(parent);
      }
      else {
         //Find the predecessor(max node of left sub tree)
         Node* predecessor = getPredecessor(node->left_child);
         int temp = predecessor->data;
         predecessor->data = node->data;
         node->data = temp;
         R_Remove(key, predecessor);
      }
   }
}

void AVL::Remove(int key)
{
   if (root == nullptr) {
      return;
   }
   R_Remove(key, root);
}