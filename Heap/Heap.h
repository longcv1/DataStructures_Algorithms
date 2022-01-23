#ifndef HEAP_H
#define HEAP_H

#include<iostream>

template<typename T, int size>
class Heap
{
private:
   T A[20];
   int rear{ -1 };
public:
   Heap(){ this->A[size] = {}; };
   void insert(T arr[], int n);
   void print();
   int Delete(int n);
   void heap_sort();
};

#endif // !HEAP_H


