#include <iostream>
#include <string>
#include "channel.h"
#include "chtext.h"

CanalTexto::CanalTexto(std::string a, std::string b){nome = a; servidor = b;}

CanalTexto::~CanalTexto(){}

std::string CanalTexto::getTodasMensagens(){
    for(auto i{0}; i < mensagens.size(); ++i){
        Mensagem print = mensagens.at(i);
        std::cout << print.getEnviadaPor();
        std::cout << "<" << print.getDataHora() << ">: ";
        std::cout << print.getConteudo() << std::endl;
    }
    return "";
};