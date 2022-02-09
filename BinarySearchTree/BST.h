#pragma once
#include "../Application/Node.h"

class BST
{
private:
   BinarySearchTree::Node* root;
private:
   // Recursive traveral BST
   void preOrder(BinarySearchTree::Node* p);
   void inOrder(BinarySearchTree::Node* p);
   void postOrder(BinarySearchTree::Node* p);

private:
   // Helper functions
   BinarySearchTree::Node* R_Search(BinarySearchTree::Node* p, int key);
   int Height(BinarySearchTree::Node* p);
   BinarySearchTree::Node* InPrecessor(BinarySearchTree::Node* p);
   BinarySearchTree::Node* InSuccessor(BinarySearchTree::Node* p);
   BinarySearchTree::Node* Delete(BinarySearchTree::Node* p, int key);

public:
   void init(int key);
   void Insert(int key);
   void Remove(int key) { Delete(root, key); };

public:
   // Search an value in BST
   void Recursive_Search(int key) { R_Search(this->root, key); };
   BinarySearchTree::Node* Search(int key);

public:
   // Display BST
   void pre_order() { preOrder(root); }
   void in_order() { inOrder(root); };
   void post_order() { postOrder(root); };
};

