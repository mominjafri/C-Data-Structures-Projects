//Momin Jafri
//Robert Dimpsey
#include "bank.h"
#include "account.h"
#include "transaction.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>

Bank::Bank(){

}

Bank::~Bank(){

}

bool Bank::readFile(string file_name){
	ifstream fileRead(file_name); //create ifstream variable
	string name; //new string variable that will read lines

	while (getline(fileRead, name)){ 
		istringstream read_string(name); //create parse/ss stream variable
		char type; 
		read_string >> type; //reads first char of line

		if (type == 'O'){ //set char conditions
			string firstName;
            string lastName;
			int accID;
			read_string >> accID >> lastName >> firstName; //parse will readstrings
			Transaction add2Queue(type, accID, lastName, firstName); //make Transaction object (put variables/parameters in corresponding constructor)
			transaction.push(add2Queue); //push on queue
          

		} else if (type == 'W' || type == 'D') { 
			int accID, fundID, amount;
			read_string >> accID >> fundID >> amount;
			Transaction add2Queue(type, accID, fundID, amount); //same constructor for both D and W
			transaction.push(add2Queue);
         

		} else if (type == 'T') {
			int accID, fundID, amount, transferAccID, transferFundID;
			read_string >> accID >> fundID >> transferAccID >> transferFundID >> amount;
			Transaction add2Queue(type, accID, fundID, transferAccID, transferFundID, amount);
			transaction.push(add2Queue);
        

		} else if (type == 'A') {
			int accID;
			read_string >> accID;
			Transaction add2Queue(type, accID);
			transaction.push(add2Queue);
           

		} else if (type == 'F') {
			int accID, fundID;
			read_string >> accID >> fundID;
			Transaction add2Queue(type, accID, fundID);
			transaction.push(add2Queue);
          

		} else {
			cerr << "ERROR: Transaction unknown" << endl; //throw error if char is not set to any listed above
    
	}
    }
	fileRead.close(); 
	return false;
    
}

bool Bank::ProcessQueue(){
	while (!transaction.empty()){
		Transaction trans = transaction.front(); //push object to front of queue if queue isn't empty

		if (trans.get_type() == 'O'){
			Account* account = new Account(trans.get_acc_id(), trans.get_last_name(), trans.get_first_name()); //set new Account object
			pAccounts.Insert(trans.get_acc_id(), account); //insert data into "tree"

        

		} else if (trans.get_type() == 'D'){
			int accountID = trans.get_acc_id(); //retrieve variables via getters
			int fundID = trans.get_fund_id();
			int addAmount = trans.get_amount();
			Account* account;
			if (pAccounts.Retrieve(accountID, account)){ //if tree object retrieves account ID and account object
				account->addBalance(fundID, addAmount);
				account->recordTrans(trans, fundID);
			}


		} else if (trans.get_type() == 'W'){
			int accountID = trans.get_acc_id();
			int fundID = trans.get_fund_id();
			int deductAmount = trans.get_amount();
			Account* account;
			if (pAccounts.Retrieve(accountID, account)){
				account->reduceBalance(fundID, deductAmount, trans);
			}


		} else if (trans.get_type() == 'T') {
			int accountID = trans.get_acc_id(); 
			int fundID = trans.get_fund_id();
			int accountID_2 = trans.get_accID_2();
			int fundID_2 = trans.get_fundID_2();
			int amount = trans.get_amount();
			Account* to; //create new Account objects
			Account* from;
			if (pAccounts.Retrieve(accountID, to) && pAccounts.Retrieve(accountID_2, from)){ //if data can be retrieved from both objects
				if (to->reduceBalance(fundID, amount, trans)){ //reduce balance from first object
					from->addBalance(fundID_2, amount); //add balance to second
					from->recordTrans(trans, fundID_2); //obtain which fund transaction is
				} else {
					Transaction add('T', accountID, fundID, accountID_2, fundID_2, amount, "FAILED"); 
					from->recordTrans(add, fundID_2);
				}
			}


		} else if (trans.get_type() == 'A') {
			Account* account;
			int accountSearch = trans.get_acc_id();
			if (pAccounts.Retrieve(accountSearch, account)) {
				account->printTrans();
				cout << endl;
			}

		} else if (trans.get_type() == 'F') {
			Account* account;
			int fundID = trans.get_fund_id();
			int accountSearch = trans.get_acc_id();
			if (pAccounts.Retrieve(accountSearch, account)) {
				account->printFund(fundID);
				cout << endl;
			}

		}
		transaction.pop();
	}

    return false;

}


void Bank::Display(){
	cout << endl << "FINAL BALANCES." << endl;
	pAccounts.Display(); //use BSTree Display method
}