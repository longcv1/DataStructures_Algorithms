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
   void quick_sort(const char* name);
   void merge_sort(const char* name);
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
inline void Sorting<T, size>::quick_sort(const char* name)
{
}
