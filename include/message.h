#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>

class Mensagem{
    std::string dataHora;
    std::string conteudo;
    int enviadaPor;

    public:
    Mensagem();
    Mensagem(std::string dh, std::string c, int ep);
    ~Mensagem();
    void setDataHora(std::string dh);
    std::string getDataHora();
    void setConteudo(std::string c);
    std::string getConteudo();
    void setEnviadaPor(int ep);
    int getEnviadaPor();
};
#endif