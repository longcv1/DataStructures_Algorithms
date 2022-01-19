#include"Tree.h"
#include<iostream>

int main()
{
   Tree bt;
   bt.createTree();

   std::cout << "\n\n";

   std::cout << "\nRecursion Pre-order:\n";
   bt.pre_Order();

   std::cout << "\nRecursion In-order:\n";
   bt.in_Order();

   std::cout << "\nRecursion Post-order:\n";
   bt.post_Order();

   std::cout << "\nLevel-Order:\n";
   bt.level_Order();

   std::cout << "\nIterative Pre-order:\n";
   bt.iterative_pre_order();

   return 0;
}

