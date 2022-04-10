#include "BST.h"
#include<iostream>
using namespace BinarySearchTree;

void BST::init(int key)
{
   Node* t = new Node();
   t->data = key;
   root = t;
}

Node* BST::R_Search(Node* p, int key)
{
   using namespace std;

   if (p == nullptr) {
      return nullptr;
   }

   if (key == p->data) {
      return p;
   }

   if (key < p->data) {
      return R_Search(p->left_child, key);
   }
   else {
      return R_Search(p->right_child, key);
   }
}

Node* BST::Search(int key)
{
   Node* p = root;
   while (p != nullptr) {
      if (p->data == key) {
         return p;
      }
      if (key < p->data) {
         p = p->left_child;
      }
      else {
         p = p->right_child;
      }
   }
   return nullptr;
}
/// Recursive Insert
Node* R_Insert(Node* p, int key)
{
   Node* t;
   if (p == nullptr) {
      t = new Node();
      t->data = key;
      t->left_child = t->right_child = nullptr;
      return t;
   }
   if (key < p->data) {
      p->left_child = R_Insert(p->left_child, key);
   }
   else if (key > p->data) {
      p->right_child = R_Insert(p->right_child, key);
   }
   return p;
}

void BST::Insert(int key)
{
   Node* p = root;
   // Create a temp pointer
   Node* temp = p;

   if (p == nullptr) {
      temp = new Node();
      temp->data = key;
      root = temp;
      return;
   }

   while (p != nullptr) {
      temp = p;
      if (key == p->data) return;
      if (key < p->data) {
         p = p->left_child;
      }
      else {
         p = p->right_child;
      }
   }
   Node* newNode = new Node();
   newNode->data = key;
   if (newNode->data < temp->data) {
      temp->left_child = newNode;
   }
   else {
      temp->right_child = newNode;
   }
}

int BST::Height(BinarySearchTree::Node* p)
{
   if (p == nullptr) {
      return 0;
   }
   auto left = Height(p->left_child);
   auto right = Height(p->right_child);

   return left > right ? left++ : right++;
}

BinarySearchTree::Node* BST::InPrecessor(BinarySearchTree::Node* p)
{
   while (p && p->right_child != nullptr) {
      p = p->right_child;
   }
   return p;
}

BinarySearchTree::Node* BST::InSuccessor(BinarySearchTree::Node* p)
{
   while (p && p->left_child != nullptr) {
      p = p->left_child;
   }
   return p;
}

BinarySearchTree::Node* BST::Delete(BinarySearchTree::Node* p, int key)
{
   if (p == nullptr) return nullptr;
   if (p->left_child == nullptr && p->right_child == nullptr) {
      if (p == root) {
         root = nullptr;
      }
      delete p;
      return nullptr;
   }
   if (key < p->data) {
      p->left_child = Delete(p->left_child, key);
   }
   else if(key>p->data) {
      p->right_child = Delete(p->right_child, key);
   }
   else {
      if (Height(p->left_child) > Height(p->right_child)) {
         auto q = InPrecessor(p->left_child);
         p->data = q->data;
         p->left_child = Delete(p->left_child, q->data);
      }
      else {
         auto q = InSuccessor(p->right_child);
         p->data = q->data;
         p->right_child = Delete(p->right_child, q->data);
      }
   }
   return p;
}

void BST::preOrder(Node* p)
{
   if (p) {
      std::cout << p->data << "   " << std::flush;
      preOrder(p->left_child);
      preOrder(p->right_child);
   }
}

void BST::inOrder(BinarySearchTree::Node* p)
{
   if (p) {
      preOrder(p->left_child);
      std::cout << p->data << "   " << std::flush;
      preOrder(p->right_child);
   }
}

void BST::postOrder(BinarySearchTree::Node* p)
{
   if (p) {
      preOrder(p->left_child);
      preOrder(p->right_child);
      std::cout << p->data << "   " << std::flush;
   }
}
