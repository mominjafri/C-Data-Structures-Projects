#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>
#include <iostream>
using namespace std;
class Animal
{
	friend ostream& operator<<(ostream &, const Animal &);
	friend istream& operator>>(istream &, Animal &);

public:
	Animal();
	~Animal();

	Animal(string name);
	Animal(string name, int id);

	string name() const;
	int id() const;
	void set_name(const string &name);
	void set_id(const int &id);

	bool operator<(const Animal &a) const;
	bool operator<=(const Animal &a) const;
	bool operator>=(const Animal &a) const;
	bool operator>(const Animal &a) const;
	bool operator==(const Animal &a) const;
	bool operator!=(const Animal &a) const;

private:
	string name_;
	int id_;
};
#endif

