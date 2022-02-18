#include <iostream>
#include"BST.h"

int main()
{
   BST bst;
   bst.Insert(12);
   bst.Insert(4);
   bst.Insert(20);
   bst.Insert(1);
   bst.Insert(8);
   bst.Insert(16);
   bst.Insert(27);
   bst.Traversal();

   std::cout << "\nBST after remove:\n";
   bst.Remove(16);
   //bst.Remove(20);
   bst.Traversal();

//   std::cout << "\nNode Max: " << bst.getMax()->data;
   return 0;
}

