/**
 * @file canalTexto.h
 * 
 * @brief Definição da classe CanalTexto
 * 
 */

#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <iostream>
#include <string>
#include <vector>
#include "mensagem.h"
#include "canal.h"

/**
 * @brief Classe CanalTexto criada para representar um canal de texto de um servidor
 * 
 */
class CanalTexto : public Canal{
    public:
    std::vector<Mensagem> vec_mensagens; //!< Vetor de mensagens do canal

    CanalTexto(std::string nome); //!< Construtor da classe CanalTexto

    void set_mensagens(std::vector<Mensagem> mensagens); //!< Seta as mensagens do canal
    std::vector<Mensagem> get_mensagens(); //!< Retorna as mensagens do canal

    void enviar_mensagem(Mensagem mensagem); //!< Envia uma mensagem para o canal

    std::string get_tipo(); //!< Retorna o tipo do canal
    int get_mensagens_size(); //!< Retorna o tamanho do vetor de mensagens
};
#endif