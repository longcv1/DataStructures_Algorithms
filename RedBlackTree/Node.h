#pragma once
#include<string>
constexpr auto RED = 0;
constexpr auto BLACK = 1;

class Node {
public:
   int data;
   bool color;
   Node* left_child;
   Node* right_child;
   Node* parent;
   Node(int value) {
      data = value;
      left_child = right_child = parent = nullptr;
      color = RED;
   }
   Node(Node* parentNode, int data) {
      this->data = data;
      this->parent = parentNode;
      this->left_child = this->right_child = nullptr;
      this->color = RED;
   }
   std::string toString(bool color) {
      if (color == 0) {
         return "R";
      }
      else {
         return "B";
      }
   }

   void setLeftChild(Node* leftChild) {
      this->left_child = leftChild;
   }
   void setRightChild(Node* rightChild) {
      this->right_child = rightChild;
   }
   Node* getParent() {
      return parent;
   }
   bool getColor() {
      return color;
   }
   void setColor(bool color) {
      this->color = color;
   }
};