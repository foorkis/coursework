#include <iostream>
#include <ctime>
#include <stdio.h>
#include "menu.cpp"

using namespace std;

int main()
{
    
    int i, count = 9;
    int key;
    RBtree* root = NULL, *node = NULL;

 
// /*    cout<<" insert 9 keys\n";
//     for (i = 1; i <= count; ++i)
//     {
// 	cin>>key;
// 	root=insert(root,key);
//     }
// */
//     string s = "foo";
//     root=insert(root,1);
//     readFromFile(root,s);
//     cout << root;
//     preorderTreeWalk(root);

//     for (i=1;i<=count;i++)
//     {
// 	cin>>key;
// 	cout<<" delete key "<<key;
// 	root=deleteByKey(root,key);
//     }
    menu(root);
    return 0;
}
