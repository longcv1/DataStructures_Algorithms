
#ifndef TREE_H
#define TREE_H

#include"Node.h";
#include<memory>

class Tree
{
    Node* root;

public:
   Tree() = default;
   ~Tree() = default;

   void createTree();
   void pre_Order() { preOrder(root); }
   void preOrder(Node*);
   void in_Order() { inOrder(root); }
   void inOrder(Node*);
   void post_Order() { postOrder(root); }
   void postOrder(Node*);
   int height(Node*);
   void level_Order() { levelOrder(root); };
   void levelOrder(Node*);
};


#endif // !TREE_H


