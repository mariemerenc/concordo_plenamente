/**
 * @file canal.h
 * 
 * @brief Definição da classe Canal
 * 
 */

#ifndef CANAL_H
#define CANAL_H

#include <iostream>
#include <string>
#include "mensagem.h"

/**
 * @brief Classe Canal criada para representar um canal de um servidor
 * 
 */
class Canal{
    public:
    std::string nome; //!< Nome do canal 

    void set_nome(std::string nome); //!< Seta o nome do canal
    
    std::string get_nome(); //!< Retorna o nome do canal
};
#endif

