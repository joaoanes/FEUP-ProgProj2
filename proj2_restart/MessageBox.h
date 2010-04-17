/*
PROJECTO: Projecto 2
FICHEIRO: MessageBox.h
DESCRICAO: Define as funcoes da classe MessageBox. Define a estrutura MessageboxData. Funciona sem falhas ou erros.
TURMA / GRUPO: 9/04
AUTORES:
- Eduardo Jesus 
- Joao Anes
DECLARACAO:
Declaramos sob compromisso de honra que este trabalho nas suas partes constituintes de codigo (e
relatorio, se aplicavel)? e original e da nossa autoria, nao correspondendo, portanto, a copia ou traducao
de outros trabalhos ja realizados, na FEUP ou fora dela.
Mais declaramos que todos os documentos ou c½digo que serviram de base ao desenvolvimento do
trabalho descrito no relatorio e seus anexos s?o adequadamente citados e explicitados na respectiva
seccao de referencias bibliograficas e que todas as eventuais partes transcritas ou utilizadas de outras
fontes estao devidamente assinaladas, identificadas e evidenciadas.
Subscrevemos a declaracao acima:
Eduardo Jesus,
Joao Anes
REFERENCIAS E FONTES DE INFORMACAO UTILIZADAS:
cplusplus.com
cppreference.com
stackoverflow.com
SISTEMA OPERATIVO:
Windows 7
AMBIENTE DE DESENVOLVIMENTO:
Visual Studio 2008
DATA DE INICIO: 05/04
DATA DE CONCLUSAO: 17/04
ESPECIFICACOS ADICIONAIS:
Testado com:
MSVC C++
ICC
g++
*/
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
