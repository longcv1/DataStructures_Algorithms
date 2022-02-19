#include "AvlTree.h"
#include<iostream>
#include<algorithm>

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

int AvlTree::Height(Avl_Tree::Node* p)
{
   if (p == nullptr) {
      return 0;
   }
   return p->height;
}

int AvlTree::NodeHeight(Avl_Tree::Node* p)
{
   int height{};
   if (p) {
      height = std::max(Height(p->left_child), Height(p->right_child)) + 1;
   }
   return height;
}

int AvlTree::BalanceFactor(Avl_Tree::Node* p)
{
   if (p == nullptr) {
      return 0;
   }
   int balance = Height(p->left_child) - Height(p->right_child);
   return balance;
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
      preOrder(p->left_child);
      std::cout << p->data << "   " << std::flush;
      preOrder(p->right_child);
   }
}

Avl_Tree::Node* AvlTree::R_Remove(Avl_Tree::Node* p, int key)
{
   if(p==nullptr) return nullptr;

   if (p->left_child == nullptr && p->right_child == nullptr) {
      if (p == root) {
         root = nullptr;
      }
      delete p;
      return nullptr;
   }

   if (key < p->data) {
      p->left_child = R_Remove(p->left_child, key);
   }
   else if (key > p->data) {
      p->right_child = R_Remove(p->right_child, key);
   }
   else {
      if (NodeHeight(p->left_child) > NodeHeight(p->right_child)) {
         auto q = getPredecessor(p->left_child);
         p->data = q->data;
         p->left_child = R_Remove(p->left_child, q->data);
      }
      else {
         auto q = getSuccessor(p->right_child);
         p->data = q->data;
         p->right_child = R_Remove(p->right_child, q->data);
      }
   }

   p->height = NodeHeight(p);

   // Balance Factor and Rotation
   if (BalanceFactor(p) == 2 && BalanceFactor(p->left_child) == 1) {  // L1 Rotation
      return LL_Rotation(p);
   }
   else if (BalanceFactor(p) == 2 && BalanceFactor(p->left_child) == -1) {  // L-1 Rotation
      return LR_Rotation(p);
   }
   else if (BalanceFactor(p) == -2 && BalanceFactor(p->right_child) == -1) {  // R-1 Rotation
      return RR_Rotation(p);
   }
   else if (BalanceFactor(p) == -2 && BalanceFactor(p->right_child) == 1) {  // R1 Rotation
      return RL_Rotation(p);
   }
   else if (BalanceFactor(p) == 2 && BalanceFactor(p->left_child) == 0) {  // L0 Rotation
      return LL_Rotation(p);
   }
   else if (BalanceFactor(p) == -2 && BalanceFactor(p->right_child) == 0) {  // R0 Rotation
      return RR_Rotation(p);
   }

   return p;
}

Avl_Tree::Node* AvlTree::getPredecessor(Avl_Tree::Node* p)
{
   while (p && p->right_child != nullptr) {
      p = p->right_child;
   }
   return p;
}

Avl_Tree::Node* AvlTree::getSuccessor(Avl_Tree::Node* p)
{
   while (p && p->left_child != nullptr) {
      p = p->left_child;
   }
   return p;
}
