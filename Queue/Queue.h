#include<iostream>

#ifndef QUEUE_H
#define QUEUE_H

template<typename T, int size>
class Queue
{
private:
   int front;
   int rear;
   T Q[size];
public:
   Queue() : front{ -1 }, rear{ -1 }{};
   Queue(int size) : front{ -1 }, rear{ -1 }{}
   ~Queue() = default;
   void enQueue(T value);
   T deQueue();
   bool isEmpty();
   bool isFull();
   void display();
};

template<typename T, int size>
void Queue<T, size>::enQueue(T value)
{
   if (rear == size - 1) {
      std::cout << "Queue is full...\n";
      return;
   }
   Q[++rear] = value;
}

template<typename T, int size>
T Queue<T, size>::deQueue()
{
   if (isEmpty()) {
      std::cout << "Queue is empty...\n";
      return -1;
   }

   return Q[++front];
}

template<typename T, int size>
bool Queue<T, size>::isEmpty()
{
   if (front == rear) return true;
   return false;
}

template<typename T, int size>
inline bool Queue<T, size>::isFull()
{
   if (front == size - 1) return true;
   return false;
}

template<typename T, int size>
void Queue<T, size>::display()
{
   for (int i = front + 1; i < size; i++)
   {
      std::cout << Q[i] << "   ";
   }
}
#endif // !QUEUE_H


