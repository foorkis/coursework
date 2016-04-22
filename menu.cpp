#include <iostream>
#include "rbtree.h"

using std::cin;
using std::cout;
using std::string;
using std::getline;

void printHelp()
{
    cout << "choose the action:\n";
    cout << "    h - print this help\n";
    cout << "    a - add new node\n";
    cout << "    d - delete node\n";
    cout << "    p - print tree\n";
    cout << "    s - search for node by key\n";
    cout << "    r - add nodes from text file\n";
    cout << "    q - exit\n";
}

RBtree* addNewNode(RBtree*& t)
{
    int key;
    cout << "print new node key: ";
    cin >> key;
    t = insert(t,key);
}

RBtree* deleteNode(RBtree*& t)
{
    int key;
    cout << "print node key: ";
    cin >> key;
    t = deleteByKey(t,key);
}

RBtree* printTree(RBtree* t)
{
    if (t == nullptr)
	cout << "empty tree";
    else
	// preorderTreeWalk(t);
	inorderTreeWalk(t);
	// postorderTreeWalk(t);
}

void search(RBtree* t)
{
    if (t == nullptr){
	int key;
	cout << "print node key: ";
	cin >> key;
	cout << "not found";
    }
    else{
	int key;
	cout << "print node key: ";
	cin >> key;
	    if (boolSearch(t,key))
		cout << "found key " << key << '\n';
	    else cout << "not found\n";
    }
}

void readFromFile(RBtree*& t)
{
    string s;
    s = "foo";
    readFromFile(t, s);
}

void menu(RBtree*& t)
{
    printHelp();
    char ch;
    while(true)
    {
	cout << "\n>";
	cin >> ch;
	switch (ch)
	{
	case 'h':
	    printHelp();
	    break;
	case 'a':
	    cout << "add node\n";
	    addNewNode(t);
	    break;
	case 'd':
	    cout << "delete node\n";
	    deleteNode(t);
	    break;
	case 'p':
	    cout << "print tree\n";
	    printTree(t);
	    break;
	case 's':
	    cout << "search for node\n";
	    search(t);
	    break;
	case 'r':
	    cout << "read from file\n";
	    readFromFile(t);
	    break;
      	case 'q':
	    cout << "exit\n";
	    break;
	}
	if (ch == 'q')
	    break;
    }
}
