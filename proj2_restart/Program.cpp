#include "Program.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iosfwd>


using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;
using std::cin;
using std::stringstream;

Program::Program()
{
}

bool Program::stringIsNumber(string& victim)
{
	bool result = true;
	for (size_t i = 0; i < victim.size(); ++i)
	{
		int aye = victim[i];
		bool isit = ((aye < 48) || (aye > 57));
		result = result && !isit;
	}
	return result;
}
int	 Program::intisizer(string str)
{
	int output;
	stringstream sstr;
	sstr << str;
	sstr >> output;
	return output;
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
void Program::hold()
{
	{ char c;
	cout << "Carregue enter para continuar...";
	cin.read(&c,1); 
	if (cin.peek() == 0xA) {;}
	}
}
void Program::addMessageBox()
{
	string nome;
	cout << "	**** Adicao de Caixa de Mensagens ****\n\n" << "Nome: ";
	getline(cin, nome);
	while (nome.size() > 16)
	{
		cout << "O nome dado tem mais do que 16 caracteres. Rectifique este erro e tente novamente.\n";
		getline(cin, nome);
	}
	MessageBox MessBox(nome);
	bool check = false;
	for (size_t i = 0; i < messageBoxes.size() ; ++i)
	{
		check = check || (messageBoxes[i].getName() == nome);
	}
	if (!check)
	{
		messageBoxes.push_back(MessBox);
		cout << "\n\n	**** Caixa de mensagens adicionada com sucesso ****";
		hold();
	}
	else
	{
		cout << "\nJa existe caixa de mensagens com esse nome. Por favor tente com outro nome.";
		hold();
	}
}

void Program::showAllMessageboxes()
{
	cout << "\nCaixas de Mensagens:\n";
	cout << "+-----+----------------------+\n";
	for (size_t i = 0; i < messageBoxes.size() ; ++i)
	{
		cout << "|   " << i <<	" |";
		string temp((21 - (messageBoxes[i].getName()).size()), ' ');
		cout << temp << messageBoxes[i].getName() << " |\n";
	}
	cout << "+-----+----------------------+\n";
}
void Program::showAllUsers()
{
	cout << "Utilizadores:\n";
	cout << "+-----+----------------------+----------------------+\n"; 
	cout << "|   # |              1º Nome |              2º Nome |\n";
	cout << "+-----+----------------------+----------------------+\n";
	for (size_t i = 0; i < users.size() ; ++i)
	{
		cout << "|   " << i <<	" |";
		string temp((21 - (users[i].getFirstname()).size()), ' ');
		cout << temp << users[i].getFirstname();
		cout << " |";
		temp = string((21 - (users[i].getLastname()).size()), ' ');
		cout << temp << users[i].getLastname() << " |\n";
	}
	cout << "+-----+----------------------+----------------------+\n";
}

void Program::showMessages(vector<Message>& msgs)

{
	cout << "Mensagens:\n\n";
	cout << "+-----+----------------------------------------+----------------------+\n"; //40 / 22
	cout << "|   # |                                     De |              Assunto |\n";
	cout << "+-----+----------------------------------------+----------------------+\n";
	for (int i = msgs.size()-1; i >= 0 ; --i)
	{
		cout << "|   " << i <<	" |";
		string temp((39 - (msgs[i].getSenderName()).size()), ' ');
		cout << temp << msgs[i].getSenderName();
		cout << " |";
		temp = string((21 - (msgs[i].getSubject()).size()), ' ');
		cout << temp << msgs[i].getSubject(	) << " |\n";
	}
	cout << "+-----+----------------------------------------+----------------------+\n";
}

void Program::showMessage(Message& msg)
{
	cout << "Assunto: " << msg.getSubject() << endl
		<< "Remetente: " << msg.getSenderName() << endl
		<< "Conteudo: " << msg.getContents(); //a mensagem ja termina com endl
	cout << "	**** FIM DE MENSAGEM ****\n";
}
bool Program::handleAuth(MessageBox& MB, User& login )
{
	bool revisit = false;
	string pw;
	while (!MB.isLoggedIn(login)) 
	{
		if (revisit) //se o ciclo se repetir mais que uma vez, o utilizador e informado que a password nao estava certa.
			cout << "\nPassword errada. Escreva \"\\EXIT\" para sair.";
		cout << "\nEspecifique a sua password de acesso: ";
		cin >> pw;
		if (pw == "\\EXIT")
			return false;
		MB.loginUser(login, pw);
		revisit = true;
	}
	return true;
}
int Program::handleChoice(int lower, int highernotinclusive) //o maior numero nao e inclusivo para podermos usar vector::size() sem ter que decrementar o resultado
{
	string schoice;
	cin >> schoice;
	while (((intisizer(schoice) >= highernotinclusive) || (intisizer(schoice) < lower)) && stringIsNumber(schoice))
	{
		cout << "\nA sua escolha encontra-se fora das escolhas disponiveis. ";
		if (lower != (highernotinclusive - 1))
			cout << "Por favor escolha uma opcao de " << lower << " ate " << highernotinclusive-1 << ".\n";
		else 
			cout << "So pode escolher " << lower << ".\n";
		cin >> schoice;
	}
	if (stringIsNumber(schoice))
		return intisizer(schoice);

	cout << "\nPor favor escolha so numeros para representar escolhas.\n";
	handleChoice(lower, highernotinclusive);

}
void Program::registerInMessageBox()
{
	if (users.empty())
	{
		cout << "Nao existem utilizadores para mandar mensagens. \nAdicione alguns e tente outra vez.\n";
		hold();
		return;
	}
	showAllUsers();
	cout << "\nEscolha o utilizador a registar: ";
	unsigned short choice = handleChoice(0, users.size());
	User ChosenOne = users[choice];
	if (messageBoxes.empty())
	{
		cout << "Nao ha caixas de mensagens. Adicione algumas e tente outra vez.\n";
		hold();
		return;
	}
	showAllMessageboxes();
	cout << "\n\nEscolha a caixa de mensagens na qual se pretende registar: ";
	choice = handleChoice(0, messageBoxes.size());
	cout << "Escolha a sua password de acesso: ";
	string passwd;
	getline(cin, passwd);
	getline(cin, passwd);
	messageBoxes[choice].addUser(ChosenOne, passwd);

	cout << "\n\n	**** Utilizador registado com sucesso ****";
}

void Program::addUser()
{
	string first;
	string last;
	cout << "	**** Adicao de Utilizador ****\n\n" << "Primeiro Nome: ";
	getline(cin, first);
	while (first.size() > 16)
	{
		cout << "O nome dado tem mais do que 16 caracteres. Rectifique este erro e tente novamente.\n";
		getline(cin, first);
	}
	cout << "Segundo Nome: ";
	getline(cin, last);
	while (last.size() > 16)
	{
		cout << "O nome dado tem mais do que 16 caracteres. Rectifique este erro e tente novamente.\n";
		getline(cin, last);
	}
	User util(first, last);
	users.push_back(util);
	cout << "\n\n	**** Utilizador adicionado com sucesso ****\n";
	hold();
}

void Program::sendMessage()
{
	cout << "\n\n	**** Envio de Mensagens ****\n";
	if (users.empty())
	{
		cout << "Nao existem utilizadores para mandar mensagens. \nAdicione alguns e tente outra vez.\n";
		hold();
		return;
	}
	showAllUsers();
	
	cout << "Escolha o emissor da mensagem: ";
	unsigned short temp;
	temp = handleChoice(0, users.size());
	User Sender = users[temp];
	cout << "Escolha o receptor da mensagem: ";
	temp = handleChoice(0, users.size());
	User Reciever = users[temp];
	cout << endl;
	if (messageBoxes.empty())
	{
		cout << "Nao ha caixas de mensagens. Adicione algumas e tente outra vez.\n";
		hold();
		return;
	}
	showAllMessageboxes();
	cout << "\n\nEscolha a caixa de mensagens para a qual pretende enviar o e-mail: ";
	temp = handleChoice(0, messageBoxes.size());
	MessageBox* SendTo = &messageBoxes[temp];
	if (!SendTo->isRegistered(Reciever) || !SendTo->isRegistered(Sender))
	{
		cout << "Um dos utilizadores nao se encontra registado na caixa de mensagens. Por favor tente outra vez.\n";
		hold();
		return;
	}
	if (!handleAuth(*SendTo, Sender)) 
		return; //caso o utilizador escreva "\EXIT" o programa volta ao menu principal
	cout << "\n\nAssunto da Mensagem: ";
	string assunto;
	getline(cin, assunto); //o primeiro e ignorado. go figure.
	getline(cin, assunto);
	while (assunto.size() > 16)
	{
		cout << "O nome dado tem mais do que 16 caracteres. Rectifique este erro e tente novamente.\n";
		getline(cin, assunto);
	}
	string conteudo;
	string temp2;
	cout << "Por favor escreva o conteudo da mensagem. Indique o fim da sua mensagem com uma linha consistindo apenas de um \".\"\n";
	getline(cin, temp2);
	while (temp2 != ".")
	{
		conteudo += temp2;
		getline(cin, temp2);
		conteudo += "\n";
	}
	Message msg(Sender, Reciever, assunto, conteudo);
	SendTo->addMessage(msg);
	cout << "\n		**** Mensagem Enviada ****";
}

void Program::readMessage()
{
	cout << "\n\n	**** Envio de Mensagens ****\n";
	if (users.empty())
	{
		cout << "Nao existem utilizadores para mandar mensagens. \nAdicione alguns e tente outra vez.\n";
		hold();
		return;
	}
	showAllUsers();
	cout << "Escolha o utilizador que pretende ler mensagens: ";
	unsigned short temp;
	temp = handleChoice(0, users.size());
	User* ChosenOne = &users[temp];
	endl(cout);
	if (messageBoxes.empty())
	{
		cout << "Nao ha caixas de mensagens. Adicione algumas e tente outra vez.\n";
		hold();
		return;
	}
	showAllMessageboxes();
	cout << "Escolha a caixa de mensagens a que se pretende ligar: ";
	temp = handleChoice(0, messageBoxes.size());
	MessageBox* ReadFrom = &messageBoxes[temp];
	if (!ReadFrom->isRegistered(*ChosenOne))
	{
		cout << "O utilizador escolhido nao esta registado na caixa. Por favor tente novamente\n";
		hold();
		return;
	}
	if (!handleAuth(*ReadFrom, *ChosenOne))
		return;
	vector<Message> msgs; 
	msgs = ReadFrom->getAllMessagesFor(*ChosenOne);
	if (msgs.empty())
	{
		cout << "O utilizador nao tem mensagens.\n";
		hold();
		return;
	}
	showMessages(msgs);
	cout << "Escolha a mensagem que pretende ler: ";
	temp = handleChoice(0, msgs.size());
	showMessage(msgs[temp]);
	hold();
}

//////////////////////////////////////////////////////////////////////////
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
				file << messages[j].getSubject() << "|"
					<< messages[j].getSender().getFirstname() << "|"
					<< messages[j].getSender().getLastname() << "|"
					<< messages[j].getRecipient().getFirstname() << "|"
					<< messages[j].getRecipient().getLastname() << endl;
				file << "[conteudo]" << endl;
				file << messages[j].getContents() << endl;
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

