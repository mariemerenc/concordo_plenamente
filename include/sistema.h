/**
 * @file sistema.h
 * 
 * @brief Definição da classe Sistema
 * 
 */
#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "canalVoz.h"
#include "canalTexto.h"
#include "usuario.h"
#include "mensagem.h"
#include "canal.h"
#include "servidor.h"

/**
 * @brief Classe Sistema criada para representar o sistema
 * 
 */
class Sistema{
    std::vector<Usuario> vec_usuarios_cadastrados; //!< Vetor de usuários cadastrados
    std::vector<Servidor> vec_servidores_cadastrados; //!< Vetor de servidores cadastrados
    std::vector<std::string> vec_emails_cadastrados; //!< Vetor de emails cadastrados
    std::string servidor_atual; //!< Nome do servidor atual
    std::string canal_atual; //!< Nome do canal atual
    int usuario_logado_id = -1; //!< Id do usuário logado
    int ultimo_id_gerado; //!< Último id gerado

    void salvar_usuarios(); //!< Salva os usuários cadastrados
    void salvar_servidores(); //!< Salva os servidores cadastrados 

    void carregar_usuarios(); //!< Carrega os usuários cadastrados
    void carregar_servidores(); //!< Carrega os servidores cadastrados

    public:
    void acrescentar_id(); //!< Acrescenta o id do usuário logado
    void set_ultimo_id_gerado(int ultimo_id_gerado); //!< Seta o último id gerado
    int get_ultimo_id_gerado(); //!< Retorna o último id gerado

    int get_usuarios(); //!< Retorna o número de usuários cadastrados
    int get_servidores(); //!< Retorna o número de servidores cadastrados

    void salvar(); //!< Salva os usuários e servidores cadastrados
    void carregar(); //!< Carrega os usuários e servidores cadastrados

    std::string verificar_login(int id_usuario_log); //!< Verifica se o login é válido
    std::string sair(); //!< Sai de uma funcionalidade do Concordo
    std::string login(std::string email, std::string senha); //!< Loga o usuário
    std::string deslogar(); //!< Desloga o usuário

    std::string criar_usuario(const std::string email, const std::string senha, const std::string nome); //!< Cria um usuário
    std::string get_usuario_cadastrado(int id_usuario); //!< Retorna o nome do usuário cadastrado
    std::string listar_participantes(); //!< Lista os participantes do Concordo


    std::string criar_servidor(const std::string nome); //!< Cria um servidor
    std::string set_descricao_servidor(std::string nome, std::string descricao); //!< Seta a descrição do servidor
    std::string set_codigo_convite(std::string nome, std::string codigo_convite); //!< Seta o código de convite do servidor
    std::string entrar_servidor(std::string nome, std::string codigo_convite); //!< Entra em um servidor
    std::string remover_servidor(std::string nome); //!< Remove um servidor
    std::string listar_servidores(); //!< Lista os servidores cadastrados

    std::string listar_canais(); //!< Lista os canais cadastrados
    std::string criar_canal(std::string nome, std::string tipo); //!< Cria um canal
    std::string entrar_canal(std::string nome); //!< Entra em um canal
    std::string sair_canal(); //!< Sai de um canal

    std::string enviar_mensagem(std::string mensagem); //!< Envia uma mensagem
    std::string listar_mensagens(); //!< Lista as mensagens enviadas
};
#endif