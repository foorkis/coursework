#include "rbtree.h"
#include <iostream>

using namespace std;

// static NIL node for leafs & root parent
static RBtree NIL = {0, 0, 0, 0, BLACK};    
// NIL pointer
#define PNIL (&NIL)

RBtree* newNode(rbKeyT key)
{
    RBtree* node=new RBtree;
    
    node->key=key;
    node->left=PNIL;
    node->right=PNIL;
    node->parent=PNIL;
    node->color=RED;
    
    return node;
}

// search function is common for binary trees
RBtree* search(RBtree* root, rbKeyT key)
{
    if (root==PNIL){
        return PNIL;
    } 
    else{
        RBtree* x=root;
        while (x!=PNIL)
        {
            if (key<x->key){
                x=x->left;
            } 
            else if(key>x->key){
                x=x->right;
            }
            else{
                return x; 
            }
        }
    }
    return PNIL;
}

RBtree* rotateLeft(RBtree* root,RBtree* x)
{
    RBtree* y = x->right;
    x->right=y->left;

    if (y->left != PNIL)
    {
        y->left->parent =x;
    }

    y->parent=x->parent;

    if (x->parent ==PNIL)
    {
        root=y;
    } 
    else if(x==x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }

    y->left=x;
    x->parent=y;

    return root;
}

RBtree* rotateRight(RBtree* root,RBtree* y)
{
    RBtree* x = y->left;
    y->left=x->right;

    if (x->right != PNIL)
    {
        x->right->parent =y;
    }

    x->parent=y->parent;

    if (y->parent ==PNIL)
    {
        root=x;
    } 
    else if(y==y->parent->left)
    {
        y->parent->left = x;
    }
    else
    {
        y->parent->right = x;
    }

    x->right=y;
    y->parent=x;

    return root;
}

RBtree* insert(RBtree* root,rbKeyT key)
{
    RBtree* z=newNode(key);

    if (root==NULL || root==PNIL)
    {
        root=z;
        root->color=BLACK;

        cout<<" success!"<<'\n';
        return root;
    } 
    else
    {
        RBtree* y=PNIL;
        RBtree* x=root;
        while (x!=PNIL)
        {
            y=x;
            if (z->key<x->key)
            {
                x=x->left;
            } 
            else if(z->key>x->key)
            {
                x=x->right;
            }
            else
            {
                cout<<" repeated, ignore!"<<'\n';
                return root;
            }
        }

        z->parent=y;

        if (y==PNIL)
        {
            root=z;
        } 
        else if(z->key<y->key)
        {
            y->left=z;
        }
        else
        {
            y->right=z;
        }

        return insertFixup(root,z);
    }
}

RBtree* insertFixup(RBtree* root, RBtree* z)
{
    RBtree* y=PNIL;

    while (z->parent!=PNIL && z->parent->color==RED)
    {
        if (z->parent==z->parent->parent->left) // z parent == z uncle
        {
            y=z->parent->parent->right;		
            if (y->color==RED) // case1: red uncle
            {
                z->parent->color=BLACK;
                y->color=BLACK;
                z->parent->parent->color=RED;

                z=z->parent->parent;
            } 
            else 
            {
                if (z==z->parent->right) // case2: black uncle, z is a right child
                {
                    z=z->parent;
                    root=rotateLeft(root,z);
                } 
                z->parent->color=BLACK;  // case3: black uncle, z is a left child
                z->parent->parent->color=RED;
                root=rotateRight(root,z->parent->parent);
            }
        } 
        else // z parent != z uncle
        {
            y=z->parent->parent->left;		
            if (y->color==RED) // case4: red uncle
            {
                z->parent->color=BLACK;
                y->color=BLACK;
                z->parent->parent->color=RED;

                z=z->parent->parent; // z passed up to his gradpa
            } 
            else 
            {
                if (z==z->parent->left) // case5: uncle is black, z is a left child
                {
                    z=z->parent;
                    root=rotateRight(root,z);
                } 
                z->parent->color=BLACK; // case6: uncle is black , z is a right child
                z->parent->parent->color=RED;
                root=rotateLeft(root,z->parent->parent);
            }
        }
    }
    root->color=BLACK;
    cout<<" success!"<<'\n';
    return root;
}

RBtree* minimum(RBtree* x)
{
    while (x->left != PNIL)
    {
        x=x->left;
    }
    return x;
}

RBtree* successor(RBtree* x)
{
    if (x->right != PNIL)
    {
        return minimum(x->right);
    } 
    else
    {
        RBtree* y=x->parent;
        while (y!=PNIL && x==y->right)
        {
            x=y;
            y=y->parent;
        }
        return y;
    }
}

int height(RBtree* root)
{
    int leftHeight,rightHeight;

    if (root==NULL || root==PNIL)
    {
        return 0;
    }
    else
    {
        leftHeight=height(root->left);
        rightHeight=height(root->right);

        return (leftHeight>rightHeight
		? (leftHeight+1)
		: (rightHeight+1));
    }
}

void inorderTreeWalk(RBtree* root)
{
    RBtree* x=root;
    if (x!=PNIL)
    {
        inorderTreeWalk(x->left);
        cout<<x->key<<" "<<x->color<<'\n';
        inorderTreeWalk(x->right);
    }
}

void preorderTreeWalk(RBtree* root)
{
    RBtree* x=root;
    if (x!=PNIL)
    {
        cout<<x->key<<" "<<x->color<<'\n';
        preorderTreeWalk(x->left);
        preorderTreeWalk(x->right);
    }
}

void postorderTreeWalk(RBtree* root)
{
    RBtree* x=root;
    if (x!=PNIL)
    {	
        postorderTreeWalk(x->left);
        postorderTreeWalk(x->right);
        cout<<x->key<<" "<<x->color<<'\n';
    }
}

RBtree* deleteByKey(RBtree* root,rbKeyT key)
{
    RBtree* z=search(root,key);

    if (z==PNIL)
    {
        cout<<" doesn't exist!"<<'\n';
    } 
    else
    {
        RBtree* y=PNIL;// y is the actual node to be deleted
        RBtree* x=PNIL;// x is y's child

        if (z->left ==PNIL || z->right ==PNIL)
        {
            y = z;
        } 
        else
        {
            y = successor(z);
        }

        if (y->left != PNIL)
        {
            x = y->left;
        } 
        else
        {
            x = y->right;
        }

        x->parent = y->parent;

        if (y->parent==PNIL)
        {
            root = x;
        } 
        else if (y == y->parent->left)
        {
            y->parent->left=x;
        }
        else
        {
            y->parent->right=x;
        }

        if (y != z)
        {
            z->key = y->key;
        }

        if (y->color==BLACK)
        { 
            root = deleteFixup(root,x,y->parent);
        }

        delete y;
        cout<<" success!"<<'\n';
    }
    return root;
}

RBtree* deleteFixup(RBtree* root,RBtree* x,RBtree* parent)
{
    RBtree* uncle=PNIL;
    if (x->color==RED)
    {
        x->color=BLACK;
    } 
    else
    {
        while (x->color==BLACK && x!=root)
        {
            if (x==x->parent->left)
            {
                uncle=x->parent->right;

                if (uncle->color == RED)  //case1
                {
                    uncle->color = BLACK;
                    x->parent->color = RED;
                    root=rotateLeft(root,x->parent);
                    uncle=x->parent->right;
                }
                else
                {
                    if (uncle->left->color==BLACK &&
                        uncle->right->color==BLACK)  //case2
                    {
                        uncle->color=RED;
                        x=x->parent;
                    } 
                    else 
                    {
                        if(uncle->right->color==BLACK)  //case3
                        {
                            uncle->left->color=BLACK;
                            uncle->color=RED;
                            root=rotateRight(root,uncle);
                            uncle=x->parent->right;
                        }
                        uncle->color=x->parent->color;  //case4
                        x->parent->color = BLACK;
                        uncle->right->color = BLACK;
                        root=rotateLeft(root,x->parent);
                        x=root;
                    }
                }
            } 
            else
            {
                uncle=x->parent->left;

                if (uncle->color == RED)  //case5
                {
                    uncle->color = BLACK;
                    x->parent->color = RED;
                    root=rotateRight(root,x->parent);
                    uncle=x->parent->left;
                }
                else
                {
                    if (uncle->left->color==BLACK &&
                        uncle->right->color==BLACK)  //case6
                    {
                        uncle->color=RED;    
                        x=x->parent;
                    } 
                    else 
                    {
                        if(uncle->left->color==BLACK)  //case7
                        {
                            uncle->right->color=BLACK;
                            uncle->color=RED;
                            root=rotateLeft(root,uncle);
                            uncle=x->parent->left;
                        }
                        uncle->color=x->parent->color;  //case8
                        x->parent->color = BLACK;
                        uncle->left->color = BLACK;
                        root=rotateRight(root,x->parent);
                        x=root;
                    }
                }
            }
        }
    }
    root->color=BLACK;
    return root;
}
/*
RBtree* readFromFile()
{
    FILE* myFile;
    myFile = fopen("tree_file", "r");
    if (myFile == NULL) cout << "Error opening file\n";
    else
    {
	while (!feof (myFile))
}
*/
