#pragma once
#include"Node.h"

class Tree {
public:
   virtual void Insert(int key) = 0;
   virtual void Remove(int key) = 0;
   virtual void Traversal() = 0;
};

class AVL : public Tree {
private:
   Node* root;

protected:
   void R_Insert(int key, Node* node);
   void R_InOrder(Node* node);
   void R_Remove(int key, Node* node);
   Node* getPredecessor(Node* node);
   int Height(Node* node);
   void updateHeight(Node* node);
   int BalanceFactor(Node* node);
   void RightRotation(Node* node);

public:
   virtual void Insert(int key)override;
   virtual void Remove(int key)override;
   virtual void Traversal()override;
};

