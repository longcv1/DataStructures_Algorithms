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
   Node* pl = node->left_child;
   Node* plr = pl->right_child;

   pl->right_child = node;
   node->left_child = plr;

   if (plr != nullptr) {
      plr->parent_node = node;
   }

   Node* tempParent = node->parent_node;
   node->parent_node = pl;
   pl->parent_node = tempParent;
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

   // Check balance factor and then rotation
   
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