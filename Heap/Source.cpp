#include<iostream>
#include"Heap.h"
#include<vector>

void InsertInplace(int A[], int n) {
   int i = n;
   int temp = A[n];
   while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1 : i / 2]) {
      A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i / 2];
      i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
   }
   A[i] = temp;
}


void createHeap(int A[], int n) {
   for (int i = 0; i < n; i++) {
      InsertInplace(A, i);
   }
}

template <typename T>
void Print(T& vec, int n, char c) {
   std::cout << c << ": [" << std::flush;
   for (int i = 0; i < n; i++) {
      std::cout << vec[i] << std::flush;
      if (i < n - 1) {
         std::cout << ", " << std::flush;
      }
   }
   std::cout << "]" << std::endl;
}

//int main() {
//
//   std::cout << "Create Heap" << std::endl;
//   int b[] = { 0,10,2,3,30,40,35,25,8 };
//   /*Print(b, sizeof(b) / sizeof(b[0]), 'b');*/
//
//   std::cout << "Inplace Insert" << std::endl;
//   createHeap(b, sizeof(b) / sizeof(b[0]));
//   Print(b, sizeof(b) / sizeof(b[0]), 'b');
//
//   Heap<int, 9> heap;
//   std::cout << "Heap:" << std::endl;
//   for (int i = 0; i < 9; i++)
//   {
//      heap.insert(b, i);
//   }
//   heap.print();
//
//   return 0;
//}

int main()
{
   Heap<int, 7> heap;
   int A[] = { 10,20,30,25,5,40,35 };
   for (int i = 0; i < 7; i++)
   {
      heap.insert(A, i);
   }
   heap.print();

   std::cout << "\nAfter delete:\n";
   //for (int i = 6; i >= 0; i--)
   {
      std::cout << heap.Delete(6) << "   ";
      std::cout << "\n------\n";
      heap.print();
      std::cout << "\n"<< heap.Delete(5) << "   ";
      std::cout << "\n------\n";
      heap.print();
   }
   /*std::cout << "\n";
   heap.print();*/
}

