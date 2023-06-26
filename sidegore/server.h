#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <vector>
#include "channel.h"

class Servidor{
    int usuarioDonold;
    std::string nome;
    std::string descricao;
    std::string codigoConvite;
    std::vector<Canal> canais;

    public:
    std::vector<int> participantesIDs;
    Servidor();
    ~Servidor();
    Servidor(std::string nome);
    void setUsuario(int id);
    int getUsuario();
    void setNome(std::string nome);
    std::string getNome();
    void setDescricao(std::string descricao);
    std::string getDescricao();
    void setCodigo(std::string codigoConvite);
    std::string getCodigo();
    void setIds(std::vector<int> Ids);
    std::vector<int> getIds();
};
#endif