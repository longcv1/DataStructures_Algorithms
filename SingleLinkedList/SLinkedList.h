#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include<memory>
#include<iostream>

template<typename T>
struct Node
{
   T data;
   std::shared_ptr<Node> next;

   Node() : data{} {}
   Node(T value) : data{value} {}
};


template<typename T>
class SLinkedList
{
private:
   std::shared_ptr<Node<T>> head;
public:
   SLinkedList(){}
   ~SLinkedList() {}
   void init(T *pArr, unsigned int size);
   void display();
   void insert(T value, unsigned int pos);
   T remove(unsigned int pos);
   bool isListEmpty() const;
   bool isListFull() const;
   unsigned int sizeOfList() const;
};
#endif // !SINGLELINKEDLIST_H

template<typename T>
inline void SLinkedList<T>::init(T* pArr, unsigned int size)
{
   head = std::make_shared<Node<T>>();
   auto tail = head;

   head->data = pArr[0];
   head->next = nullptr;

   for (unsigned int i = 1; i < size; i++)
   {
      auto p = std::make_shared<Node<T>>(pArr[i]);
      tail->next = p;
      tail = p;
   }
}

template<typename T>
inline void SLinkedList<T>::display()
{
   auto p = head;
   while (p != nullptr)
   {
      std::cout << p->data << "->";
      p = p->next;
   }
}

template<typename T>
inline void SLinkedList<T>::insert(T value, unsigned int pos)
{
   if (isListFull()) {
      std::cout << "Inserting a node is failed! List is full! \n";
      return;
   }
   if (pos < 0 || pos > sizeOfList()) {
      std::cout << "Inserting at an invalid postion!\n";
      return;
   }
   if (pos - 1 == 0) {
      //Inserting at first postion
      auto newNode = std::make_shared<Node<T>>(value);
      newNode->next = head;
      head = newNode;
   }
   else {
      //Inserting at any valid position
      auto p = head;
      for (unsigned int i = 0; i < pos - 1; i++) {
         p = p->next;
      }
      auto newNode = std::make_shared<Node<T>>(value);
      newNode->next = p->next;
      p->next = newNode;
   }
}

template<typename T>
inline T SLinkedList<T>::remove(unsigned int pos)
{
   T data{};
   if (isListEmpty()) {
      std::cout << "List is empty";
      return data;
   }
   if (pos < 0 || pos > sizeOfList()) {
      std::cout << "Removing at invalid postion!\n";
      return data;
   }
   if (pos - 1 == 0)
   {
      //Removing at first position
      auto temp = head;
      head = temp->next;
      data = temp->data;
      temp.reset();
      return data;
   }
   else {
      //Removing at any valid postion
      auto p = head;
      auto q = p;
      for (unsigned int i = 0; i < pos - 1; i++) {
         q = p;
         p = p->next;
      }
      q->next = p->next;
      data = p->data;
      p.reset();
      return data;
   }
}

template<typename T>
inline bool SLinkedList<T>::isListEmpty() const
{
   if (head == nullptr){
      return true;
   }
   return false;
}

template<typename T>
inline bool SLinkedList<T>::isListFull() const
{
   auto p = std::make_shared<Node<T>>();
   if (p == nullptr) {
      return true;
   }
   return false;
}

template<typename T>
inline unsigned int SLinkedList<T>::sizeOfList() const
{
   unsigned int size{};
   auto p = std::make_shared<Node<T>>();
   p = head;
   while (p) {
      p = p->next;
      size++;
   }
   return size;
}
