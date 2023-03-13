//Momin Jafri
//Robert Dimpsey
#include <iostream>
#include "fund.h"
using namespace std;

Fund::Fund(){
	
}

Fund::~Fund(){

}

bool Fund::Add(int amount){
	balance_ += amount; //adds given amount to current balance
	return true;
}

bool Fund::Deduct(int amount){
	balance_ -= amount; //subtracts given amount from current balance
	return true;
}

bool Fund::checkBalance(int amount){
	if (balance_ >= amount){ 
		return true;
	}
	return false;
}

bool Fund::recordTransaction(Transaction trans){
	trans_history.push_back(trans); //adds Transition object to vector
	return true;
}

void Fund::displayHistory(){
	if (trans_history.size() == 0){
		cout << "Transaction failed" << endl; //Transaction failed if vector is empty
	}
	cout << fund_name_ << ": $ " << get_balance() << endl; //print out balance
	for (int i = 0; i < trans_history.size(); i++){
		cout << " " << trans_history[i]; //print vector (same method used in display)
	}

}

void Fund::displayFund(){
	for (int i = 0; i < trans_history.size(); i++){
		cout << " " << trans_history[i];
	}
}

void Fund::set_name(string name){
	fund_name_ = name;
}

int Fund::get_balance() const{
	return balance_;
}

string Fund::get_name() const{
	return fund_name_;
}