/*
PROJECTO: Projecto 2
FICHEIRO: User.h
DESCRICAO: Define os metodos da classe User. Define tambem um overload de "==". Funciona sem falhas ou erros.
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
