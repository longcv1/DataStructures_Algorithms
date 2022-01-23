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
   return 0;
}

