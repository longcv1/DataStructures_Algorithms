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

Node* BST::Search(Node* p, int key)
{
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

void BST::Insert(/*BinarySearchTree::Node* p,*/ int key)
{
   Node* p = root;
   // Create a temp pointer
   Node* temp = nullptr;

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

void BST::preOrder(Node* p)
{
   if (p) {
      std::cout << p->data << "   " << std::flush;
      preOrder(p->left_child);
      preOrder(p->right_child);
   }
}
