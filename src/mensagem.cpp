#include <iostream>
#include "mensagem.h"

Mensagem::Mensagem() {
    this->autor_id = 0;
    this->data_hora = "";
    this->conteudo = "";
}

Mensagem::Mensagem(int autor_id, std::string data_hora, std::string conteudo) {
    this->autor_id = autor_id;
    this->data_hora = data_hora;
    this->conteudo = conteudo;
}

void Mensagem::set_autor_id(int autor_id) {
    this->autor_id = autor_id;
}

int Mensagem::get_autor_id() {
    return this->autor_id;
}

void Mensagem::set_data_hora(std::string data_hora) {
    this->data_hora = data_hora;
}

std::string Mensagem::get_data_hora() {
    return this->data_hora;
}

void Mensagem::set_conteudo(std::string conteudo) {
    this->conteudo = conteudo;
}

std::string Mensagem::get_conteudo() {
    return this->conteudo;
}