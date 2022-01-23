#include "Heap.h"
#include<iostream>

template class Heap<int, 7>;

template<typename T, int size>
void Heap<T, size>::insert(T arr[], int n)
{
   A[++rear] = arr[n];
   int temp, i = n;
   temp = A[n];
   while (i >=1 && temp > A[i / 2]) {
      A[i] = A[i / 2];
      i = i / 2;
   }
   A[i] = temp;
}

template<typename T, int size>
void Heap<T, size>::print()
{
   for (int i = 0; i < size; i++) {
      std::cout << A[i] << "   ";
   }
}

template<typename T, int size>
int Heap<T, size>::Delete(int n)
{
   int val = A[0];
   A[0] = A[n];
   A[n] = val;
   Heapify(n);
   return val;
}

template<typename T, int size>
void Heap<T, size>::Heapify(int n)
{
   //Index of last leaf element's parent (n/2)-1
   for (int i = (n / 2) - 1; i >= 0; i--) {
      int j = 2 * i + 1; //=> left child of current i
      while (j < n - 1) {
         //Compare left child and right child of current i
         if (A[j] < A[j + 1]) {
            j++;
         }
         //Compare largest child and its parent of current i
         if (A[i] < A[j]) {
            int temp = A[i]; A[i] = A[j]; A[j] = temp;
            i = j;
            j = 2 * j;
         }
         else break;
      }
   }
}

