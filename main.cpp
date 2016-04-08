#include <iostream>
#include <ctime>
#include "RBTree.h"

using namespace std;

int main()
{
  int i, count = 9;
	rbKeyT key;
	RBtree* root = NULL, *node = NULL;
	int repeat=0;

	/*srand(time(0));*/
	for (i = 1; i <= count; ++i)
	{
		/*key = rand() % count;*/
            cin>>key;

            cout<<i<<" insert key "<<key;
            root=insert(root,key);
	}

	/*cout<<"Tree height: "<<rbTreeHeight(root)<<endl;

	preorderTreeWalk(root);
	cout<<endl;
	inorderTreeWalk(root);
	cout<<endl;*/

	for (i=1;i<=count;i++)
	{
		cin>>key;

		cout<<i<<" delete key "<<key;
		root=deleteByKey(root,key);
	}

	return 0;
}
