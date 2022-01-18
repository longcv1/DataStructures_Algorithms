//#include"../Queue/Queue.h"
#include "Tree.h"
#include <iostream>
#include <queue>
#include<memory>

void Tree::createTree()
{
   Node* p; int value;
   std::queue<Node*> q;

   std::cout << "Enter root value: "; std::cin >> value;

   root = new Node(value);

   //Push root node into queue.
   q.emplace(root);

   while (!q.empty()) {

      // Get first one and pop-out of queue.
      p = q.front();
      q.pop();

      std::cout << "\t-> Input left child value of " << p->data << " : " << std::flush; std::cin >> value;
      if (value != -1) {
         Node* newNode = new Node(value);
         p->left_child = newNode;
         q.emplace(newNode);
      }

      std::cout << "\t-> Input right child value of " << p->data << " : " << std::flush; std::cin >> value;
      if (value != -1) {
         Node* newNode = new Node(value);
         p->right_child = newNode;
         q.emplace(newNode);
      }
   }
}

void Tree::preOrder(Node* root)
{
   if (root) {
      std::cout << root->data << "   " << std::flush;
      preOrder(root->left_child);
      preOrder(root->right_child);
   }
}

void Tree::inOrder(Node* root)
{
   if (root) {
      inOrder(root->left_child);
      std::cout << root->data << "   ";
      inOrder(root->right_child);
   }
}

void Tree::postOrder(Node* root)
{
   if (root) {
      postOrder(root->left_child);
      postOrder(root->right_child);
      std::cout << root->data << "   ";
   }
}
