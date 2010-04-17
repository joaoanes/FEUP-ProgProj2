/*
PROJECTO: Projecto 2
FICHEIRO: Message.h
DESCRICAO: Define os metodos da classe Message. Funciona sem falhas ou erros.
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
#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>
#include "User.h"

using std::string;

class Message
{
    private:
		User remetente;
		User destinatario;
		string assunto;
		string conteudo;
    public:
        Message(User sender, User recipient, string subject, string contents);
        virtual ~Message();
        User    getSender() const;
        string  getSenderName() const;
        void    setSender(User sender);
        User    getRecipient() const;
        string  getRecipientName() const;
        void    setRecipient(User recipient);
        string  getContents() const;
        void    setContents(string contents);
        string  getSubject() const;
        void    setSubject(string subject);
};

#endif
