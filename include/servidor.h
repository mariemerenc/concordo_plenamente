/**
 * @file servidor.h
 * 
 * @brief Definição da classe Servidor
 * 
 */
#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <iostream>
#include <string>
#include <vector>
#include "canal.h"
#include "canalTexto.h"
#include "canalVoz.h"

class Servidor{
    int id_dono_servidor; // ID do dono do servidor
    std::string nome; // Nome do servidor
    std::string descricao; // Descrição do servidor
    std::string codigo_convite; // Código de convite do servidor

    std::vector<Canal> vec_canais; // Vetor de canais do servidor
    std::vector<CanalTexto> vec_canais_texto; // Vetor de canais de texto do servidor
    std::vector<CanalVoz> vec_canais_voz; // Vetor de canais de voz do servidor
    std::vector<int> vec_usuarios_ids; // Vetor de IDs dos usuários que participam do servidor

    public:
    Servidor(); // Construtor da classe Servidor
    Servidor(int id_dono_servidor, std::string nome, std::string descricao, std::string codigo_convite); // Construtor da classe Servidor

    void set_id_dono_servidor(int id_dono_servidor); // Seta o ID do dono do servidor
    int get_id_dono_servidor(); // Retorna o ID do dono do servidor

    void set_nome(std::string nome); // Seta o nome do servidor
    std::string get_nome(); // Retorna o nome do servidor

    void set_descricao(std::string descricao); // Seta a descrição do servidor
    std::string get_descricao(); // Retorna a descrição do servidor

    void set_codigo_convite(std::string codigo_convite); // Seta o código de convite do servidor
    std::string get_codigo_convite(); // Retorna o código de convite do servidor

    void set_vec_canais(std::vector<Canal> vec_canais); // Seta o vetor de canais do servidor
    std::vector<Canal> get_vec_canais(); // Retorna o vetor de canais do servidor
    int get_vec_canais_size(); // Retorna o tamanho do vetor de canais do servidor

    void set_vec_canais_texto(std::vector<CanalTexto> vec_canais_texto); // Seta o vetor de canais de texto do servidor
    std::vector<CanalTexto> get_vec_canais_texto(); // Retorna o vetor de canais de texto do servidor
    int get_vec_canais_texto_size();

    void set_vec_canais_voz(std::vector<CanalVoz> vec_canais_voz); // Seta o vetor de canais de voz do servidor
    std::vector<CanalVoz> get_vec_canais_voz(); // Retorna o vetor de canais de voz do servidor
    int get_vec_canais_voz_size();

    void set_vec_usuarios_ids(std::vector<int> vec_usuarios_ids); // Seta o vetor de IDs dos usuários que participam do servidor
    std::vector<int> get_vec_usuarios_ids(); // Retorna o vetor de IDs dos usuários que participam do servidor

    void adicionar_participante(int id_usuario); // Adiciona um participante ao servidor
    void criar_canal_texto(CanalTexto canaltxt); // Cria um canal de texto no servidor
    void criar_canal_voz(CanalVoz canalvoz); // Cria um canal de voz no servidor
    void adicionar_msg_txt(Mensagem msg, std::string atual); // Adiciona uma mensagem de texto a um canal de texto
    void adicionar_msg_voz(Mensagem msg, std::string atual); // Adiciona uma mensagem de voz a um canal de voz
};
#endif