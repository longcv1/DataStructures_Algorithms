#include "CircularLinkedList.h"
#include<iostream>


void CircularLinkedList::display()
{
   auto p = head;
   do {
      std::cout << p->data << "   ";
      p = p->next;
   } while (p != head);
}

void CircularLinkedList::insert(int value, unsigned int pos)
{
   if (isListEmpty())
   {
      // Insert at firt position if list is empty
      Node* newNode = new Node(value);
      head = newNode;
      newNode->next = head;
      size++;
      return;
   }

   if (pos < 0 || pos > size) {
      std::cout << "Insert invalid postion!\n";
      return;
   }
   if (pos == 0) {
      //Insert at firt position
      auto newNode = new Node(value);
      auto p = head;
      do {
         p = p->next;
      } while (p->next != head);
      p->next = newNode;
      newNode->next = head;
      head = newNode;
      size++;
   }
   else {
      Node* newNode = new Node(value);
      if (pos == size) {
         // Insert at last position
         auto p = head;
         do {
            p = p->next;
         } while (p->next != head);
         p->next = newNode;
         newNode->next = head;
         size++;
      }
      else {
         // Insert at any position
         auto p = head;
         for (unsigned int i = 0; i < pos; i++) {
            p = p->next;
         }
         newNode->next = p->next;
         p->next = newNode;
         size++;
      }
   }
}

int CircularLinkedList::remove(unsigned int pos)
{
   int value{ -1 };
   if (pos < 0 || pos > getSize()) {
      std::cout << "Delete at invalid position..\n";
      return -1;
   }

   if (pos - 1 == 0) {
      //Delete at first position
      auto p = head; auto q = head;
      do {
         p = p->next;
      } while (p->next != head);
      head = q->next;
      value = q->data;
      delete q;
      p->next = head;
      size--;
   }
   else{
      //Delete at last position
      auto p = head; auto q = p;
      for (unsigned int i = 0; i < pos - 1; i++) {
         q = p;
         p = p->next;
      }
      q->next = p->next;
      value = p->data;
      delete p;
      size--;
   }

   return value;
}

bool CircularLinkedList::isListEmpty() const
{
   if (head == nullptr) return true;
   return false;
}

bool CircularLinkedList::isListFull() const
{
   Node* p = new Node();
   if (p == nullptr) return true;
   return false;
}

int main()
{
   std::cout << "---------Circular Linked List---------\n";
   CircularLinkedList* cll = new CircularLinkedList();
   cll->insert(5, 0);
   cll->insert(10, 1);
   cll->insert(20, 2);
   cll->insert(30, 3);
   cll->insert(1, 0);
   cll->insert(0, 0);
   cll->insert(15, 3);
   std::cout << "\nDisplay List:\n";
   cll->display();

   std::cout << "\nAfter deleting:\n";
   cll->remove(1);
   cll->remove(6);
   cll->remove(3);
   cll->display();
   return 0;
}

