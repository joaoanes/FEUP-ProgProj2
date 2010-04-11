#include "MessageBox.h"

vector<Message> MessageBox::PrivMensagens;

MessageBox::MessageBox(string name)
{
	setName(name);
}

MessageBox::~MessageBox()
{
}

void MessageBox::addMessage(Message message)
{
	PrivMensagens.push_back(message);
}

void MessageBox::addUser(User user, string password)
{
	MessageboxData temp;
	temp.utilizador = user;
	temp.password = password;
	temp.IsLoggedIn = false;
	PrivDados.push_back(temp);
}
short MessageBox::getUserIndexFromData(User user)
{
	for (size_t i = 0; i < PrivDados.size() ; ++i)
	{
		if (User::equalUsers(user, PrivDados[i].utilizador)) return i;
	}
	return -1;
}

bool MessageBox::loginUser(User user, string pass)
{
	short i = getUserIndexFromData(user);
		if (PrivDados[i].password == pass)
		{
			PrivDados[i].IsLoggedIn = true;
			return true;
		}
	return false; //nao encontra/nao ha password match
}



bool MessageBox::logoutUser(User user)
{
	short i = getUserIndexFromData(user);
	if (i != -1)
	{
		PrivDados[i].IsLoggedIn = false;
		return true;
	}
	return false;
}

bool MessageBox::isLoggedIn(User user)
{
	return PrivDados[getUserIndexFromData(user)].IsLoggedIn;
}

bool MessageBox::isRegistered(User user)
{
	if (getUserIndexFromData(user) != -1)
	{
		return true;
	}
    return false;
}

vector<Message> MessageBox::getAllMessagesFor(User user)
{
   vector<Message> UserMessages;
   for (size_t i = 0; i < PrivMensagens.size() ; ++i)
   {
	   if (User::equalUsers(user, PrivMensagens[i].getRecipient()))
		   UserMessages.push_back(PrivMensagens[i]);
   }
   return UserMessages;
}

vector<Message> MessageBox::getAllMessages()
{
    return PrivMensagens;
}

string MessageBox::getName() const
{
    return nome_caixa;
}

void MessageBox::setName(string name)
{
	nome_caixa = name;
}

vector<User> MessageBox::getRegisteredUsers()
{
	vector<User> AllUsers;
    for (size_t i = 0; i < PrivDados.size() ; ++i)
    {
		AllUsers.push_back(PrivDados[i].utilizador);
    }
	return AllUsers;
}

string MessageBox::getUserPassword(User user)
{
    return PrivDados[getUserIndexFromData(user)].password;
}
