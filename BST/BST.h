#pragma once
#include"Node.h"

class Tree {
public:
   virtual void Insert(int key) = 0;
   virtual void Remove(int key) = 0;
   virtual void Traversal() = 0;
   virtual Node* getMin() = 0;
   virtual Node* getMax() = 0;
};

class BST : public Tree {
private:
   Node* root;

protected:
   void R_Insert(int key, Node* node);
   void R_InOrder(Node* node);
   Node* R_GetMax(Node* node);
   Node* R_GetMin(Node* node);
   void R_Remove(int key, Node* node);
   Node* getPredecessor(Node* node);

public:
   virtual void Insert(int key)override;
   virtual void Remove(int key)override;
   virtual void Traversal()override;
   virtual Node* getMin()override;
   virtual Node* getMax()override;
};

