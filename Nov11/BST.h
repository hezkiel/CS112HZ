/*
 * BST.h
 *
 *  Created on: Nov 11, 2013
 *      Author: hezkiel
 */

#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <stdexcept>
using namespace std;

typedef double Item;
class BST {
public:
	BST();
	virtual ~BST() {delete myRoot;}
	unsigned getSize() const {return mySize;}
	void insert(const Item& it);
	bool contains(const Item& it);
	void preorderTraverse() const;
	void inorderTraverse() const;
	void postorderTraverse() const;
private:
	unsigned mySize;
	struct Node {
		Node(const Item& it){myItem = it; myLeft = myRight = NULL;};
		~Node(){ delete myLeft; delete myRight;};
		void nodeInsert(const Item& it);
		bool nodeContains(const Item& it);
		void visit() const {cout<<myItem<< ' ';};
		void preorder() const;
		void inorder() const;
		void postorder() const;
		Item myItem;
		Node * myLeft;
		Node * myRight;
	};
	Node * myRoot;
	friend class BST_Tester;
};

#endif /* BST_H_ */
