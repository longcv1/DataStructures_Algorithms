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
   int x = A[0];
   A[0] = A[n];
   A[n] = val;
   int i = 0;
   int j = 2 * i + 1;


   while (j <= n - 1) {
      if (A[j] < A[j + 1]) {
         j++;
      }
      if (A[i] < A[j]) {
         int temp = A[i];
         A[i] = A[j];
         A[j] = temp;
         i = j;
         j = 2 * j;
      }
      else break;
   }
   return val;
}

