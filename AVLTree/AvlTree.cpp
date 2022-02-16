#include "AvlTree.h"
#include<iostream>

Avl_Tree::Node* AvlTree::R_Insert(Avl_Tree::Node* p, int key)
{
   Avl_Tree::Node* t = nullptr;

   if (p == nullptr)
   {
      t = new Avl_Tree::Node(key);
      t->height = 1;
      return t;
   }

   if (p!= nullptr && key < p->data) {
      p->left_child = R_Insert(p->left_child, key);
   }
   else if (p != nullptr && key > p->data) {
      p->right_child = R_Insert(p->right_child, key);
   }

   // Update again height of tree
   p->height = NodeHeight(p);

   if (BalanceFactor(p) == 2 && BalanceFactor(p->left_child) == 1) {
      return LL_Rotation(p);
   }
   else if (BalanceFactor(p) == 2 && BalanceFactor(p->left_child) == -1) {
      return LR_Rotation(p);
   }
   else if (BalanceFactor(p) == -2 && BalanceFactor(p->right_child) == -1) {
      return RR_Rotation(p);
   }
   else if (BalanceFactor(p) == -2 && BalanceFactor(p->right_child) == 1) {
      return RL_Rotation(p);
   }
   return p;
}

int AvlTree::NodeHeight(Avl_Tree::Node* p)
{
   // Check height of left sub tree and height of right sub tree
   int hl{}, hr{};
   hl = (p && p->left_child) ? p->left_child->height : 0;
   hr = (p && p->right_child) ? p->right_child->height : 0;
   if (hl > hr) {
      hl++;
      return hl;
   }
   else {
      hr++;
      return hr;
   }
}

int AvlTree::BalanceFactor(Avl_Tree::Node* p)
{
   int height_left{}, height_right{};
   height_left = (p && p->left_child) ? p->left_child->height : 0;
   height_right = (p && p->right_child) ? p->right_child->height : 0;
   return height_left - height_right;
}

Avl_Tree::Node* AvlTree::LL_Rotation(Avl_Tree::Node* p)
{
   Avl_Tree::Node* pl = p->left_child;
   Avl_Tree::Node* plr = pl->right_child;

   pl->right_child = p;
   p->left_child = plr;

   // Update height
   p->height = NodeHeight(p);
   pl->height = NodeHeight(pl);

   // Update root
   if (root = p) {
      root = pl;
   }
   return pl;
}

Avl_Tree::Node* AvlTree::LR_Rotation(Avl_Tree::Node* p)
{
   Avl_Tree::Node* pl = p->left_child;
   Avl_Tree::Node* plr = pl->right_child;

   pl->right_child = plr->left_child;
   p->left_child = plr->right_child;

   plr->left_child = pl;
   plr->right_child = p;

   // Update height
   p->height = NodeHeight(p);
   pl->height = NodeHeight(pl);
   plr->height = NodeHeight(plr);

   // Update root
   if (root = p) {
      root = plr;
   }
   return plr;
}

Avl_Tree::Node* AvlTree::RR_Rotation(Avl_Tree::Node* p)
{
   Avl_Tree::Node* pr = p->right_child;
   Avl_Tree::Node* prl = pr->left_child;

   pr->right_child = p;
   p->right_child = prl;

   // Update height
   p->height = NodeHeight(p);
   pr->height = NodeHeight(pr);

   // Update root
   if (root = p) {
      root = pr;
   }
   return pr;

   return nullptr;
}

Avl_Tree::Node* AvlTree::RL_Rotation(Avl_Tree::Node* p)
{
   Avl_Tree::Node* pr = p->right_child;
   Avl_Tree::Node* prl = pr->left_child;

   pr->left_child = prl->right_child;
   p->right_child = prl->left_child;

   prl->right_child = pr;
   prl->left_child = p;

   // Update height
   p->height = NodeHeight(p);
   pr->height = NodeHeight(pr);
   prl->height = NodeHeight(prl);

   // Update root
   if (root = p) {
      root = prl;
   }
   return prl;
}

void AvlTree::preOrder(Avl_Tree::Node* p)
{
   if (p) {
      std::cout << p->data << "   " << std::flush;
      preOrder(p->left_child);
      preOrder(p->right_child);
   }
}
