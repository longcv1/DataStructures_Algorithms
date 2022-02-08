#include"BST.h"
#include<iostream>

using namespace BinarySearchTree;

int main()
{
   BST bst;
   bst.init(2);
   bst.Insert(1);
   bst.Insert(3);
   bst.pre_order();
   return 0;
}

