#ifndef USER.H
#define USER.H

#include <iostream>

class User{
    int id;
    std::string nome;
    std::string email;
    std::string senha;

    public:
    User();
    User(std::string nome, std::string email, std::string senha);
    ~User();
    void setId(int i);
    int getId();
    void setNome(std::string n);
    std::string getNome();
    void setEmail(std::string email);
    std::string getEmail();
    void setSenha(std::string password);
    std::string getSenha();
};

#endif