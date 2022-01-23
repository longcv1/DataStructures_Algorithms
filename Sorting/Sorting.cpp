#include "Sorting.h"
#include<iostream>

int main()
{
   Sorting<int, 10> sort;
   int Array[10] = { 8,9,0,5,1,2,6,3,4,7 };
   sort.init(Array);
   sort.display();

   sort.insertion_sort("INSERTION SORT");
   sort.display();
   return 0;
}

