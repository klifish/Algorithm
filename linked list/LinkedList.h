//�㷨�����е��������ʵ��
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

	//���ҵ�һ��dataΪ_target��Ԫ��
	Node* search(int _target);
	bool insert( int _data);
	bool del(int x);

	bool print();
};

