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
using std::setw;
using std::resetiosflags;

Program::Program()
{
}

bool Program::stringIsNumber(string& victim)
//Verifica se certa string pode representar um numero literal
{
	for (size_t i = 0; i < victim.size(); ++i)
	{
		char& aye = victim[i]; //define-se uma referencia para a letra a ser correntemente processada
		bool isit = ((aye < 48) || (aye > 57)); //e verifica se cada um e um algarismo
		if (isit) return false; //se apanhar um char que nao seja um algarismo, a string nao e um numero, logo nao e necessario continuar
	}
	return true;
}
int	 Program::intisizer(string str)
//string -> int
{
	int output;
	stringstream sstr;
	sstr << str;
	sstr >> output;
	return output;
}
string Program::stringisizer(int i)
//int -> string
{
	stringstream hello;
	string str;	
	hello << i;
	hello >> str;
	return str;
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
//Substituto de system("pause");
{
	{ char c;
	cout << "Carregue enter para continuar...";
	cin.read(&c,1); 
	if (cin.peek() == 10) {}
	}
}
void Program::addMessageBox()
//Adiciona uma caixa de mensagens, verificando antes se ela ja existe
{
	string nome;
	cout << "	**** Adicao de Caixa de Mensagens ****\n\n" << "Nome: ";
	getline(cin, nome);
	while (nome.size() > 18)
		//No caso do nome ter um tamanho superior a 18, o utilizador deve rectificar o erro
	{
		cout << "O nome dado tem mais do que 18 caracteres. Rectifique este erro e tente novamente.\n";
		getline(cin, nome);
	}
	bool check = false;
	for (size_t i = 0; i < messageBoxes.size() ; ++i)
	{
		check = check || (messageBoxes[i].getName() == nome); //Compara se existe uma messagebox com o mesmo nome
	}
	if (!check)
		//e no caso de nao existir, constroi uma messagebox com o nome dado pelo utilizador
	{
		MessageBox MessBox(nome);
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
//Encapsula numa caixa uma lista de todas as messageboxes existentes
{
	cout << "\nCaixas de Mensagens:\n";
	cout << "+-----+----------------------+\n";
	for (size_t i = 0; i < messageBoxes.size() ; ++i)
	{
		cout << setw(4) << i <<	" |";
		cout << setw(21) << messageBoxes[i].getName() << " |\n";
	}
	cout << "+-----+----------------------+\n";
}
void Program::showAllUsers()
//Mostra todos os utilizadores com indice crescente
{
	cout << "Utilizadores:\n";
	cout << "+-----+----------------------+----------------------+\n"; 
	cout << "|   # |              1º Nome |              2º Nome |\n";
	cout << "+-----+----------------------+----------------------+\n";
	for (size_t i = 0; i < users.size() ; ++i)
	{
		string stri = stringisizer(i);
		cout << "|" << setw(4) << i <<	" |";
		cout << setw(21) << users[i].getFirstname();
		cout << " |";
		cout << setw(21) << users[i].getLastname() << " |\n";
	}
	cout << "+-----+----------------------+----------------------+\n";
}


void Program::showMessages(vector<Message>& msgs)
//De uma maneira similar a showAllMessages, mostra um vector de mensagens no ecra, encapsulado
{
	cout << "Mensagens:\n\n";
	cout << "+-----+----------------------------------------+----------------------+\n"; //40 / 22 espacos brancos
	cout << "|   # |                                     De |              Assunto |\n";
	cout << "+-----+----------------------------------------+----------------------+\n";
	for (int i = msgs.size()-1; i >= 0 ; --i)
	{
		
		cout << "|" << setw(4) << i <<	" |";
		cout << setw(40) << msgs[i].getSenderName();
		cout << " |";
		cout << setw(21) << msgs[i].getSubject(	) << " |\n";
	}
	cout << "+-----+----------------------------------------+----------------------+\n";
}

void Program::showMessage(Message& msg)
//Mostra uma mensagem passada por referencia nos argumentos
{
	cout << "Assunto: " << msg.getSubject() << endl
		<< "Remetente: " << msg.getSenderName() << endl
		<< "Conteudo: " << msg.getContents(); //a mensagem ja termina com endl
	cout << "	**** FIM DE MENSAGEM ****\n";
}
bool Program::handleAuth(MessageBox& MB, User& login )
//Esta funcao trata de qualquer pedido de autenticacao feito no pedido, nao fazendo nada se o utilizador
//ja esteja autenticado na caixa de mensagens a que ele esta a tentar aceder
{
	bool revisit = false;
	string pw;
	while (!MB.isLoggedIn(login)) 
	{
		if (revisit) //se o ciclo se repetir mais que uma vez, o utilizador e informado que a password nao estava certa.
			cout << "\nPassword errada. Escreva \"\\EXIT\" para sair."; 
		cout << "\nEspecifique a sua password de acesso: ";
		cin >> pw;
		if (pw == "\\EXIT")//Se o utilizador por qualquer motivo desistir do processo, pode escrever "\EXIT" para desistir do processo
			//Retornando entao o valor "false"
			return false;
		MB.loginUser(login, pw);
		revisit = true;
	}
	return true;
}
int  Program::handleChoice(int lower, int highernotinclusive) //o maior numero nao e incluido para podermos usar vector::size() sem ter que decrementar o resultado
//Esta funcao aje mais como uma subrotina, tratando de todas as operacoes que envolvam escolhas numericas
{
	string schoice;
	cin >> schoice;
	while (((intisizer(schoice) >= highernotinclusive) || (intisizer(schoice) < lower)) && stringIsNumber(schoice))
		//Este ciclo so se processa caso o que utilizador escreveu for realmente so constituido por algarismos e compara se 
		//esta se encontra entre as opcoes validas e se e uma escolha valida em termos de sintaxe
	{
		cout << "\nA sua escolha encontra-se fora das escolhas disponiveis. ";
		if (lower != (highernotinclusive - 1))
			//Caso exista mais de uma opcao por onde escolher, ele mostra os resultados possiveis
			cout << "Por favor escolha uma opcao de " << lower << " ate " << highernotinclusive-1 << ".\n";
		else 
			//Senao ele mostra o unico resultado possivel
			cout << "So pode escolher " << lower << ".\n";
		cin >> schoice;
	}
	//O que pode acontecer tambem e dentro do ciclo while o utilizador colocar algo que nao e um numero, tendo caracteres que nao sao algarismos
	//Nessa situacao o ciclo while termina, e e feita a verificacao neste if, que caso seja valido, tendo "escapado" o while, tem de
	//ser necessariamente um numero valido
	if (stringIsNumber(schoice))
		return intisizer(schoice);
	//caso nao o seja, a funcao e chamada recursivamente ate encontrar uma possivel.
	cout << "\nPor favor escolha so numeros para representar escolhas.\n";
	return handleChoice(lower, highernotinclusive);
}
void Program::registerInMessageBox()
//Regista um utilizador numa messagebox
{
	if (users.empty())//Primeiro ele verifica se existem utilizadores passiveis de ser registados
	{
		cout << "Nao existem utilizadores para mandar mensagens. \nAdicione alguns e tente outra vez.\n";
		hold();
		return;
	}
	showAllUsers();
	cout << "\nEscolha o utilizador a registar: ";
	unsigned short choice = handleChoice(0, users.size());
	User* ChosenOne = &users[choice]; //E guardada a escolha do utilizador num apontador para o User no vector users, de modo a acelara
	//os acessos a memoria
	if (messageBoxes.empty())//E verifica se existem caixas de correio passiveis de aceitarem registos
	{
		cout << "Nao ha caixas de mensagens. Adicione algumas e tente outra vez.\n";
		hold();
		return;
	}
	showAllMessageboxes();
	cout << "\n\nEscolha a caixa de mensagens na qual se pretende registar: ";
	choice = handleChoice(0, messageBoxes.size());
	if (messageBoxes[choice].isRegistered(*ChosenOne))//Verifica-se se ja ha algum utilizador com o mesmo nome.
	{
		cout << "O utilizador que pretende registar ja se encontra registado.\n"; 
		return;
	}
	cout << "Escolha a sua password de acesso: ";
	string passwd;
	getline(cin, passwd);
	getline(cin, passwd);
	messageBoxes[choice].addUser(*ChosenOne, passwd); //Se nao, adiciona um utilizador a lis

	cout << "\n\n	**** Utilizador registado com sucesso ****";	
}

void Program::addUser()
//De maneira simples, este pede duas variavei de 18chars e constrou um dado da classe USER com eles
{
	string first;
	string last;
	cout << "	**** Adicao de Utilizador ****\n\n" << "Primeiro  q q Nome: ";
	getline(cin, first);
	while (first.size() > 18)
	{
		cout << "O nome dado tem mais do que 18 caracteres. Rectifique este erro e tente novamente.\n";
		getline(cin, first);
	}
	cout << "Segundo Nome: ";
	getline(cin, last);
	while (last.size() > 18)
	{
		cout << "O nome dado tem mais do que 18 caracteres. Rectifique este erro e tente novamente.\n";
		getline(cin, last);
	}
	User util(first, last);
	users.push_back(util);
	cout << "\n\n	**** Utilizador adicionado com sucesso ****\n";
	hold();
}

void Program::sendMessage()
//Envia uma mensagem de um utilizador para outro numa messagebox
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
	User* Sender = users[temp];
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
	if (cin.peek() == '\n')
		cin.ignore(1000,'\n');
	getline(cin, assunto);
	while (assunto.size() > 18)
	{
		cout << "O nome dado tem mais do que 18 caracteres. Rectifique este erro e tente novamente.\n";
		getline(cin, assunto);
	}
	string conteudo;
	string temp2;
	cout << "Por favor escreva o conteudo da mensagem. Indique o fim da sua mensagem com uma linha consistindo apenas de um \".\"\n";
	getline(cin, temp2);
	while (temp2 != ".")
		//Aqui, ate encontrar um "." em temp2, vai construindo o conteudo com as linhas de texto e um caracter endl apos cada linha
		//ja que cin ignora endlines
	{
		conteudo += temp2;
		getline(cin, temp2);
		conteudo  += "\n";
	}
	Message msg(Sender, Reciever, assunto, conteudo);
	SendTo->addMessage(msg);
	//Apos estarem reunidos todos os dados, constroi-se a mensagem e adiciona-se a messagebox

	cout << "\n		**** Mensagem Enviada ****";
}

void Program::readMessage()
//Le uma mensagem escolhida pelo utilizador
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
	User* ChosenOne = &users[temp]; //E lido o utilizador escolhido como um apontador
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
	MessageBox* ReadFrom = &messageBoxes[temp]; //E a messagebox para onde ler e lida tambem como apontador
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
	//E criado um vector contendo todas as mensagens enderecadas ao User escolhido
	if (msgs.empty())
	{
		cout << "O utilizador nao tem mensagens.\n";
		hold();
		return;
	}
	showMessages(msgs); //Depois e apresentado ao utilizador a lista de mensagens totais
	cout << "Escolha a mensagem que pretende ler: ";
	temp = handleChoice(0, msgs.size()); //E ele escolhe a mensagem que quer ler.
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

