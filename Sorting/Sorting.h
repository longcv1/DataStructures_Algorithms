#ifndef SORTING_H
#define SORTING_H
#include<iostream>

template<typename T>
void Swap(T* x, T* y) {
   T temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

template<typename T, int size>
class Sorting
{
private:
   T A[size];

public:
   void init(int arr[]);
   void display();

   //Sorting techniques
   void buble_sort(const char* name);
   void insertion_sort(const char* name);
   void selection_sort(const char* name);
   //Quick Sort
   int partition_quick_sort_middle(int l, int h);
   void quick_sort_middle(int l, int h);
   int partition_quick_sort_left(int l, int r);
   void quick_sort_left(int l, int r);
   //Merge Sort
   void merge_sort_recursive(int l, int h);
   void merge(int l, int mid, int h);
};

#endif // !SORTING_H

template<typename T, int size>
inline void Sorting<T, size>::init(int arr[])
{
   for (int i = 0; i < size; i++)
   {
      A[i] = arr[i];
   }
}

template<typename T, int size>
inline void Sorting<T, size>::display()
{
   for (int i = 0; i < size; i++) {
      std::cout << A[i] << "   ";
   }
}

template<typename T, int size>
inline void Sorting<T, size>::buble_sort(const char* name)
{
   std::cout << std::endl << "Sorting with" << name << ": " << std::endl;
   for (int i = 0; i < size; i++){
      for (int j = 0; j < size; j++) {
         if (A[i] < A[j]) {
            Swap(&A[i], &A[j]);
         }
      }
   }
}

template<typename T, int size>
inline void Sorting<T, size>::insertion_sort(const char* name)
{
   std::cout << std::endl << "Sorting with" << name << ": " << std::endl;
   for (int i = 1; i < size; i++) {
      int j = i - 1;
      int temp = A[i];
      while (j >= 0 && temp < A[j]) {
         A[j + 1] = A[j];
         j--;
      }
      A[j+1] = temp;
   }
}

template<typename T, int size>
inline void Sorting<T, size>::selection_sort(const char* name)
{
   int j, k;
   for (int i = 0; i < size; i++) {
      for (j = k = i; j < size; j++) {
         if (A[j] < A[k]) {
            k = j;
         }
      }
      Swap(&A[k], &A[i]);
   }
}

template<typename T, int size>
inline int Sorting<T, size>::partition_quick_sort_middle(int l, int r)
{
   int mid = (l + r) / 2;
   Swap(&A[l], &A[mid]);
   int pivot = A[l];
   int i = l + 1; int j = r;
   while (i < j) {
      while (A[i] <= pivot) {
         i++;
      }
      while (A[j] > pivot) {
         j--;
      }
      if (i < j) {
         Swap(&A[i], &A[j]);
         i++;
         j--;
      }
   }
   Swap(&A[l], &A[j]);
   return j;
}


template<typename T, int size>
inline void Sorting<T, size>::quick_sort_middle(int l, int r)
{
   if (l < r) {
      int j = partition_quick_sort_middle(l, r);
      quick_sort_middle(l, j - 1);
      quick_sort_middle(j + 1, r);
   }
}

template<typename T, int size>
inline int Sorting<T, size>::partition_quick_sort_left(int l, int r)
{
   int pivot = A[l];
   int i = l + 1; int j = r;
   while (i < j) {
      while (A[i] <= pivot) {
         i++;
      }
      while (A[j] > pivot) {
         j--;
      }
      if (i < j) {
         Swap(&A[i], &A[j]);
      }
   }

   Swap(&A[l], &A[j]);
   return j;
}

template<typename T, int size>
inline void Sorting<T, size>::quick_sort_left(int l, int r)
{
   if (l < r) {
      int j = partition_quick_sort_left(l, r);
      quick_sort_left(l, j - 1);
      quick_sort_left(j + 1, r);
   }
}

template<typename T, int size>
inline void Sorting<T, size>::merge_sort_recursive(int l, int h)
{
   if (l < h) {
      int mid = l + (h - l) / 2;
      merge_sort_recursive(l, mid);
      merge_sort_recursive(mid + 1, h);
      merge(l, mid, h);
   }
}

template<typename T, int size>
inline void Sorting<T, size>::merge(int l, int mid, int h)
{
   T B[size];
   int i = l; int j = mid + 1; int k = l;
   while (i <= mid && j <= h) {
      if (A[i] < A[j]) {
         B[k++] = A[i++];
      }
      else {
         B[k++] = A[j++];
      }
   }
   while (i <= mid) {
      //Copy remaining elements of first array if have
      B[k++] = A[i++];
   }
   while (j <= h) {
      //Copy remaining elements of second array if have
      B[k++] = A[j++];
   }

   for (int n = l; n <= h; n++) {
      A[n] = B[n];
   }
}
