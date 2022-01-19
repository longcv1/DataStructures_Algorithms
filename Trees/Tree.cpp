#include "Tree.h"
#include <iostream>
#include <queue>
#include <stack>
#include <memory>

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

int Tree::height(Node* p)
{
   int l = 0, r = 0;
   if (p == nullptr) return 0;

   l = height(p->left_child);
   r = height(p->right_child);
   if (l > r) {
      return l++;
   }
   else {
      return r++;
   }
}

void Tree::levelOrder(Node* p)
{
   std::queue<Node*> Q;
   std::cout << root->data << "   ";
   Q.emplace(root);

   while (!Q.empty()) {
      p = Q.front(); Q.pop();
      if (p->left_child) {
         std::cout << p->left_child->data << "   ";
         Q.emplace(p->left_child);
      }
      if (p->right_child) {
         std::cout << root->right_child->data << "   ";
         Q.emplace(p->right_child);
      }
   }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ! Using while loop and stack to iterate the binary tree by pre-order
// ! [Input] : Node p is at the root node of the tree
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Tree::iterativePreOrder(Node* p)
{
   std::stack<Node*> stk;
   while (!stk.empty() || p != nullptr) {
      if (p != nullptr) {
         std::cout << p->data << "   ";
         stk.emplace(p);
         p = p->left_child;
      }
      else {
         p = stk.top(); stk.pop();
         p = p->right_child;
      }
   }
}

