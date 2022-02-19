#include<iostream>
#include"AVL.h"

int main()
{
   AVL avl;
   avl.Insert(12);
   avl.Insert(4);
   avl.Insert(20);
   avl.Insert(1);
   avl.Insert(5);
   avl.Insert(23);
   avl.Insert(19);

   std::cout << "\nAfter inserting nodes:\n";
   avl.Traversal();

   avl.Remove(12);
   std::cout << "\nAfter removing nodes: 12\n";
   avl.Traversal();

   avl.Remove(20);
   std::cout << "\nAfter removing nodes: 20\n";
   avl.Traversal();
   return 0;
}