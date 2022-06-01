#include"BST.h"
#include<iostream>

using namespace BinarySearchTree;

int main()
{
   BST bst;
   bst.init(20);
   bst.Insert(10);
   bst.Insert(30);
   bst.Insert(8);
   bst.Insert(12);
   //bst.Insert(25);
   bst.Insert(38);
   bst.Insert(5);
   bst.Insert(9);
   bst.Insert(11);
   bst.Insert(32);
   bst.Insert(40);
   bst.in_order();
   std::cout << "\nAfter Delete Node:\n";
   bst.Remove(20);
   bst.in_order();
   return 0;
}

