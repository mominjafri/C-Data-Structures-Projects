#include "animal.h"


Animal::Animal()
{
	name_ = "";
	id_ = 0;
}

Animal::~Animal()
{
}

Animal::Animal(string name)
{
	this->name_ = name;
	id_ = 0;
}

Animal::Animal(string name, int id)
{
	this->name_ = name;
	this->id_ = id;
}

string Animal::name() const
{
	return name_;
}

int Animal::id() const
{
	return id_;
}

void Animal::set_name(const string& name)
{
	this->name_ = name;
}

void Animal::set_id(const int& id)
{
	this->id_ = id;
}

bool Animal::operator<(const Animal& rhs) const
{
	return (id_ < rhs.id_);
}

bool Animal::operator<=(const Animal& rhs) const
{
	return (id_ <= rhs.id_);
}

bool Animal::operator>=(const Animal& rhs) const
{
	return (id_ >= rhs.id_);
}

bool Animal::operator>(const Animal& rhs) const
{
	return (id_ > rhs.id_);
}

bool Animal::operator==(const Animal& rhs) const
{
	return (id_ == rhs.id_);
}

bool Animal::operator!=(const Animal& rhs) const
{
	return (id_ != rhs.id_);
}


ostream& operator<<(ostream& stream, const Animal& an)
{
	stream << an.name_ << an.id_;
	return stream;
}

istream& operator>>(istream& stream, Animal& an)
{
	stream >> an.name_;
	stream >> an.id_;
	return stream;
}

