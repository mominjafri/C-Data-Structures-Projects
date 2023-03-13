//Momin Jafri
//Robert Dimpsey
#ifndef FUND_H_
#define FUND_H_
#include "transaction.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Fund
{
public:
	Fund();
	~Fund();

	bool Add(int amount);
	bool Deduct(int amount);
	bool checkBalance(int amount); //checks to see if balance is greater than given amount
	bool recordTransaction(Transaction tr);

	void displayFund();
	void displayHistory();
	
	int get_balance() const;
	string get_name() const;

	void set_name(string name);
private:
	int balance_ = 0;
	string fund_name_ = "";
	vector<Transaction> trans_history;
};

#endif