/**
 * @file exec.h
 * 
 * @brief Definição da classe Executor
 * 
 */

#ifndef EXEC_H
#define EXEC_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "sistema.h"

/**
 * @brief Classe Executor criada para executar os comandos do Concordo
 * 
 */
class Executor{
    Sistema *sistema; //!< Ponteiro para o sistema
    bool sair = false; //!< Variável que indica se o usuário quer sair do Concordo

    public:
    Executor(Sistema *sistema); //!< Construtor da classe Executor
    void executar(); //!< Executa os comandos do Concordo

    std::string ler_comando(std::string comando, Sistema *sist); //!< Lê o comando digitado pelo usuário
};
#endif