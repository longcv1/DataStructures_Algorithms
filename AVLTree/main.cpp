#include<iostream>
#include"AvlTree.h"

int main()
{
   AvlTree avl;
   avl.Insert(12);
   avl.Insert(4);
   avl.Insert(20);
   avl.Insert(1);
   avl.Insert(5);
   avl.Insert(23);
   avl.Insert(19);
   avl.pre_order();

   avl.Remove(12);
   std::cout << "\nAfter removing nodes: 12\n";
   avl.pre_order();

   avl.Remove(20);
   std::cout << "\nAfter removing nodes: 20\n";
   avl.pre_order();
   return 0;
}