#include <iostream>
#include "canalTexto.h"

CanalTexto::CanalTexto(std::string nome) {
    this->nome = nome;
}

void CanalTexto::set_mensagens(std::vector<Mensagem> mensagens) {
    this->vec_mensagens = mensagens;
}

std::vector<Mensagem> CanalTexto::get_mensagens() {
    return this->vec_mensagens;
}

void CanalTexto::enviar_mensagem(Mensagem mensagem) {
    this->vec_mensagens.push_back(mensagem);
}

std::string CanalTexto::get_tipo() {
    return "texto";
}

int CanalTexto::get_mensagens_size() {
    return this->vec_mensagens.size();
}