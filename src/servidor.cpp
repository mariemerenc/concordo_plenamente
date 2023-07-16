#include <iostream>
#include <vector>
#include "canal.h"
#include "canalTexto.h"
#include "canalVoz.h"
#include "servidor.h"

Servidor::Servidor() {
    this->id_dono_servidor = 0;
    this->nome = "";
    this->descricao = "";
    this->codigo_convite = "";
}

Servidor::Servidor(int id_dono_servidor, std::string nome, std::string descricao, std::string codigo_convite) {
    this->id_dono_servidor = id_dono_servidor;
    this->nome = nome;
    this->descricao = descricao;
    this->codigo_convite = codigo_convite;
}

void Servidor::set_id_dono_servidor(int id_dono_servidor) {
    this->id_dono_servidor = id_dono_servidor;
}

int Servidor::get_id_dono_servidor() {
    return this->id_dono_servidor;
}

void Servidor::set_nome(std::string nome) {
    this->nome = nome;
}

std::string Servidor::get_nome() {
    return this->nome;
}

void Servidor::set_descricao(std::string descricao) {
    this->descricao = descricao;
}

std::string Servidor::get_descricao() {
    return this->descricao;
}

void Servidor::set_codigo_convite(std::string codigo_convite) {
    this->codigo_convite = codigo_convite;
}

std::string Servidor::get_codigo_convite() {
    return this->codigo_convite;
}

void Servidor::set_vec_canais(std::vector<Canal> vec_canais) {
    this->vec_canais = vec_canais;
}

std::vector<Canal> Servidor::get_vec_canais() {
    return this->vec_canais;
}

int Servidor::get_vec_canais_size() {
    return this->vec_canais.size();
}

void Servidor::set_vec_canais_texto(std::vector<CanalTexto> vec_canais_texto) {
    this->vec_canais_texto = vec_canais_texto;
}

std::vector<CanalTexto> Servidor::get_vec_canais_texto() {
    return this->vec_canais_texto;
}

int Servidor::get_vec_canais_texto_size() {
    return this->vec_canais_texto.size();
}

void Servidor::set_vec_canais_voz(std::vector<CanalVoz> vec_canais_voz) {
    this->vec_canais_voz = vec_canais_voz;
}

std::vector<CanalVoz> Servidor::get_vec_canais_voz() {
    return this->vec_canais_voz;
}

int Servidor::get_vec_canais_voz_size() {
    return this->vec_canais_voz.size();
}

void Servidor::set_vec_usuarios_ids(std::vector<int> vec_usuarios_ids) {
    this->vec_usuarios_ids = vec_usuarios_ids;
}

std::vector<int> Servidor::get_vec_usuarios_ids() {
    return this->vec_usuarios_ids;
}

void Servidor::adicionar_participante(int id_usuario) {
    this->vec_usuarios_ids.push_back(id_usuario);
}

void Servidor::criar_canal_texto(CanalTexto canaltxt) {
    this->vec_canais.push_back(canaltxt);
    this->vec_canais_texto.push_back(canaltxt);
}

void Servidor::criar_canal_voz(CanalVoz canalvoz) {
    this->vec_canais.push_back(canalvoz);
    this->vec_canais_voz.push_back(canalvoz);
}

void Servidor::adicionar_msg_txt(Mensagem msg, std::string atual){
    for (int i = 0; i < this->vec_canais_texto.size(); i++){
        if (this->vec_canais_texto[i].get_nome() == atual){
            this->vec_canais_texto[i].enviar_mensagem(msg);
        }
    }
}

void Servidor::adicionar_msg_voz(Mensagem msg, std::string atual){
    for (int i = 0; i < this->vec_canais_voz.size(); i++){
        if (this->vec_canais_voz[i].get_nome() == atual){
            this->vec_canais_voz[i].set_ultima_mensagem(msg);
        }
    }
}