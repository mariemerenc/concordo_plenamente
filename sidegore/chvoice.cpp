#include <iostream>
#include "channel.h"
#include "chvoice.h"

CanalVoz::CanalVoz(std::string a, std::string b){nome = a; servidor = b;}

CanalVoz::~CanalVoz(){}

std::string CanalVoz::getTodasMensagens(){
    Mensagem print = ultimaMensagem;
    std::cout << print.getEnviadaPor();
    std::cout << "<" << print.getDataHora() << ">: ";
    std::cout << print.getConteudo() << std::endl;
    return "";
};