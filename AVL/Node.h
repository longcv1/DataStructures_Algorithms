#pragma once

struct Node {
   int data;
   Node* left_child;
   Node* right_child;
   //When remove node
   Node* parent_node;
   int height;
   Node(int value, Node* parentNode) {
      this->data = value;
      this->left_child = this->right_child = nullptr;
      this->parent_node = parentNode;
      this->height = 0;
   }
};