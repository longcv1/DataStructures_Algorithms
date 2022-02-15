#include<iostream>
#include"AvlTree.h"

int main()
{
   AvlTree *avl = new AvlTree();
   avl->Insert(10);
   avl->Insert(5);
   avl->Insert(2);

   avl->pre_order();
   return 0;
}