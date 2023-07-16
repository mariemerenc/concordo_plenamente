/**
 * @file canalVoz.h
 * 
 * @brief  Definição da classe CanalVoz
 * 
 */
#ifndef CANALVOZ_H
#define CANALVOZ_H

#include <iostream>
#include <string>
#include <vector>
#include "mensagem.h"
#include "canal.h"

/**
 * @brief Classe CanalVoz criada para representar um canal de voz de um servidor
 * 
 */
class CanalVoz : public Canal{
    public:
    CanalVoz(std::string nome); //!< Construtor da classe CanalVoz

    Mensagem ultima_mensagem; //!< Última mensagem enviada no canal

    void set_ultima_mensagem(Mensagem ult_mensagem); //!< Seta a última mensagem enviada no canal
    Mensagem get_ultima_mensagem(); //!< Retorna a última mensagem enviada no canal

    std::string get_tipo(); //!< Retorna o tipo do canal
};
#endif