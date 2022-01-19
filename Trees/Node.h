#ifndef NODE_H
#define NODE_H

struct Node {
   Node* left_child;
   int data;
   Node* right_child;

   Node() : left_child{ nullptr }, right_child{ nullptr }, data{}{}
   Node(int value) : left_child{ nullptr }, right_child{ nullptr }, data{ value }{}
};

#endif // !NODE_H

