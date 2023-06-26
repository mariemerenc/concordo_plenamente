#ifndef CHANNEL_H
#define CHANNEL_H

#include <iostream>

class Canal{
    public:
    std::string nome;
    std::string servidor;
    Canal();
    Canal(std::string c);
    ~Canal();
    void setNome(std::string n);
    std::string getNome();
    void setServidor(std::string s);
    std::string getServidor();
};

#endif