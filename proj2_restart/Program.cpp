#include "Program.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

using std::ifstream;
using std::ofstream;
using std::endl;

Program::Program()
{
}

User Program::getUser(string firstname, string lastname)
{
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getFirstname() == firstname && 
            users[i].getLastname() == lastname )
            return users[i];
    }

    // nao deve acontecer...
    return User("", "");
}

void Program::addMessageBox()
{
	string nome;
	std::cout << "	**** Adicao de Caixa de Mensagens ****\n\n" << "Nome: ";
	getline(std::cin, nome);
	MessageBox MessBox(nome);
	messageBoxes.push_back(MessBox);
	std::cout << "\n\n	**** Caixa de mensagens adicionada com sucesso ****";
}

void Program::registerInMessageBox()
{

}

void Program::addUser()
{
	string first;
	string last;
	std::cout << "	**** Adicao de Utilizador ****\n\n" << "Primeiro Nome: ";
	getline(std::cin, first);
	std::cout << "Segundo Nome: ";
	getline(std::cin, last);
	User util(first, last);
	users.push_back(util);
	std::cout << "\n\n	**** Utilizador adicionada com sucesso ****";	
}

void Program::sendMessage()
{
}

void Program::readMessage()
{
}

static vector<string> split(string in, char delim)
{
    vector<string> result;
    size_t i = 0, f;

    while (i < in.size() && ((f = in.find(delim, i)) != string::npos))
    {
        result.push_back(in.substr(i, f-i));
        i = f + 1;
    }

    result.push_back(in.substr(i));
    return result;
}

void Program::loadMessageBoxes(string filename)
{
    ifstream file;
    file.open(filename.c_str());

    if (file.is_open())
    {
        string temp;
        int n_mailboxes;

        getline(file, temp);
        n_mailboxes = atoi(temp.c_str());

        for (int i = 0; i < n_mailboxes; i++)
        {
            string name;
            getline(file, name);
            this->messageBoxes.push_back(MessageBox(name));
        }

        for (int i = 0; i < n_mailboxes; i++)
        {
            int n_users, n_messages;

            getline(file, temp);
            n_users = atoi(temp.c_str());

            for (int j = 0; j < n_users; j++)
            {
                string user_details;
                getline(file, user_details);
                vector<string> name = split(user_details, '|');

                User u = this->getUser(name[0], name[1]);
                this->messageBoxes[i].addUser(u, name[2]);
            }

            getline(file, temp);
            n_messages = atoi(temp.c_str());

            for (int j = 0; j < n_messages; j++)
            {
                string message_header, contents = "", t_contents;
                getline(file, message_header);
                vector<string> details = split(message_header, '|');

                User emitter = this->getUser(details[1], details[2]);
                User recipient = this->getUser(details[3], details[4]);

                getline(file, t_contents);

                if (t_contents == "[conteudo]")
                {
                    while (getline(file, t_contents) && 
                            t_contents != "[/conteudo]")
                    {
                        contents += (t_contents + "\n");
                    }
                }

                this->messageBoxes[i].addMessage(
                        Message(emitter, recipient, details[0], contents));
            }
        }

        file.close();
    }
}

void Program::loadUsers(string filename)
{
    ifstream file;
    file.open(filename.c_str());

    if (file.is_open())
    {
        int n_users;
        string user_details, temp;

        getline(file, temp);
        n_users = atoi(temp.c_str());

        for (int i = 0; i < n_users; i++)
        {
            getline(file, user_details);
            vector<string> name = split(user_details, '|');

            this->users.push_back(User(name[0], name[1]));
        }        

        file.close();
    }
}

void Program::saveMessageBoxes(string filename)
{
    ofstream file;
    file.open(filename.c_str());

    if (file.is_open())
    {
        file << this->messageBoxes.size() << endl;

        for (size_t i = 0; i < this->messageBoxes.size(); i++)
            file << this->messageBoxes[i].getName() << endl;

        for (size_t i = 0; i < this->messageBoxes.size(); i++)
        {
            vector<User> users = this->messageBoxes[i].getRegisteredUsers();
            file << users.size() << endl;

            for (size_t j = 0; j < users.size(); j++)
            {
                file << users[j].getFirstname() << "|" << users[j].getLastname()
                     << "|" << this->messageBoxes[i].getUserPassword(users[j]) 
                     << endl;
            }

            vector<Message> messages = this->messageBoxes[i].getAllMessages();
            file << messages.size() << endl;
            
            for (size_t j = 0; j < messages.size(); j++)
            {
                file << messages[i].getSubject() << "|"
                     << messages[i].getSender().getFirstname() << "|"
                     << messages[i].getSender().getLastname() << "|"
                     << messages[i].getRecipient().getFirstname() << "|"
                     << messages[i].getRecipient().getLastname();
                file << "[conteudo]" << endl;
                file << messages[i].getContents() << endl;
                file << "[/conteudo]" << endl;
            }
        }

        file.close();
    }
}

void Program::saveUsers(string filename)
{
    ofstream file;
    file.open(filename.c_str());
    
    if (file.is_open())
    {
        file << this->users.size() << endl;

        for (size_t i = 0; i < users.size(); i++)
        {
            file << users[i].getFirstname() << "|" << users[i].getLastname() 
                 << endl;
        }

        file.close();
    }
}

