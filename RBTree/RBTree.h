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
	void leftRotate(Node* n);
	void rightRotate(Node* n);
	RBTree();
	~RBTree();
};

