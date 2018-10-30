#include "stdafx.h"
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList():Head(NULL)
{
}


LinkedList::~LinkedList()
{
}

Node* LinkedList::search(int _target)
{
	Node* p = Head;
	while (NULL != p && p->data != _target)
		p = p->next;
	return p;
}

bool LinkedList::insert(int _data)
{
	Node* n = new Node;
	if (n != NULL) {
		n->data = _data;
		n->next = Head;
		Head = n;
		return true;
	}

	return false;
}

bool LinkedList::print()
{
	Node* p = Head;
	int count = 0;
	while (NULL != p) {
		cout << count++ <<":" <<p->data << endl;
		p = p->next;
	}
	cout << "print finish" << endl;
	return true;
}

bool LinkedList::del(int x)
{
	Node* n = Head;
	Node* pre = n;

	while (NULL != n && n->data != x)
	{
		pre = n;
		n = n->next;
	}

	if (NULL == n) {
		return true;
	}

	pre->next = n->next;
	delete n;

	return true;
}
