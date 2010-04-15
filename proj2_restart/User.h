#ifndef USER_H_
#define USER_H_

#include <string>

using std::string;

class User
{
    private:
		string first;
		string last;
    public:
        User(string firstname, string lastname);
		User();
        virtual ~User();
        string  getFirstname() const;
        void    setFirstname(string firstname);
        string  getLastname() const;
        void    setLastname(string lastname);
		static bool	equalUsers(User user1, User user2); //E PRA SAIR
		string getFullname(User user); //Retorna uma string de "first" + " " + "last"
};

#endif
