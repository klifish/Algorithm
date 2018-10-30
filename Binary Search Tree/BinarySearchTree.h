#pragma once
//#include<vector>

struct Node {
	int Key;
	Node* Left;
	Node* Right;
	Node* Parent;
	void* Data;
	Node(int k):Key(k),Left(NULL),Right(NULL),Parent(NULL),Data(NULL){}
	~Node() {}
};

class BinarySearchTree
{
	Node* root;
public:
	BinarySearchTree();
	~BinarySearchTree();

	bool IsEmpty();
	void Inorder();
	Node* Search(int _target);
	bool Insert(Node* n);
	Node* Min();

private:
	Node * min(Node* _root);
	void inorderTreeWalk(Node* _root);

	Node* search(Node* _root, int _target);
	Node* iterativeSearch(Node* _root, int _target);

	void transplant(Node* dst, Node* src);
	void deleteNode(Node* n);
};

