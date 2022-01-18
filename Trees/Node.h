#pragma once
struct Node {
   Node* left_child;
   int data;
   Node* right_child;

   Node() : left_child{ nullptr }, right_child{ nullptr }, data{}{}
   Node(int value) : left_child{ nullptr }, right_child{ nullptr }, data{ value }{}
};
