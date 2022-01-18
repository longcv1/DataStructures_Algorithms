#include"Tree.h"
#include<iostream>

int main()
{
   Tree bt;
   bt.createTree();

   std::cout << "\n\n";

   /*std::cout << "\nPre-order:\n";
   bt.pre_Order();

   std::cout << "\nIn-order:\n";
   bt.in_Order();

   std::cout << "\nPost-order:\n";
   bt.post_Order();*/

   std::cout << "\nPre-Order:\n";
   bt.level_Order();

   return 0;
}

