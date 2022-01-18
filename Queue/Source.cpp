#include<iostream>
#include"Queue.h"

int main()
{
   Queue<int, 5> q;
   q.enQueue(1);
   q.enQueue(2);
   q.enQueue(3);
   q.enQueue(4);
   q.enQueue(5);

   q.display();
   std::cout << "Get Value: " << q.deQueue() << std::endl;
   std::cout << "\n After dequeue:\n";
   q.display();
   return 0;
}
