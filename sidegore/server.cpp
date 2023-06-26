#include <iostream>
#include <vector>
#include "server.h"

Servidor::Servidor(){}

Servidor::~Servidor(){}

Servidor::Servidor(std::string n){nome = n;}

void Servidor::setUsuario(int id){usuarioDonold = id;}

int Servidor::getUsuario(){return usuarioDonold;}

void Servidor::setNome(std::string n){nome = n;}

std::string Servidor::getNome(){return nome;}

void Servidor::setDescricao(std::string desc){descricao = desc;}

std::string Servidor::getDescricao(){return descricao;}

void Servidor::setCodigo(std::string codConv) {codigoConvite = codConv;}
    
std::string Servidor::getCodigo(){return codigoConvite;}

void Servidor::setIds(std::vector<int> Ids){participantesIDs = Ids;}

std::vector<int> Servidor::getIds(){return participantesIDs;}

