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

    menuPrincipal = Menu("DICKSMAIL - ESTEVAO'S NUMBER 1 CHOICE FOR EMALES", "Sair");
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
