#ifndef  _RBTREEH_
#define  _RBTREEH_

#define NULL    0

typedef int rbKeyT;

enum rbColorT
{
    RED=0,
    BLACK=1
};

struct RBtree 
{
    RBtree *left,*right,*parent;
    rbKeyT key;
    rbColorT color;
};

RBtree* rbNewNode(rbKeyT key);

RBtree* search(RBtree* root, rbKeyT key);

RBtree* rotateLeft(RBtree* root, RBtree* x);
RBtree* rotateRight(RBtree* root, RBtree* y);

RBtree* insert(RBtree* root, rbKeyT key);
RBtree* insertFixup(RBtree* root, RBtree* x);

RBtree* successor(RBtree* x);
RBtree* minimum(RBtree* x);

int height(RBtree* root);

void inorderTreeWalk(RBtree* root);
void preorderTreeWalk(RBtree* root);
void postorderTreeWalk(RBtree* root);

RBtree* deleteByKey (RBtree* root,rbKeyT key);
RBtree* deleteFixup(RBtree* root,RBtree* x,RBtree* parent);

#endif
