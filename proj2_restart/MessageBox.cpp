#include "MessageBox.h"

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
	//Constroi um dado da classe User com os argumentos, e adiciona ao vector
	MessageboxData temp;
	temp.utilizador = user;
	temp.password = password;
	temp.IsLoggedIn = false;
	PrivDados.push_back(temp);
}
short MessageBox::getUserIndexFromData( User user )
//Percorre o vector de dados a procura do utilizador com iguais nomes
{
	for (size_t i = 0; i < PrivDados.size() ; ++i)
	{
		if (User::equalUsers(user, PrivDados[i].utilizador)) return i; 
	}
	return -1; //retorna -1 caso nao exista
}

bool MessageBox::loginUser(User user, string pass)
//Compara a pass dada a pass relativa a um utilizador e caso elas sejam iguais muda o estado de User::IsLoggedIn
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
//Se o utilizador existir muda o estado de IsLoggedIn para false
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
   vector<Message> UserMessages; //Declara um vector vazio
   for (size_t i = 0; i < PrivMensagens.size() ; ++i)
   {
	   if (User::equalUsers(user, PrivMensagens[i].getRecipient()))
		   UserMessages.push_back(PrivMensagens[i]);
	   //Vector esse que e preenchido com mensagens que tenham como destinatario o User user.
   }
   return UserMessages; //Que e devolvido no final.
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
//Retorna um vector com os utilizadores contidos na estrutura PrivDados
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
