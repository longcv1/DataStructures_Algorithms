#pragma once
class Stack
{
private:
   int size;
   int top;
   int* s;

public:
   Stack() :s{ nullptr }, size{ 100 }, top{ -1 } {};
   bool isEmpty() const;
   bool isFull() const;
   void push(int value);
   int pop();
   int peak();
   void display();
   void init();
};

