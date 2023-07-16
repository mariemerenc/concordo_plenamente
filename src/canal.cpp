#include <iostream>
#include "canal.h"

void Canal::set_nome(std::string nome) {
    this->nome = nome;
}

std::string Canal::get_nome() {
    return this->nome;
}