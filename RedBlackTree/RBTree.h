#pragma once
#include"Node.h"

class RBTree
{
private:
   Node* root;

protected:
   void R_InOrder(Node* p);
   void R_Insert(int key, Node* node);
   void RightRotation(Node* node);
   void LeftRotation(Node* node);
   bool isRed(Node* node);
   void FixViolation(Node* node);

public:
   RBTree() :root{ nullptr } {}
   void Insert(int key);
   void in_order() { R_InOrder(root); };
};

