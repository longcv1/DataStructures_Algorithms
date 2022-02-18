#include "BST.h"
#include<iostream>

void BST::R_Insert(int key, Node* node)
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
}

void BST::Insert(int key)
{
   if (root == nullptr) {
      // Insert the first node into BST
      root = new Node(key, nullptr);
   }
   else {
      R_Insert(key, root);
   }
}

void BST::R_Remove(int key, Node* node)
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
         //remove node
         delete node;
         node = nullptr;
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
         //node->right_child = parent;
         node = nullptr;
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
         //node->left_child = parent;
         node = nullptr;
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

Node* BST::getPredecessor(Node* node)
{
   if (node->right_child != nullptr) {
      return getPredecessor(node->right_child);
   }
   return node;
}


void BST::Remove(int key)
{
   if (root == nullptr) {
      return;
   }
   R_Remove(key, root);
}

void BST::R_InOrder(Node* node)
{
   if (node) {
      R_InOrder(node->left_child);
      std::cout << node->data << " , ";
      R_InOrder(node->right_child);
   }
}

void BST::Traversal()
{
   R_InOrder(root);
}

Node* BST::R_GetMin(Node* node)
{
   if (node->left_child != nullptr) {
      return R_GetMin(node->left_child);
   }
   return node;
}

Node* BST::getMin()
{
   if (root == nullptr) {
      return nullptr;
   }
   return R_GetMin(root);
}

Node* BST::R_GetMax(Node* node)
{
   if (node->right_child != nullptr) {
      return R_GetMax(node->right_child);
   }
   return node;
}

Node* BST::getMax()
{
   if (root == nullptr) {
      return nullptr;
   }
   return R_GetMax(root);
}
