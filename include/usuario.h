/**
 * @file usuario.h
 * 
 * @brief Definição da classe Usuario
 * 
 */
#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

/**
 * @brief Classe Usuario criada para representar um usuário do Concordo
 * 
 */
class Usuario{
    int id; //!< ID do usuário
    std::string nome; //!< Nome do usuário
    std::string email; //!< Email do usuário
    std::string senha; //!< Senha do usuário

    public:
    Usuario(); //!< Construtor padrão da classe Usuario
    Usuario(int id, std::string nome, std::string email, std::string senha); //!< Construtor da classe Usuario
    ~Usuario(); //!< Destrutor da classe Usuario

    void set_id(int id); //!< Seta o ID do usuário
    int get_id(); //!< Retorna o ID do usuário

    void set_nome(std::string nome); //!< Seta o nome do usuário
    std::string get_nome(); //!< Retorna o nome do usuário

    void set_email(std::string email); //!< Seta o email do usuário
    std::string get_email(); //!< Retorna o email do usuário
 
    void set_senha(std::string senha); //!< Seta a senha do usuário
    std::string get_senha(); //!< Retorna a senha do usuário
};
#endif