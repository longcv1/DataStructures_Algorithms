#include "DLinkedList.h"
#include<iostream>
#include<memory>

/*
** Initialization doubled linked list by an array
*/
void DLinkedList::init(int* pArr, int size)
{
   //Init first node of array
   head = std::make_shared<Node>();
   head->data = pArr[0];

   //Transform array to double linked list
   auto tail = head;
   for (int i = 1; i < size; i++)
   {
      auto p = std::make_shared<Node>(pArr[i]);
      tail->next = p;
      p->prev = tail;
      tail = p;
   }
}

/*
********************************************************************************
** Display a doubled linked list
********************************************************************************
*/
void DLinkedList::display()
{
   auto p = head;
   while (p) {
      std::cout << p->data << "<->";
      p = p->next;
   }
}

/*
********************************************************************************
** Inserting a node in doubled linked list
********************************************************************************
*/
void DLinkedList::insert(int value, int pos)
{
   if (isListFull()) {
      std::cout << "List FULL...\n";
      return;
   }
   if (pos < 0 || pos > sizeOfList()) {
      std::cout << "Inserting - invalid postion...\n";
      return;
   }
   if (pos - 1 == 0) {
      //Inserting at first position
      auto newNode = std::make_shared<Node>(value);
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
   }
   else {
      //Inserting at any valid position
      auto p = head;
      for (int i = 0; i < pos - 1; i++) {
         p = p->next;
      }
      auto newNode = std::make_shared<Node>(value);
      newNode->next = p->next;
      newNode->prev = p;
      if (p->next) {
         p->next->prev = newNode;
      }
      p->next = newNode;
   }
}

/*
********************************************************************************
** Removing a node in doubled linked list
********************************************************************************
*/
int DLinkedList::remove(int pos)
{
   int value = INT_MIN;
   if (isListEmpty()) {
      std::cout << "Removing failed - List is empty...\n";
      return value;
   }
   if (pos < 0 || pos > sizeOfList())
   {
      std::cout << "Removing at invalid position....\n";
      return value;
   }

   if (pos - 1 == 0) {
      //Removing at first position
      auto p = head;
      head = head->next;
      value = p->data;
      p.reset();
      if (head) {
         head->prev = nullptr;
      }
   }
   else {
      //Removing at any valid position
      auto p = head;
      for (int i = 0; i < pos - 1; i++) {
         p = p->next;
      }
      p->prev->next = p->next;
      if (p->next) {
         p->next->prev = p->prev;
      }
      value = p->data;
      p.reset();
   }
   return value;
}

bool DLinkedList::isListEmpty() const
{
   if (head == nullptr) {
      return true;
   }
   return false;
}

bool DLinkedList::isListFull() const
{
   auto p = std::make_shared<Node>();
   if (p == nullptr) {
      return true;
   }
   return false;
}

int DLinkedList::sizeOfList() const
{
   auto p = head;
   int size{};
   while (p) {
      p = p->next;
      size++;
   }
   return size;
}

void DLinkedList::revertList()
{
   auto p = head;
   auto temp = std::make_shared<Node>();
   while (p) {
      temp = p->next;
      p->next = p->prev;
      p->prev = temp;
      p = p->prev;
      if (p!= nullptr && p->next == nullptr) {
         head = p;
      }
   }
}
