// Menu.cpp

#include "Menu.h"

Menu::~Menu()
{
}

Menu::Menu()
{
    name = "";
}

/**
 * Creates a menu, receives the menu description
 */

Menu::Menu(string title, string exit_message)
{
    name = title;
    exitOptionText = exit_message;
}

/**
 * Add a sub menu entry to a menu
 * A submenu entry has a descriptive text and a menu reference
 */
void Menu::add(string name, Menu & menu)
{
    SubMenuEntry *sm = new SubMenuEntry();
    sm->desc = name;
    sm->sub = &menu;
    entries.push_back(sm);
}

/**
 * Add a menu entry to a menu
 * An entry has a descriptive text and a function pointer
 * The function prototype must be "void func(void)"
 */
void Menu::add(string name, void(*func)())
{
    FunctionEntry *me = new FunctionEntry();
    me->desc = name;
    me->func = func;
    entries.push_back(me);
}

/**
 * shows and process a Menu object
 */
void Menu::clear()
{
    for (int i = 0; i < 100; i++)
    {
        cout << "" << endl;
    }
}

void Menu::go()
{
    unsigned int numEntries = entries.size();

    while (true)
    {
        clear();
        cout << "\n\t**** " << name << " ****\n" << endl; // the menu title
        cout << "\t0 - " << exitOptionText << endl; // the quit/return entry

        for (unsigned int i = 0; i < numEntries; i++)
        {
            MenuEntry *mn = entries[i];

            // print each menu entry description
            cout << '\t' << i + 1 << " - " << mn->desc << endl;
        }
        cout << endl;

        // read the user choice
        unsigned int choice = getInput("Opcao: ", 0, (int) numEntries);
        if (choice == 0)
            return; // returns to the previous menu or return from this function
        else
        {
            MenuEntry *me = entries[choice - 1];
            me->exec(); // "execute" the user choice
        }
    }
}

/**
 * Utility function, reads and returns an int within min and max limits from cin
 *
 * It was made static so that it can be used by any class, as in
 * int i = Menu::getInput(...)
 *
 */
int Menu::getInput(string prompt, int min, int max)
{
    int choice;
#define MAX_STRING 256
    char start[MAX_STRING];
    char *end;

    while (true)
    {
        cout << prompt;
        if (cin.peek() == '\n')
            cin.ignore(1000, '\n');
        cin.getline(start, MAX_STRING);

        // converts char* to int, if possible. Use strtof() for float/double
        choice = strtol(start, &end, 10);

        // if strtol() fails end == start
        if (end != start && choice >= min && choice <= max)
            return choice;
    }
}
