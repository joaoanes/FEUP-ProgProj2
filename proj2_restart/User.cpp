#include "User.h"

User::User(string firstname, string lastname)
{
	setFirstname(firstname);
	setLastname(lastname);
}
User::User()
{}

User::~User()
{
}

string User::getFirstname() const
{
    return first;
}

void User::setFirstname(string firstname)
{
	first = firstname;
}

string User::getLastname() const
{
    return last;
}

void User::setLastname(string lastname)
{
	last = lastname;
}

string User::getFullname(User user)
{
	return (user.getFirstname() + " " + user.getLastname());
}

bool User::operator== (User &usr)
{
	if ((first == usr.first) && (last == usr.last))
		return true;
	return false;
}