/*
PROJECTO: Projecto 2
FICHEIRO: main.cpp
DESCRICAO: "Liga" a classe program e inicia um menu com as operacoes passiveis de serem escolhidas, lendo depois as mensagens nos ficheiros e iniciando o processo. 
Parte do codigo fornecido inicialmente, sem mudancas.
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
#include <iostream>
#include "Program.h"
#include "Menu.h"

Program program;

void opAddUser()                { program.addUser(); }
void opAddMessageBox()          { program.addMessageBox(); }
void opRegisterInMessageBox()   { program.registerInMessageBox(); }
void opSendMessage()            { program.sendMessage(); }
void opReadMessage()            { program.readMessage(); }

int main()
{
    const string file_mailboxes = "mailboxes.txt";
    const string file_users = "users.txt";

    Menu menuPrincipal, menuCorreio;

    menuPrincipal = Menu("SimpleMail - Mail that is Simple", "Sair");
    menuPrincipal.add("Gestao de Caixas de Correio", menuCorreio);
    menuPrincipal.add("Adicionar Utilizador", opAddUser);

    menuCorreio = Menu("Gestao de Caixas de Correio");
    menuCorreio.add("Adicionar Caixa de Correio", opAddMessageBox);
    menuCorreio.add("Registar-se em Caixa de Correio", opRegisterInMessageBox);
    menuCorreio.add("Enviar mensagem", opSendMessage);
    menuCorreio.add("Ler mensagem", opReadMessage);

    program.loadUsers(file_users);
    program.loadMessageBoxes(file_mailboxes);
    menuPrincipal.go();
    program.saveMessageBoxes(file_mailboxes);
    program.saveUsers(file_users);

    return 0;
}
