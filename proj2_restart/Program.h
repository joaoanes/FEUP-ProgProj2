#ifndef PROGRAM_H_
#define PROGRAM_H_

#include "User.h"
#include "MessageBox.h"
#include <vector>
#include <string>
#include <sstream>


using std::vector;

class Program
{
    private:
        vector<User>        users;
        vector<MessageBox>  messageBoxes;
        User                getUser(string firstname, string lastname);
		void showAllUsers();
		void showAllMessageboxes();
		void showMessages(vector<Message>& msgs);
		void showMessage(Message& msg);
		bool handleAuth(MessageBox& MB, User& login );
		int handleChoice(int lower, int highernotinclusive);
		bool stringIsNumber(string& victim);
		int intisizer(string str);

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
		void hold();
};

#endif
