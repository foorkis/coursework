#include <iostream>
#include "rbtree.h"

using std::cin;
using std::cout;
using std::getchar;

void printHelp()
{
    cout << "choose the action:\n";
    cout << "    h - print this help\n";
    cout << "    a - add new node\n";
    cout << "    d - delete node\n";
    cout << "    p - print tree\n";
    cout << "    s - save tree to .tree file\n";
    cout << "    l - load tree from .tree file\n";
    cout << "    r - create tree from text file\n";
    cout << "    q - exit\n";
    char b;
    b=getchar();
    cout << b;
}

void menu()
{
    char ch;
    printHelp();
    while (true){
        cout >> "/n>"
        cin >> ch;
        case ch 
            
    }
}

