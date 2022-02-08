#pragma once
#include "../Application/Node.h"

class BST
{
private:
   BinarySearchTree::Node* root;
   void preOrder(BinarySearchTree::Node*);
private:

public:
   void init(int key);
   BinarySearchTree::Node* R_Search(BinarySearchTree::Node* p, int key);
   BinarySearchTree::Node* Search(BinarySearchTree::Node* p, int key);
   void Insert(/*BinarySearchTree::Node* p, */int key);
   BinarySearchTree::Node* Delete(BinarySearchTree::Node* p, int key);
   void pre_order() { preOrder(root); }
};

