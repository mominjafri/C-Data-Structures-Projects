//Momin Jafri
//Robert Dimpsey
#ifndef BANK_H_
#define BANK_H_
#include "bstree.h"
#include "transaction.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Bank
{
public:
	Bank();
	~Bank();

	bool readFile(string file_name);
	bool ProcessQueue();
    void Display();

private:
	BSTree pAccounts;
	queue<Transaction> transaction;
};

#endif