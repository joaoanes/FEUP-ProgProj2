/*
PROJECTO: Projecto 2
FICHEIRO: Program.h
DESCRICAO: Implementa as funcoes necessarias a classe program, colocando algumas funcoes internas de ajuda em private. Funciona sem falhas ou erros.
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
#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "User.h"
#include "MessageBox.h"
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>


using std::vector;

class Program
{
    private:
        vector<User>        users;
        vector<MessageBox>  messageBoxes;
        User                getUser(string firstname, string lastname);

		void	 showAllUsers();
		void	 showAllMessageboxes();
		void	 showMessages(vector<Message>& msgs);
		void	 showMessage(Message& msg);
		bool   	 handleAuth(MessageBox& MB, User& login );
		int		 handleChoice(int lower, int highernotinclusive);
		bool	 stringIsNumber(string& victim);
		int		 intisizer(string str);
		void	 hold();
		string	 stringisizer(int i);

    public:
        Program();
        void	 addUser();
        void	 addMessageBox();
        void	 registerInMessageBox();
        void	 sendMessage();
        void	 readMessage();
        void	 loadMessageBoxes(string filename);
        void	 loadUsers(string filename);
        void	 saveMessageBoxes(string filename);
        void	 saveUsers(string filename);

};

#endif
