#include "CircularDoubleLinkedList.h"
#include<iostream>

/*
********************************************************************************
** Checks if list is empty or not
********************************************************************************
*/
bool CircularDoubleLinkedList::isListEmpty() const
{
   if (head == nullptr) {
      return true;
   }
   return false;
}

/*
********************************************************************************
** Checks if list is full or not
********************************************************************************
*/
bool CircularDoubleLinkedList::isListFull() const
{
   Node* p = new Node();
   if (p == nullptr) {
      return true;
   }
   return false;
}

/*
********************************************************************************
** Size of the list
********************************************************************************
*/
int CircularDoubleLinkedList::sizeOfList() const
{
   if (isListEmpty()) return 0;
   auto p = head;
   int size{0};
   do{
      p = p->next;
      size++;
   }while (p != head);
   return size;
}

/*
********************************************************************************
** Initialization circular doubled linked list by an array
********************************************************************************
*/
void CircularDoubleLinkedList::init(int* pArr, int size)
{
   //Init first node of array
   head = new Node();
   head->data = pArr[0];

   //Transform array to double linked list
   auto tail = head;
   for (int i = 1; i < size; i++)
   {
      Node* p = new Node(pArr[i]);
      tail->next = p;
      p->prev = tail;
      tail = p;
      tail->next = head;
      head->prev = tail;
   }
}

/*
********************************************************************************
** Display circular doubled linked list
********************************************************************************
*/
void CircularDoubleLinkedList::display()
{
   auto p = head;
   do{
      std::cout << p->data << "<->";
      p = p->next;
   } while (p != head);
}

/*
********************************************************************************
** Inserting a node in circular doubled linked list
********************************************************************************
*/
void CircularDoubleLinkedList::insert(int value, int pos)
{
   if (isListFull()) {
      std::cout << "List FULL...\n";
      return;
   }

   if (isListEmpty()) {
      Node* p = new Node(value);
      p->next = p->prev = p;
      head = p;
      return;
   }

   if (pos < 0 || pos > sizeOfList()) {
      std::cout << "Inserting - invalid postion...\n";
      return;
   }


   //Inserting at first position
   if (pos - 1 == 0) {
      Node* newNode = new Node(value);
      //Pointer points to last node
      Node* last = head->prev;

      //Setting previous and next pointers of new node.
      newNode->next = head;
      newNode->prev = last;

      //Update next and previous pointers of head.
      head->prev = newNode;
      last->next = newNode;
      head = newNode;
   }
   else {
      //Inserting at any valid position
      auto p = head;
      for (int i = 0; i < pos - 1; i++) {
         p = p->next;
      }
      Node* newNode = new Node(value);
      newNode->next = p->next;
      newNode->prev = p;
      p->next->prev = newNode;
      p->next = newNode;
   }
}


/*
********************************************************************************
** Deleteing a node in circular doubled linked list
********************************************************************************
*/
int CircularDoubleLinkedList::remove(int pos)
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
      Node* last = head->prev;
      auto p = head;
      head = head->next;
      last->next = head;
      head->prev = last;
      value = p->data;
      delete p;
      p = nullptr;
   }
   else {
      //Removing at any valid position
      auto p = head;
      for (int i = 0; i < pos - 1; i++) {
         p = p->next;
      }
      p->prev->next = p->next;
      p->next->prev = p->prev;
      value = p->data;
      delete p;
   }
   return value;
}
