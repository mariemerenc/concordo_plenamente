#ifndef CHTEXT_H
#define CHTEXT_H

#include <iostream>
#include <string>
#include <vector>
#include "message.h"
#include "channel.h"

class CanalTexto : public Canal{
    std::vector<Mensagem> mensagens;

    public:
    CanalTexto(std::string a, std::string b);
    ~CanalTexto();
    std::string getTodasMensagens();
};
#endif