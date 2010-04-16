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
		string getFullname(User user); //Retorna uma string de "first" + " " + "last"
		bool User::operator== (User &usr); //Compara entre dois utilizadores de maneira mais intuitiva
};

#endif
