#include<iostream>
#include<memory>
#include"DLinkedList.h"

int main()
{
   auto dl = std::make_unique<DLinkedList>();
   int arr[]{ 1,2,3 };
   dl->init(arr, 3);
   dl->display();
   std::cout<<"\n------------------\n";
   dl->insert(0, 1);
   dl->insert(4, 4);
   dl->insert(5, 5);
   //dl->display();
   //std::cout<< "\n------------------\n";
   dl->revertList();
   dl->display();
   return 0;
}

