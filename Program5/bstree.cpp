//Momin Jafri
//Robert Dimpsey
#include <iostream>
#include "bstree.h"
using namespace std;

BSTree::BSTree(){
	root_ = nullptr; //set root equal to null 
}

BSTree::~BSTree(){
	Delete(); //call upon Delete function in destructor
}

bool BSTree::Insert(int accID, Account* insert){ 
	if (root_ == nullptr){ 
		root_ = new Node; //set root to New node if null
		root_->p_account = insert; //set Account object
		root_->left = nullptr; //set left and right nodes to null
		root_->right = nullptr;
		return true;
	} else {
		Node* curr = root_; //current pointer node is equal to root
		InsertRecursively(curr, insert); //call upon recursive insert method
	}
	return false;
}

bool BSTree::Retrieve(int accID, Account*& acc) const {
	Node* curr = root_;  //create Node equal to root
	bool search = false;

	while (!search) { //set condition that as long as search is true
		if (curr != nullptr && accID == curr->p_account->get_id()){ //curr is not equal to nullpointer and account ID is retrieved from getter
			search = true;
			acc = curr->p_account;
			return search;
		} else if (curr != nullptr && accID > curr->p_account->get_id()){
			curr = curr->right;
		} else if (curr != nullptr && accID < curr->p_account->get_id()){
			curr = curr->left;
		} else {
			search = true;
        }
	}
	cerr << "ERROR: Account with number ( " << accID << " ) cannot be found" << endl; //throw error if search is still false
	return false;
}

void BSTree::Display() const{
	if (IsEmpty()){
		cerr << "ERROR: List is empty" << endl; //throw error if tree is empty
	} 
    
    RecursivePrint(root_); //
}

void BSTree::Delete(){
	if (IsEmpty()){
		return;
	}
	delete root_; //delete root and set to null
	root_ = nullptr;
}

bool BSTree::IsEmpty() const{
	if (root_ == nullptr){
		return true;
	}
	return false;
}

bool BSTree::InsertRecursively(Node* curr, Account* acc) {
	if (acc->get_id() > curr->p_account->get_id()){ //if parameter's account ID is greater than the node's ID
		if (curr->right == nullptr){ 
			Node* insert = new Node(); //construct new Node if right node is equal to null
		    {
				insert->p_account = acc;
				insert->left = nullptr;
				insert->right = nullptr;
				curr->right = insert;
				return true;
			}
		} else {
			return InsertRecursively(curr->right, acc); //call recursive method with right node
        }
	} else if (acc->get_id() < curr->p_account->get_id()) { //same as before except with left node
		if (curr->left == nullptr) {
			Node* insert = new Node();
			insert->p_account = acc;
			insert->left = nullptr;
			insert->right = nullptr;
			curr->left = insert;
			return true;
		} else {
			return InsertRecursively(curr->left, acc);
        }
	}
	cerr << "ERROR: Account " << acc->get_id() << " is already open. Transaction denied." << endl; //throw error if account is already open
	return false;
}

void BSTree::RecursivePrint(Node* curr) const{
	if (curr == nullptr){
		cerr << "FAILED" << endl; //throw error if curr node is null
 	}
	if (curr->right != nullptr && curr->left != nullptr){
		RecursivePrint(curr->left); //call method if both nodes are equal to null
		cout << *curr->p_account << endl;
		RecursivePrint(curr->right);
	} else if (curr->left != nullptr) {
		RecursivePrint(curr->left); //method is only being called for nodes that are set to null
		cout << *curr->p_account << endl;
	} else if (curr->right != nullptr) {
		cout << *curr->p_account << endl;
		RecursivePrint(curr->right);
	} else {
		cout << *curr->p_account << endl; //output account object if all else fails
	}
}