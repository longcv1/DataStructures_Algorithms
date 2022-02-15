#pragma once
namespace BinarySearchTree {
   struct Node {
      int data;
      Node* left_child{ nullptr };
      Node* right_child{ nullptr };
   };
}

namespace Avl_Tree {
   struct Node {
      Node* left_child;
      int data;
      int height;
      Node* right_child;

      Node(int value) : data{ value }, height{ 1 }, left_child{ nullptr }, right_child{ nullptr }{};
   };
}

