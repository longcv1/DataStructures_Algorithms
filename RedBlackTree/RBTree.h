#pragma once
#include"Node.h"

class RBTree
{
private:
   Node* root;

protected:
   void R_InOrder(Node* p);
   void R_Insert(Node* p, int key);
public:
   RBTree() :root{ nullptr } {}
   void Insert(int key);
   void in_order() { R_InOrder(root); };
};

