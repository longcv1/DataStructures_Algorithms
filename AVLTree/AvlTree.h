#pragma once
#include "../Application/Node.h"

class AvlTree
{
private:
   Avl_Tree::Node* root;
   Avl_Tree::Node* R_Insert(Avl_Tree::Node* p, int key);
   int NodeHeight(Avl_Tree::Node* p);
   int BalanceFactor(Avl_Tree::Node* p);
   Avl_Tree::Node* LL_Rotation(Avl_Tree::Node* p);
   Avl_Tree::Node* LR_Rotation(Avl_Tree::Node* p);
   Avl_Tree::Node* RR_Rotation(Avl_Tree::Node* p);
   Avl_Tree::Node* RL_Rotation(Avl_Tree::Node* p);
   void preOrder(Avl_Tree::Node* p);
public:
   AvlTree() :root{ nullptr } {}
   void Insert(int key) {
      root = R_Insert(root, key);
   };
   void pre_order() { preOrder(root); };
};

