#include "Stack.h"
#include<iostream>

constexpr auto NOT_FOUND = -100;

bool Stack::isEmpty() const
{
   if (top == -1) {
      return true;
   }
   return false;
}

bool Stack::isFull() const
{
   if (top == size) {
      return true;
   }
   return false;
}

void Stack::push(int value)
{
   if (isFull()) {
      return;
   }
   top++;
   s[top] = value;
}

int Stack::pop()
{
   if (isEmpty()) {
      return NOT_FOUND;
   }
   int x = s[top];
   top--;
   return x;
}

void Stack::display()
{
   for (int i = 0; i <= top; i++) {
      std::cout << s[i] << "   ";
   }
}

void Stack::init()
{
   s = new int[size];
}
