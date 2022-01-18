#pragma once
#include<memory>

struct Node {
   std::shared_ptr<Node> prev;
   int data;
   std::shared_ptr<Node> next;

   Node() : data{}, prev{ nullptr }, next{ nullptr } {}
   Node(int value) : data{ value }, prev{ nullptr }, next{ nullptr }{}
};

class DLinkedList
{
private:
   std::shared_ptr<Node> head;

public:
   DLinkedList() {}
   ~DLinkedList(){}
   void init(int* pArr, int size);
   void display();
   void insert(int value, int pos);
   int  remove(int pos);
   bool isListEmpty() const;
   bool isListFull() const;
   int  sizeOfList() const;
   void revertList();
};
