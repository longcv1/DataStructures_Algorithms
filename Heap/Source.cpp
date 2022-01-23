#include<iostream>
#include"Heap.h"
#include<vector>

int main()
{
   Heap<int, 7> heap;
   int A[] = { 10,20,30,25,5,40,35 };
   for (int i = 0; i < 7; i++)
   {
      heap.insert(A, i);
   }
   heap.print();

   std::cout << "\nHeap Sort:\n";
   for (int i = 6; i >= 0; i--)
   {
      heap.Delete(i);
   }
   heap.print();
}

