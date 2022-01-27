#include "Sorting.h"
#include<iostream>

int main()
{
   using namespace std;
   int Array[] = { 10, 30, 80, 90, 40, 50, 70, 20 };
   const int size = sizeof(Array) / sizeof(Array[0]);

   Sorting<int, size> sort;
   sort.init(Array);
   cout << "List before sorting:\n";
   sort.display();

   cout << "\n\nQuick Sort:\n";
   sort.quick_sort_left(0, size - 1);
   sort.display();

   return 0;
}

