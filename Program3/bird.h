#ifndef BIRD_H_
#define BIRD_H_
#include <iostream>
#include <string>
using namespace std;

class Bird
{

friend ostream& operator<<(ostream &, const Bird &);
friend istream& operator>>(istream &, Bird &);

public:
	Bird();
	Bird(string name);
	Bird(string name, int id);
	~Bird();

	//getters-setters
	int id() const;
	void set_id(const int &id);
	string name() const;
	void set_name(const string &name);


	bool operator<(const Bird &b) const;
	bool operator<=(const Bird &b) const ;
	bool operator>=(const Bird &b) const;
	bool operator>(const Bird &b) const;
	bool operator==(const Bird &b) const;
	bool operator!=(const Bird &b) const;


private:
	string name_;
	int id_;
};
#endif

