//Momin Jafri
//Robert Dimpsey
#include <iostream>
#include "transaction.h"
using namespace std;

Transaction::Transaction(){
	transaction_type_ = 0;
}

Transaction::~Transaction(){
}

Transaction::Transaction(char type, int accountID, string firstName, string lastName){ //constructor for Deposit and Withdrawls
	transaction_type_ = type;
	first_name_ = firstName;
	last_name_ = lastName;
	acc_id_ = accountID;
}

Transaction::Transaction(char type, int accountID, int fundID, int amount){ //constructor for F
	transaction_type_ = type;
	acc_id_ = accountID;
	fund_id_ = fundID;
	amount_ = amount;
}

Transaction::Transaction(char type, int accountID, int fundNumber, string fail, int amount){ //constructor for A
	transaction_type_ = type; 
	acc_id_ = accountID;
	fund_id_ = fundNumber;
	amount_ = amount;
	fail_ = fail;
}

Transaction::Transaction(char type, int accountID, int fundID, int accountID_2, int fundID_2, int amount){ //constructor for Transfers
	transaction_type_ = type;
	acc_id_ = accountID;
	fund_id_ = fundID;
	amount_ = amount;
	transfer_acc_id_ = accountID_2;
	transfer_fund_id_ = fundID_2;
}

Transaction::Transaction(char type, int accountID, int fundID, int accountID_2, int fundID_2, int amount, string fail){  //constructor for opening account
	transaction_type_ = type;
	acc_id_ = accountID;
	fund_id_ = fundID;
	amount_ = amount;
	transfer_acc_id_ = accountID_2;
	transfer_fund_id_ = fundID_2;
	fail_ = fail;
}

Transaction::Transaction(char type, int accountID){ //failed constructor
	transaction_type_ = type;
	acc_id_ = accountID;
}

Transaction::Transaction(char type, int accountID, int fundID){
	transaction_type_ = type;
	acc_id_ = accountID;
	fund_id_ = fundID;

}

bool Transaction::check_fail(){ //check to see if Transaction failed or not through empty string
	if (fail_.empty()){
		return true;
	}
	return false;
}

char Transaction::get_type() const {
	return transaction_type_;
}

string Transaction::get_first_name() const {
	return first_name_;
}

string Transaction::get_last_name() const {
	return last_name_;
}

int Transaction::get_acc_id() const {
	return acc_id_;
}

int Transaction::get_amount() const {
	return amount_;
}

int Transaction::get_fund_id() const {
	return fund_id_;
}

int Transaction::get_accID_2() const {
	return transfer_acc_id_;
}

int Transaction::get_fundID_2() const {
	return transfer_fund_id_;
}

ostream& operator<<(ostream& os, const Transaction& trans) {
	if (trans.fail_.empty()){
		if (trans.get_type() == 'D' || trans.get_type() == 'W'){ //set condition
			os << " " << trans.get_type() << " " << trans.get_acc_id() << trans.get_fund_id() << " " << trans.get_amount(); //print out char type along with account/fund IDs and amount
		} else if (trans.get_type() == 'T') {
			os << " " << trans.get_type() << " " << trans.get_acc_id() << trans.get_fund_id() << " " << trans.get_amount() << " " << trans.get_accID_2() << trans.get_fundID_2();

		}

    } else {
		if (trans.get_type() == 'D' || trans.get_type() == 'W' ){
			os << " " << trans.get_type() << " " << trans.get_acc_id() << trans.get_fund_id() << " " << trans.get_amount() << " (FAILED)";
		} else if (trans.get_type() == 'T') {
			os << " " << trans.get_type() << " " << trans.get_acc_id() << trans.get_fund_id() << " " << trans.get_amount() << " " << trans.get_accID_2() << trans.get_fundID_2() << "(FAILED)";
		}
	}
	return os << endl;
}