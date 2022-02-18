#include "RBTree.h"
#include<iostream>

void RBTree::R_InOrder(Node* p)
{
   if (p) {
      R_InOrder(p->left_child);
      std::cout << p->data << "   " << std::flush;
      R_InOrder(p->right_child);
   }
}

void RBTree::R_Insert(Node* p, int key)
{
   if (key < p->data) {
      if (p->left_child) {
         R_Insert(p->left_child, key);
      }
      else {
         p->setLeftChild(new Node(p, key));
      }
   }
   else if (key > p->data) {
      if (p->right_child) {
         R_Insert(p->right_child, key);
      }
      else {
         p->setRightChild(new Node(p, key));
      }
   }

}

void RBTree::Insert(int key)
{
   // Insert the first node to root
   if (root == nullptr) {
      root = new Node(nullptr, key);
   }
   else {
      R_Insert(root, key);
   }
}
