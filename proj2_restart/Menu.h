/*
PROJECTO: Projecto 2
FICHEIRO: Menu.h
DESCRICAO: Define a classe menu e todos os seus metodos. Parte do codigo distribuido.
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

#ifndef MENU_H_
#define MENU_H_

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define DEFAULT_EXIT_MESSAGE "Voltar ao menu anterior"

/**
 * Simple and dirty menu generator and processor
 * @author jcard@fe.up.pt
 */
class Menu
{
    public:
        Menu();
        virtual ~Menu();
        Menu(string name, string exit_message = DEFAULT_EXIT_MESSAGE); // the constructor

        void add(string desc, Menu & menu); // add a submenu to this menu
        void add(string desc, void(*)()); // add a function to execute to this menu
        void go(); // process this and all submenus
        static void clear();

        /** this is an utility function.
         * It was made static so that it can be used by any class, as in
         * int i = Menu::getInput(...)
         */
        static int getInput(string prompt, int min, int max); // read and validate an int from cin

    private:
        /**
         * MenuEntry is a private abstract nested class of Menu!
         * It has a descriptive string
         * and subclasses must implement the exec() method
         */
        class MenuEntry
        {
            public:
                string desc; // this menu line descritpive text
                virtual void exec() = 0; // method to "execute" this menu line
                virtual ~MenuEntry()
                {
                }
        };

        /**
         * A MenuEntry can be a FunctionEntry, which is just a function pointer
         * The function it points to must be executed when this menu entry is choosen
         */
        class FunctionEntry: public MenuEntry
        {
            public:
                void (*func)(); // function pointer -- points to a function like "void foo(void)"
                void exec()
                { // this method executes the function that "func" above points to.
                    (*func)(); // awkward, isn't it? but as "func" is a pointer to a function,
                } //  *func is the function, and thus "*func ()" executes it!
        };

        /**
         * A MenuEntry can also be a MenuEntry, which is just another Menu
         */
        class SubMenuEntry: public MenuEntry
        {
            public:
                Menu *sub; // another (sub) Menu
                void exec()
                { // this time, the Menu go() method is invoked
                    sub->go();
                }
        };

        string name; // the Menu description
        string exitOptionText; // the exit option text
        vector<MenuEntry*> entries; // a vector of entries, that are displayed/processed
};

#endif /*MENU_H_*/
