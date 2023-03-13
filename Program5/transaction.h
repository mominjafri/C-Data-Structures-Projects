//Momin Jafri
//Robert Dimpsey
#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include <iostream>
#include <string>
using namespace std;

class Transaction
{
public:
	Transaction();
	~Transaction();

	
	Transaction(char type, int accountID, string firstName, string lastName); //Five different constructors for different char types (D and W share a constructor)
	Transaction(char type, int accountID, int fundID, int amount);
	Transaction(char type, int accountID, int fundID, int accountID_2, int fundID_2, int amount);
	Transaction(char type, int accountID);
	Transaction(char type, int accountID, int fundID);

	
	Transaction(char type, int accountID, int fundID, int accountID_2, int fundID_2, int amount, string fail); //constructors for failed Transactions
	Transaction(char type, int accountID, int fundID, string fail, int amount);

	char get_type() const;
	string get_first_name() const;
	string get_last_name() const;
	int get_acc_id() const;
	int get_fund_id() const;
	int get_fundID_2() const;
	int get_accID_2() const;
	int get_amount() const;
	bool check_fail();

	friend ostream& operator<<(ostream& os, const Transaction& trans);

private:
	int acc_id_ = 0;
	int fund_id_ = 0;
	int transfer_acc_id_ = 0;
	int transfer_fund_id_ = 0;
	int amount_ = 0;
	string first_name_;
	string last_name_;
	string fail_;
	char transaction_type_;
};

#endif