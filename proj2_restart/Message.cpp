/*
PROJECTO: Projecto 2
FICHEIRO: Message.cpp
DESCRICAO: Implementa todas as funcoes associadas a classe Message. Funciona sem falhas ou erros.
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
#include "Message.h"

Message::Message(User sender, User recipient, string subject, string contents)
{
	setSender(sender);
	setRecipient(recipient);
	setSubject(subject);
	setContents(contents);
}

Message::~Message()
{
}

User Message::getSender() const
{
    return remetente;
}

string Message::getSenderName() const
{
	return (remetente.getFirstname() + " " + remetente.getLastname());
}

void Message::setSender(User sender)
{
	 remetente = sender;
}

User Message::getRecipient() const
{
    return destinatario;
}

void Message::setRecipient(User recipient)
{
	destinatario = recipient;
}

string Message::getRecipientName() const
{
	return (destinatario.getFirstname() + " " + destinatario.getLastname());
}

string Message::getContents() const
{
    return conteudo;
}

void Message::setContents(string contents)
{
	conteudo = contents;
}

string Message::getSubject() const
{
    return assunto;
}

void Message::setSubject(string subject)
{
	assunto = subject;
}

