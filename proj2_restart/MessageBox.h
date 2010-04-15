#ifndef MESSAGEBOX_H_
#define MESSAGEBOX_H_

#include <string>
#include <algorithm>
#include <vector>
#include "Message.h"
#include "User.h"

using std::string;
using std::vector;

struct MessageboxData
//Usamos uma estrutura de dados para guardar principalmente a relacao entre um utilizador,
//a sua password e se ja se autenticou em casa sessao.
{
	User utilizador;
	string password;
	bool IsLoggedIn;
};

class MessageBox
{
    private:
	string nome_caixa;
	vector<Message> PrivMensagens; //Guardamos num vector todas as mensagens da caixa
	vector<MessageboxData> PrivDados; //E guardamos todos os utilizadores/passwords
	
    public:
        MessageBox(string name);
        virtual ~MessageBox();
        string          getName() const;
        void            setName(string name);
        void            addMessage(Message message);
        void            addUser(User user, string password);
		short getUserIndexFromData(User user); //Devolve o indice do utilizador "user" no vector PrivDados, usado em outras funcoes
        bool            loginUser(User user, string password);
        bool            logoutUser(User user);
        bool            isLoggedIn(User user);
        bool            isRegistered(User user);
        vector<Message> getAllMessagesFor(User user);
        vector<Message> getAllMessages();
        vector<User>    getRegisteredUsers();
        string          getUserPassword(User user);
};

#endif
