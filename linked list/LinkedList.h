//算法导论中单向链表的实现
#pragma once
#include<iostream>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

class LinkedList
{
	Node* Head;
public:
	LinkedList();
	virtual ~LinkedList();

	bool isEmpty() {
		return Head == NULL;
	}

	//查找第一个data为_target的元素
	Node* search(int _target);
	bool insert( int _data);
	bool del(int x);

	bool print();
};

