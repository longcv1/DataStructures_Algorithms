#include<iostream>
#include"RBTree.h"

int main()
{
   std::cout << "Red Black Tree\n";
   RBTree rb;

   rb.Insert(12);
   rb.Insert(4);
   rb.Insert(20);
   rb.Insert(1);
   rb.Insert(5);
   rb.Insert(23);
   rb.Insert(19);

   rb.in_order();
   return 0;
}