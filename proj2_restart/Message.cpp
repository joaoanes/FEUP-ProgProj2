#include "Message.h"

Message::Message(User sender, User recipient, string subject, string contents)
{
	setSender(sender);
	setRecipient(recipient);
	setSubject(subject);
	setContents(contents);
}

Message::~Message()
{
}

User Message::getSender() const
{
    return remetente;
}

string Message::getSenderName() const
{
	return (remetente.getFirstname() + " " + remetente.getLastname());
}

void Message::setSender(User sender)
{
	 remetente = sender;
}

User Message::getRecipient() const
{
    return destinatario;
}

void Message::setRecipient(User recipient)
{
	destinatario = recipient;
}

string Message::getRecipientName() const
{
	return (destinatario.getFirstname() + " " + destinatario.getLastname());
}

string Message::getContents() const
{
    return conteudo;
}

void Message::setContents(string contents)
{
	conteudo = contents;
}

string Message::getSubject() const
{
    return assunto;
}

void Message::setSubject(string subject)
{
	assunto = subject;
}

