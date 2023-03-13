//Momin Jafri
//Robert Dimpsey
#ifndef BST_H_
#define BST_H_
#include "account.h"
#include <iostream>
using namespace std;

class BSTree
{
public:
	BSTree();
	~BSTree();

	bool Insert(int acc_id, Account* account);
	bool Retrieve(int acc_id, Account*& acc) const;

	bool IsEmpty() const;
	void Delete();
	void Display() const;
	
private:
	struct Node //create Node
	{
		int acc_id_;
		Account* p_account;
		Node* left;
		Node* right;
	};
	Node* root_;
    //private recursive functions since BinaryTrees implement recursive algorithms
	bool InsertRecursively(Node* curr, Account* insert); 
	void RecursivePrint(Node* printNode) const;
};

#endif