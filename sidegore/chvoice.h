#ifndef CHVOICE_H
#define CHVOICE_H

#include <iostream>
#include <string>
#include <vector>
#include "message.h"
#include "channel.h"

class CanalVoz : public Canal{
    Mensagem ultimaMensagem;

    public:
    CanalVoz(std::string a, std::string b);
    ~CanalVoz();
    std::string getTodasMensagens();
};
#endif

