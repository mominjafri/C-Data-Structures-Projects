//Momin Jafri -- its almost 3 am and im still commenting out
//Robert Dimpsey
#include <iostream>
#include "account.h"
using namespace std;

Account::Account() {
    first_name_= "";
    last_name_= "";
    account_id_ = 0;
    fund_id_ = 0;
}

Account::Account(int accountId, string firstName, string lastName){
	first_name_ = firstName;
	last_name_ = lastName;
	account_id_ = accountId;
	string funds[] = { //create an array of strings for the fund types
		"Money Market",
		"Prime Money Market",
		"Long-Term Bond",
		"Short-Term Bond",
		"500 Index Fund",
		"Capital Value Fund",
		"Growth Equity Fund",
		"Growth Index Fund"
	};
	for (int i = 0; i < 8; i++){ //segmentation error if sizeof(funds) is implemented in forloop, decided to use actual number instead
		fund_array[i].set_name(funds[i]);
	}
}

Account::~Account(){
}

int Account::get_id() const{
	return account_id_;
}

void Account::addBalance(int fund_id, int amount){
	fund_array[fund_id].Add(amount);
}

void Account::accountCheck(int fundID_1, int fundID_2, int amount){
	if ((fund_array[fundID_1].get_balance() + fund_array[fundID_2].get_balance()) >= amount){ //checks to see if balance from both accounts is greater than the inputted amount
		int balance_available = fund_array[fundID_1].get_balance(); //obtains balance from fund variables
		fund_array[fundID_1].Deduct(balance_available); //subtracts balance available from fund
		Transaction add('W', get_id(), fundID_1, balance_available); //create new Transaction object
		fund_array[fundID_1].recordTransaction(add); //output fund type
		amount = amount - balance_available; //subtract availaible balance from amount

		fund_array[fundID_2].Deduct(amount); //subtract from second fund
		Transaction add_2('W', get_id(), fundID_2, amount);
		fund_array[fundID_2].recordTransaction(add_2);
	} else {
		int balance_available = fund_array[fundID_1].get_balance();
		if (balance_available > amount) { //deducts available balance if it is greater than given amount
			fund_array[fundID_1].Deduct(balance_available);
			Transaction add('W', get_id(), fundID_1, balance_available);
			fund_array[fundID_1].recordTransaction(add);
			amount = amount - balance_available;
		} 
        
        if (fund_array[fundID_2].checkBalance(amount)){ //same thing as previous method except for total balance
			fund_array[fundID_2].Deduct(amount);
			Transaction add('W', get_id(), fundID_2, amount);
			fund_array[fundID_2].recordTransaction(add);
		} else {
			Transaction add('W', get_id(), fundID_2, "FAILED", amount);
			fund_array[fundID_2].recordTransaction(add);
		}
	}
}

bool Account::reduceBalance(int fund_id, int amount, Transaction trans) {
	if (fund_id == KMONEY_MARKET || fund_id == KPRIME_MONEY_MARKET || fund_id == KLONG_TERM_BOND || fund_id == KSHORT_TERM_BOND){ //if fund id is equal to any of the given constants
		if (fund_id == KMONEY_MARKET || fund_id == KPRIME_MONEY_MARKET){
			if (fund_array[fund_id].checkBalance(amount)){
				fund_array[fund_id].Deduct(amount); //match given method to certain conditions
				fund_array[fund_id].recordTransaction(trans);
				return true;
			} else if (((fund_array[KMONEY_MARKET].get_balance() + fund_array[KPRIME_MONEY_MARKET].get_balance()) >= amount)){
				if (fund_id == KMONEY_MARKET) {
					accountCheck(KMONEY_MARKET, KPRIME_MONEY_MARKET, amount); //pass through accountCheck if fund id is equal to certain constant
				} else {
					accountCheck(KPRIME_MONEY_MARKET, KMONEY_MARKET, amount);
				}
			} else {
				if (fund_id == KMONEY_MARKET) {
					accountCheck(KMONEY_MARKET, KPRIME_MONEY_MARKET, amount);
				} else {
					accountCheck(KPRIME_MONEY_MARKET, KMONEY_MARKET, amount);
				}
				return false;
			}
		} else if (fund_id == KLONG_TERM_BOND|| fund_id == KSHORT_TERM_BOND) {
			if (fund_array[fund_id].checkBalance(amount)){
				fund_array[fund_id].Deduct(amount);
				fund_array[fund_id].recordTransaction(trans);
				return true;
			} else if (((fund_array[KLONG_TERM_BOND].get_balance() + fund_array[KSHORT_TERM_BOND].get_balance()) >= amount)){
				if (fund_id == KLONG_TERM_BOND){
					accountCheck(KLONG_TERM_BOND, KSHORT_TERM_BOND, amount);
				} else {
					accountCheck(KSHORT_TERM_BOND, KLONG_TERM_BOND, amount);
				}
			} else {
				if (fund_id == KLONG_TERM_BOND) {
					accountCheck(KLONG_TERM_BOND, KSHORT_TERM_BOND, amount);
				} else {
					accountCheck(KSHORT_TERM_BOND, KLONG_TERM_BOND, amount);
				}
				return false;
			}
		}
    } else {
		if (fund_array[fund_id].checkBalance(amount)){
			fund_array[fund_id].Deduct(amount);
			fund_array[fund_id].recordTransaction(trans);
			return true;
		} else {
			return false;
		}
	}


	return false;
}

void Account::recordTrans(Transaction trans, int fund_id) { //gets fund types
	fund_array[fund_id].recordTransaction(trans);
}

void Account::printTrans() { //display output
	cout << endl << "Transaction History for " << get_first_name() << " " << get_last_name() << " by Fund:" << endl;
	for (int i = 0; i < 8; i++) {
		fund_array[i].displayHistory();
	}
}

void Account::printFund(int fundId) {
	cout << "Transaction history for " << get_first_name() << " " << get_last_name() << " " << get_fund_id(fundId) << " $ " << get_balance(fundId) << endl;
	fund_array[fundId].displayFund();
}

void Account::setFundId(int fundNumber) {
	this->fund_id_ = fundNumber;
}

int Account::get_balance(int fundNumber) const {
	return fund_array[fundNumber].get_balance();
}

string Account::get_fund_id(int fundNumber) {
	return fund_array[fundNumber].get_name();
}

string Account::get_first_name() const {
	return first_name_;
}

string Account::get_last_name() const {
	return last_name_;
}

ostream& operator<<(ostream& os, Account& acc) {
	os << acc.get_first_name() << " " << acc.get_last_name() << " ID: " << acc.get_id() << endl; //output name of client and their account id
	for (int i = 0; i < 8; i++) {
		os << " " << acc.get_fund_id(i) << ": $ " << acc.get_balance(i) << endl; //prints out fund types
	}
	return os;
}