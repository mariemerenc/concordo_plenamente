#include <iostream>
#include "user.h"

User::User(){}

User::User(std::string n, std::string e, std::string p){
    nome = n;
    email = e;
    senha = p;
}

User::~User(){}

void User::setId(int i){id = i;}

int User::getId(){return id;}

void User::setNome(std::string n){nome = n;}

std::string User::getNome(){return nome;}

void User::setEmail(std::string e){email = e;}

std::string User::getEmail(){return email;}

void User::setSenha(std::string p){senha = p;}

std::string User::getSenha(){return senha;}