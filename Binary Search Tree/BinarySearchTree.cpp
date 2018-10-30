#include "stdafx.h"
#include "BinarySearchTree.h"
#include<iostream>

using namespace std;


BinarySearchTree::BinarySearchTree() :root(NULL)
{
}


BinarySearchTree::~BinarySearchTree()
{
}

bool BinarySearchTree::IsEmpty()
{
	if (NULL == root)
		return true;
	else
		return false;
}

void BinarySearchTree::Inorder()
{
	this->inorderTreeWalk(root);
}

Node * BinarySearchTree::Search(int _target)
{
	return search(root,_target);
}

bool BinarySearchTree::Insert(Node * n)
{
	Node* p = root;
	Node* parent = p;
	while (p != NULL) {
		parent = p;
		if (n->Key < p->Key)
			p = p->Left;
		else
			p = p->Right;
	}
	n->Parent = parent;

	if (NULL == parent)
		root = n;
	else if (n->Key < parent->Key)
		parent->Left = n;
	else
		parent->Right = n;

	return false;
}

Node * BinarySearchTree::Min()
{
	return min(root);
}


Node * BinarySearchTree::min(Node * _root)
{
	while (_root->Left != NULL)
		_root = _root->Left;

	return _root;
}

void BinarySearchTree::inorderTreeWalk(Node* _root)
{
	if (_root == NULL)
		return;

	this->inorderTreeWalk(_root->Left);
	cout << _root->Key << endl;
	this->inorderTreeWalk(_root->Right);
}

Node* BinarySearchTree::search(Node * _root, int _target)
{
	if (_root == NULL || _root->Key == _target)
		return _root;

	if (_root->Key < _target)
		return search(_root->Right, _target);
	else
		return search(_root->Left, _target);
}

Node * BinarySearchTree::iterativeSearch(Node * _root, int _target)
{
	while (_root != NULL && _target != _root->Key) {
		if (_target < _root->Key)
			_root = _root->Left;
		else
			_root = _root->Right;
	}
	return _root;
}

void  BinarySearchTree::transplant(Node * _dst, Node * _src)
{
	//root½Úµã
	if (_dst->Parent == NULL)
		root = _src;
	else if (_dst == _dst->Parent->Left)
		_dst->Parent->Left = _src;
	else
		_dst->Parent->Right = _src;

	if (_src != NULL)
		_src->Parent = _dst->Parent;
}

void BinarySearchTree::deleteNode(Node * z)
{
	if (z->Left == NULL)
		transplant(z, z->Right);
	else if (z->Right == NULL)
		transplant(z, z->Left);
	else {
		Node* y = min(z->Right);
		if (y->Parent != z) {
			transplant(y, y->Right);
			y->Right = z->Right;
			y->Right->Parent = y;
		}

		transplant(z, y);
		y->Left = z->Left;
		y->Left->Parent = y;
	}
}
