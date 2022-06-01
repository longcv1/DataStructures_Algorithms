#include "RBTree.h"
#include<iostream>


/*
   INSERTION:
   1. Neu tree la rong => tao node moi la root node voi color = BLACK
   2. Neu tree khac rong => tao node moi la leaf node voi color = RED
   3. Check conflict:
      3.1: Neu node cha cua new node la BLACK => exit
      3.2: Neu node cha cua new node la RED => check node uncle
           +> uncle la BLACK/null => Rotation & Recolor (parent node & grandparent node)
           +> uncle la RED => Recolor (parent, uncle and grandparent nodes) & recursive check to root node.

   DELETION:
   1. Neu node can xoa la RED va ko co node con => delete it (nothing more to do)
   2. Neu node can xoa la RED va co node con la BLACK => delete it and update lai parent node tro vao node con bi xoa
   3. Neu node can xoa la BLACK => cehck node sibling
     3.1: Neu node la RED => delete node can xoa & rotation
     3.2: Neu node la BLACK => check children of sibling
          +> Neu la BLACK => recolor (sibling = RED and parent = BLACK) & recursive check to root node
          +> Neu la RED => delete node can xoa & rotation

  Exp: 10,20,30,50,40,60,70,80,4,8
*/


void RBTree::R_InOrder(Node* p)
{
   if (p) {
      R_InOrder(p->left_child);
      std::cout << p->data << "   " << std::flush;
      R_InOrder(p->right_child);
   }
}

void RBTree::R_Insert(int key, Node* node)
{
   if (node == nullptr) return;

   if (key < node->data) {
      // Goes to left sub tree
      if (node->left_child != nullptr) {
         R_Insert(key, node->left_child);
      }
      else {
         Node* newNode = new Node(key, node);
         node->left_child = newNode;
         FixViolation(newNode);
      }
   }
   else if (key > node->data) {
      // Goes to right sub tree
      if (node->right_child != nullptr) {
         R_Insert(key, node->right_child);
      }
      else {
         Node* newNode = new Node(key, node);
         node->right_child = newNode;
         FixViolation(newNode);
      }
   }
   else {
      // If key equal to current data node,
      // Nothing to do
      return;
   }
   // Check RB properties violation
}

void RBTree::Insert(int key)
{
   // Insert the first node to root
   if (root == nullptr) {
      root = new Node(key, nullptr);
      FixViolation(root);
   }
   else {
      R_Insert(key, root);
   }
}

void RBTree::RightRotation(Node* node)
{
   Node* tempLeftChild = node->left_child;
   Node* grandChild = tempLeftChild->right_child;

   //Make rotation - new root node will be tempLeftChild
   tempLeftChild->right_child = node;
   node->left_child = grandChild;

   //Update parent node
   if (grandChild != nullptr) {
      grandChild->parent_node = node;
   }

   //Handle parents for the node
   Node* tempParent = node->parent_node;
   node->parent_node = tempLeftChild;
   tempLeftChild->parent_node = tempParent;

   if (node == root) {
      root = tempLeftChild;
   }
}

void RBTree::LeftRotation(Node* node)
{
   Node* tempRightChild = node->right_child;
   Node* grandChild = tempRightChild->left_child;

   //Make rotation - new root node will be tempRightChild
   tempRightChild->left_child = node;
   node->right_child = grandChild;

   //Update parent node
   if (grandChild != nullptr) {
      grandChild->parent_node = node;
   }

   //Handle parents for the node
   Node* tempParent = node->parent_node;
   node->parent_node = tempRightChild;
   tempRightChild->parent_node = tempParent;

   if (node == root) {
      root = tempRightChild;
   }
}

bool RBTree::isRed(Node* node)
{
   if (node == nullptr) {
      return false;
   }
   return node->color == RED;
}

void RBTree::FixViolation(Node* node)
{
   Node* parent = nullptr;
   Node* grand = nullptr;

   // Checks the violation up to the root node
   while (node!=nullptr && node != root && isRed(node) && isRed(node->parent_node)) {
      parent = node->parent_node;
      grand = parent->parent_node;
      if (parent == nullptr || grand == nullptr) {
         break;
      }
      // Parent is a left child of it's parent
      if (parent == grand->left_child) {
         //   (G-b)                           (G-r)
         //  /     \        Recolor          /     \
         //(P-r)   (U-r)     ==>          (P-b)    (U-b)
         //   \                               \
         //  (X-r)                           (X-r)
         Node* uncle = grand->right_child;
         if ((uncle != nullptr) && isRed(uncle)){
            // Rocoloring G, P and U
            grand->color = RED;
            parent->color = BLACK;
            uncle->color = BLACK;
            node = grand;
         }
         else {
            //   (G-b)                           (G-b)                         (P-r)                      (P-b)
            //  /     \       Left Rotate       /     \        Right Rotate   /     \         Recolor    /     \
            //(P-r)   (U-b)     ==>          (P-r)    (U-b)        ==>     (X-r)    (G-b)       ==>   (X-r)    (G-r)
            //   \                            /                                       \                          \
            //  (X-r)                      (X-r)                                      (U-b)                     (U-b)
            if (node == parent->right_child) {
               LeftRotation(parent);
               // Update the reference we keep going up to root node
               node = parent;
               parent = grand;
            }
            RightRotation(grand);
            // Swap parent's color and grand's color
            bool tempColor = parent->color;
            parent->color = grand->color;
            grand->color = tempColor;
            // Update the reference we keep going up to root node
            node = parent;
         }
      }
      else if(parent == grand->right_child) {
         // Parent is a right child of it's parent
         //   (G-b)                           (G-r)
         //  /     \       Recolor           /     \
         //(U-r)   (P-r)     ==>          (U-b)    (P-b)
         //         /                               /
         //      (X-r)                           (X-r)
         Node* uncle = grand->left_child;
         if ((uncle != nullptr) && isRed(uncle)) {
            // Rocoloring G, P and U
            grand->color = RED;
            parent->color = BLACK;
            uncle->color = BLACK;
            node = grand;
         }
         else {
         //   (G-b)                           (G-b)                            (X-r)                        (X-b)
         //  /     \       Rigt Rotate       /     \          Left Rotate     /     \         Recolor      /     \
         //(U-b)   (P-r)     ==>          (U-b)    (X-r)         ==>       (G-b)    (P-r)      ==>      (G-r)    (P-r)
         //         /                                 \                     /                             /
         //      (X-r)                                (P-r)               (U-b)                         (U-b)
            if (node == parent->left_child) {
               RightRotation(parent);
               // Update the reference we keep going up to root node
               node = parent;
               parent = grand;
            }
            LeftRotation(grand);
            // Swap parent's color and grand's color
            bool tempColor = parent->color;
            parent->color = grand->color;
            grand->color = tempColor;
            // Update the reference we keep going up to root node
            node = parent;
         }
      }

      if (isRed(root)) {
         root->color = BLACK;
      }
   }
}
