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
{
	User utilizador;
	string password;
	bool IsLoggedIn;
};

class MessageBox
{
    private:
	string nome_caixa;
	static vector<Message> PrivMensagens;
	vector<MessageboxData> PrivDados;
	
    public:
        MessageBox(string name);
        virtual ~MessageBox();
        string          getName() const;
		vector<MessageboxData>::iterator FindUser(MessageboxData Data, User usr);
        void            setName(string name);
        void            addMessage(Message message);
        void            addUser(User user, string password);
		short			getUserIndexFromData(User user);
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
