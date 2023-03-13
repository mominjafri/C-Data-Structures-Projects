#include "bird.h"

Bird::Bird()
{
	id_ = 0;
}

Bird::Bird(string n)
{
	name_ = n;
	id_ = 0;
}

Bird::Bird(string n, int i)
{
	name_ = n;
	id_ = i;
}

string Bird::name() const
{
	return name_;
}

int Bird::id() const
{
	return id_;
}

void Bird::set_id(const int &id)
{
	id_ = id;
}

void Bird::set_name(const string &n)
{
	name_ = n;
}

bool Bird::operator<(const Bird &rhs) const
{
	return (this->id_ < rhs.id_);
}

bool Bird::operator<=(const Bird &rhs) const
{
	return (this->id_ <= rhs.id_);
}

bool Bird::operator>(const Bird &rhs) const
{
	return (this->id_ > rhs.id_);
}

bool Bird::operator>=(const Bird &rhs) const
{
	return (this->id_ >= rhs.id_);
}

bool Bird::operator==(const Bird &rhs) const
{
	return (this->id_ == rhs.id_);
}

bool Bird::operator!=(const Bird &rhs) const
{
	return (this->id_ != rhs.id_);
}

ostream& operator<<(ostream &stream, const Bird &b)
{
	stream << b.name_ << b.id_;
	return stream;
}

istream& operator>>(istream &stream, Bird &b)
{
	stream >> b.name_;
	stream >> b.id_;
	return stream;
}


Bird::~Bird()
{
}
