#ifndef SORTING_H
#define SORTING_H
#include<iostream>

template<typename T, int size>
class Sorting
{
private:
   T A[size];

public:
   void init(int arr[]);
   void display();
   void buble_sort();
   void insertion_sort(const char* name);
   void selection_sort();
   void quick_sort();
   void merge_sort();
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
inline void Sorting<T, size>::insertion_sort(const char* name)
{
   std::cout << std::endl << name << ": " << std::endl;
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
