//Momin Jafri
//Robert Dimpsey
#include "account.h"
#include "bank.h"
#include "bstree.h"
#include "fund.h"
#include "transaction.h"

int main(int argc, const char * argv[]) {
	cin >> argc;
	if(argc < 2){
		cerr << "Please enter a valid file name" << endl;
		return 0;
	}
	string file = argv[1];
	Bank bank;
	bank.readFile(file);
	bank.ProcessQueue();
	bank.Display();
}