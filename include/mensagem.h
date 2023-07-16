/**
 * @file mensagem.h
 *
 * @brief Definição da classe Mensagem
 * 
 */
#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <iostream>
#include <string>

/**
 * @brief Classe Mensagem criada para representar uma mensagem enviada em um canal
 * 
 */
class Mensagem{
    int autor_id; //!< ID do autor da mensagem
    std::string data_hora;  //!< Data e hora em que a mensagem foi enviada
    std::string conteudo; //!< Conteúdo da mensagem

    public:
    Mensagem(); //!< Construtor da classe Mensagem
    Mensagem(int autor_id, std::string data_hora, std::string conteudo); //!< Construtor da classe Mensagem

    void set_autor_id(int autor_id); //!< Seta o ID do autor da mensagem
    int get_autor_id(); //!< Retorna o ID do autor da mensagem

    void set_data_hora(std::string data_hora); //!< Seta a data e hora em que a mensagem foi enviada
    std::string get_data_hora(); //!< Retorna a data e hora em que a mensagem foi enviada

    void set_conteudo(std::string conteudo); //!< Seta o conteúdo da mensagem
    std::string get_conteudo(); //!< Retorna o conteúdo da mensagem
};
#endif