#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "User.h"
#include "MessageBox.h"
#include <vector>

using std::vector;

class Program
{
    private:
        vector<User>        users;
        vector<MessageBox>  messageBoxes;
        User                getUser(string firstname, string lastname);

    public:
        Program();
        void addUser();
        void addMessageBox();
        void registerInMessageBox();
        void sendMessage();
        void readMessage();
        void loadMessageBoxes(string filename);
        void loadUsers(string filename);
        void saveMessageBoxes(string filename);
        void saveUsers(string filename);
		void showAllUsers();
		void showAllMessageboxes();
};

#endif
