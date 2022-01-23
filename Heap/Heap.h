#ifndef HEAP_H
#define HEAP_H

#include<iostream>

template<typename T, int size>
class Heap
{
private:
   T A[size];
   int rear;
public:
   Heap() :rear{ -1 } { /*this->A[size] = {};*/};
   void insert(T arr[], int n);
   void print();
   int Delete(int n);
   void Heapify(int n);
};

#endif // !HEAP_H


