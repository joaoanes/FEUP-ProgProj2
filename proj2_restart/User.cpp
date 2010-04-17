/*
PROJECTO: Projecto 2
FICHEIRO: User.cpp
DESCRICAO: Implementa os metodos da classe User. Funciona sem falhas ou erros.
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
