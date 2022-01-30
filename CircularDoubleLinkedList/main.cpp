#include<iostream>
#include"CircularDoubleLinkedList.h"

int main()
{
   using namespace std;
   CircularDoubleLinkedList cl;
   int A[] = { 1,2,3 };
   //cl.init(A, 3);
   cl.insert(7, 0);
   cl.insert(6, 1);
   cl.insert(5, 1);
   cl.insert(4, 1);
   cl.insert(0, 4);
   cl.display();
   cout << "\nSize of list: " << cl.sizeOfList() << endl;

   cout << "\nAfter deleting: " << cl.remove(6) << endl;
   cl.display();
   cout << "\nSize of list: " << cl.sizeOfList() << endl;
}
