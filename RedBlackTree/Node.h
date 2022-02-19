#pragma once
#include<string>
constexpr auto RED = 0;
constexpr auto BLACK = 1;

struct Node {
   int data;
   bool color;
   Node* left_child;
   Node* right_child;
   Node* parent_node;
   Node(int value) {
      data = value;
      left_child = right_child = parent_node = nullptr;
      color = RED;
   }
   Node(int data, Node* parentNode) {
      this->data = data;
      this->parent_node = parentNode;
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

   //void setLeftChild(Node* leftChild) {
   //   this->left_child = leftChild;
   //}
   //void setRightChild(Node* rightChild) {
   //   this->right_child = rightChild;
   //}
   //Node* getParent() {
   //   return parent;
   //}
   //bool getColor() {
   //   return color;
   //}
   //void setColor(bool color) {
   //   this->color = color;
   //}
};