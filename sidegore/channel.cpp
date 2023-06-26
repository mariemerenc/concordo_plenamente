#include <iostream>
#include "channel.h"

Canal::Canal(){};

Canal::Canal(std::string c){nome = c;}

Canal::~Canal(){};

void Canal::setNome(std::string n){nome = n;}

std::string Canal::getNome(){return nome;}

void Canal::setServidor(std::string s){servidor = s;}

std::string Canal::getServidor(){return servidor;}
