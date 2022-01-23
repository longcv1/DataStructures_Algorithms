#include<iostream>
#include<memory>
#include"SLinkedList.h"

int main()
{
   auto sl = std::make_unique<SLinkedList<int>>();
   int arr[]{ 1,2,3,4,5 };
   sl->init(arr, 5);
   sl->display();
   std::cout << "\n--------Inserted-------------\n";
   sl->insert(0, 1);
   sl->insert(6, 6);
   sl->display();
   std::cout << "\n--------Deleted-------------\n";
   sl->remove(1);
   sl->remove(5);
   sl->display();

   return 0;
}


