// RBTree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "RBTree.h"


int main()
{
    return 0;
}


/*
左旋转
修改的时候注意：
修改完一对关系之后再修改下一对（这里的一对是指在旋转完成之后，所形成的一对关系）
			p
			|1
			x
		  /   \2
		 a     y
		     /3  \
		    b     r
*/
void RBTree::leftRotate(Node * x)
{
	//获取x的右子节点
	Node* y = x->right;

	//设置x的右子节点
	x->right = y->left;
	//设置y的左子节点的父节点
	if (y->left != NULL)
		y->left->parent = x;

	//设置y的父节点
	y->parent = x->parent;
	//设置x的父节点的子节点
	if (x->parent == NULL)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	//设置y的左子节点
	y->left = x;
	//设置x的父节点
	x->parent = y;
}
/*
右旋转
			p
			|1
			y
		  /2   \
		x       r 
	  /   \3
    a       b
需要修改的为1、2、3这三个连接
*/
void RBTree::rightRotate(Node * y)
{
	//获取y的左子树x
	Node* x = y->left;

	//设置y的左子节点
	y->left = x->right;
	//设置x的右子节点的父节点
	if (x->right != NULL) {
		x->right->parent = y;
	}

	//设置x的父节点
	x->parent = y->parent;
	//设置x的父节点的子节点
	if (y->parent == NULL)
		root = x;
	else if(y == y->parent->left)
		x->parent->left = x;
	else
		x->parent->right = x;

	//设置x的右子节点
	x->right = y;
	//设置y的父节点
	y->parent = x;
}

RBTree::RBTree():root(NULL)
{
}


RBTree::~RBTree()
{
}
