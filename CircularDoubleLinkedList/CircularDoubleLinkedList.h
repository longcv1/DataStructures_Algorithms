#pragma once

struct Node {
   Node* prev;
   int data;
   Node* next;

   Node() : data{}, prev{ nullptr }, next{ nullptr } {}
   Node(int value) : data{ value }, prev{ nullptr }, next{ nullptr }{}
};

class CircularDoubleLinkedList
{
private:
   Node* head;

public:
   CircularDoubleLinkedList() :head{ nullptr } {};
   ~CircularDoubleLinkedList() {}
   void init(int* pArr, int size);
   void display();
   void insert(int value, int pos);
   int  remove(int pos);
   bool isListEmpty() const;
   bool isListFull() const;
   int  sizeOfList() const;
};

