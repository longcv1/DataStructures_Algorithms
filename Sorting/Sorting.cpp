#include "Sorting.h"
#include<iostream>

int main()
{
   Sorting<int, 20> sort;
   int Array[20] = { 20,14,8,9,0,5,1,2,6,3,50,30,4,7,15,12,25,11,13,10 };
   sort.init(Array);
   //sort.display();

   sort.buble_sort("Bubble Sort");
   sort.display();

   return 0;
}

