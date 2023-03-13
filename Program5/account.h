//Momin Jafri
//Robert Dimpsey
#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"
#include "fund.h"
using namespace std;

const int KFUND_MAX = 8;
const int KMONEY_MARKET = 0;
const int KPRIME_MONEY_MARKET = 1;
const int KLONG_TERM_BOND = 2;
const int KSHORT_TERM_BOND = 3;

class Account
{
public:
	Account();
	Account(int account_id, string first_name, string last_name);
	~Account();

	void addBalance(int fund_id, int amount);
	bool reduceBalance(int fund_id, int amount, Transaction trans);
	void recordTrans(Transaction trans, int fund_id);
	void accountCheck(int fundID_1, int fundID_2, int amount);

	void printTrans();
	void printFund(int fund_id);


	int get_id() const;
	int get_balance(int fund_id) const;
	string get_fund_id(int fund_id);
	string get_first_name() const;
	string get_last_name() const;

	void setFundId(int fundNumber);

	friend ostream& operator<<(ostream& os, Account& acc);

private:
	int account_id_;
	int fund_id_;
	string first_name_;
	string last_name_;
	Fund fund_array[KFUND_MAX];
};


#endif