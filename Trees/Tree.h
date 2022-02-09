
#ifndef TREE_H
#define TREE_H

#include"Node.h";
#include<memory>

class Tree
{
private:
    Node* root;
private:
   void preOrder(Node*);
   void inOrder(Node*);
   void postOrder(Node*);
   void levelOrder(Node*);
   void iterativePreOrder(Node*);

public:
   Tree() = default;
   ~Tree() = default;

   int  height(Node*);
   void createTree();
   void pre_Order() { preOrder(root); }
   void in_Order() { inOrder(root); }
   void post_Order() { postOrder(root); }
   void level_Order() { levelOrder(root); };
   void iterative_pre_order() { iterativePreOrder(root); };
};


#endif // !TREE_H


