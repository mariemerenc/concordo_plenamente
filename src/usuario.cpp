#include <iostream>
#include "usuario.h"

Usuario::Usuario() {
    this->id = 0;
    this->nome = "";
    this->email = "";
    this->senha = "";
}

Usuario::Usuario(int id, std::string nome, std::string email, std::string senha) {
    this->id = id;
    this->nome = nome;
    this->email = email;
    this->senha = senha;
}

Usuario::~Usuario() {}

void Usuario::set_id(int id) {
    this->id = id;
}

int Usuario::get_id() {
    return this->id;
}

void Usuario::set_nome(std::string nome) {
    this->nome = nome;
}

std::string Usuario::get_nome() {
    return this->nome;
}

void Usuario::set_email(std::string email) {
    this->email = email;
}

std::string Usuario::get_email() {
    return this->email;
}

void Usuario::set_senha(std::string senha) {
    this->senha = senha;
}

std::string Usuario::get_senha() {
    return this->senha;
}