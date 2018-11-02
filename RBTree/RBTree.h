#pragma once

enum COLOR {
	RED,
	BLACK
};
struct Node {
	COLOR color;
	int key;
	Node* left;
	Node* right;
	Node* parent;
};

class RBTree
{
	Node* root;

public:

	RBTree();
	~RBTree();
	void RBDelete(Node* n);
	//void RBMinimum();

private:
	void deleteFixup(Node* x);
	void insertFixup(Node* z);
	void leftRotate(Node* n);
	void rightRotate(Node* n);
	void transplant(Node* u, Node* v);
	Node* minimum(Node* start);

};

