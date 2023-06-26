#include <iostream>
#include "message.h"

Mensagem::Mensagem(){}

Mensagem::Mensagem(std::string dh, std::string c, int ep){dataHora = dh; conteudo = c; enviadaPor = ep;}
    
Mensagem::~Mensagem(){}

void Mensagem::setDataHora(std::string dh){dataHora = dh;}

std::string Mensagem::getDataHora(){return dataHora;}

void Mensagem::setConteudo(std::string c){conteudo = c;}

std::string Mensagem::getConteudo(){return conteudo;}

void Mensagem::setEnviadaPor(int ep){enviadaPor = ep;}

int Mensagem::getEnviadaPor(){return enviadaPor;}