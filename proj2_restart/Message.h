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
