// Binary Search Tree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"BinarySearchTree.h"
#include<iostream>

using namespace std;
int main()
{
	BinarySearchTree b;
	for (int i = 0; i < 10; i++) {
		Node* n = new Node(i);
		b.Insert(n);
	}
	if (b.IsEmpty()) {
		cout << "empty" << endl;
	}
	b.Inorder();

    return 0;
}

