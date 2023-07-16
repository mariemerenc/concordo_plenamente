#include <iostream>
#include "canalVoz.h"

CanalVoz::CanalVoz(std::string nome) {
    this->nome = nome;
    this->ultima_mensagem = Mensagem();
}

void CanalVoz::set_ultima_mensagem(Mensagem ult_mensagem) {
    this->ultima_mensagem = ult_mensagem;
}

Mensagem CanalVoz::get_ultima_mensagem() {
    return this->ultima_mensagem;
}

std::string CanalVoz::get_tipo() {
    return "voz";
}
