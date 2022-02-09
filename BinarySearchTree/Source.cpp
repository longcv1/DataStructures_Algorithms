#include"BST.h"
#include<iostream>

using namespace BinarySearchTree;

int main()
{
   BST bst;
   bst.init(10);
   bst.Insert(5);
   bst.Insert(20);
   bst.Insert(8);
   bst.Insert(30);
   bst.in_order();
   std::cout << "\nAfter Delete Node:\n";
   bst.Remove(20);
   bst.in_order();
   return 0;
}

