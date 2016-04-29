#ifndef  RBTREE_HPP
#define  RBTREE_HPP

#include <fstream>
#include <string>
#include <cstdio>

using std::string;

//#define NULL    0

enum rbColorT
{
    RED=0,
    BLACK=1
};

struct RBtree 
{
    RBtree *left,*right,*parent;
    int key;
    rbColorT color;
};

RBtree* newNode(int key);

RBtree* search(RBtree* root, int key);
bool boolSearch(RBtree* root, int key);

RBtree* rotateLeft(RBtree* root, RBtree* x);
RBtree* rotateRight(RBtree* root, RBtree* y);

RBtree* insert(RBtree* root, int key);
RBtree* insertFixup(RBtree* root, RBtree* x);

RBtree* successor(RBtree* x);
RBtree* minimum(RBtree* x);

int height(RBtree* root);

void inorderTreeWalk(RBtree* root);
void preorderTreeWalk(RBtree* root);
void postorderTreeWalk(RBtree* root);

RBtree* deleteByKey (RBtree* root,int key);
RBtree* deleteFixup(RBtree* root,RBtree* x,RBtree* parent);

void readFromFile(RBtree*& root, string &name);
#endif // #ifdef RBTREE_HPP
