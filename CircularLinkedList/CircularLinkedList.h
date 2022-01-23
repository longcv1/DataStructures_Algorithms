#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

struct Node {
   int data;
   Node* next;
   Node() = default;
   Node(int value) :data{ value }, next{ nullptr }{};
};

class CircularLinkedList
{
private:
   Node* head;
   unsigned int size;
public:
   CircularLinkedList() :size{0}, head{ nullptr } {};
   void display();
   void insert(int value, unsigned int pos);
   int remove(unsigned int pos);
   bool isListEmpty() const;
   bool isListFull() const;
   unsigned int getSize() const { return size; }
};

#endif // !CIRCULARLINKEDLIST_H


