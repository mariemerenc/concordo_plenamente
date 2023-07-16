/**
 * @file sistema.cpp
 * 
 * @brief Implementação da classe Sistema
 * 
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include "sistema.h"
#include "usuario.h"

/**
 * @brief 
 * 
 */
void Sistema::acrescentar_id(){
    this->ultimo_id_gerado++;
}

/**
 * @brief 
 * 
 * @param ultimo_id_gerado 
 */
void Sistema::set_ultimo_id_gerado(int ultimo_id_gerado){
    this->ultimo_id_gerado = ultimo_id_gerado;
}

/**
 * @brief 
 * 
 * @return int 
 */
int Sistema::get_ultimo_id_gerado(){
    return this->ultimo_id_gerado;
}

/**
 * @brief 
 * 
 * @return int
 */
int Sistema::get_usuarios(){
    return this->vec_usuarios_cadastrados.size();
}

/**
 * @brief 
 * 
 * @return int
 */
int Sistema::get_servidores(){
    return this->vec_servidores_cadastrados.size();
}

/**
 * @brief 
 * 
 * @return std::string
 */
std::string Sistema::get_usuario_cadastrado(int id_usuario){
    for(auto i{0}; i < get_usuarios(); i++){
        if(vec_usuarios_cadastrados[i].get_id() == id_usuario){
            return vec_usuarios_cadastrados[i].get_nome();
        }
    }
}



std::string Sistema::verificar_login(int id_usuario_log){
    if(id_usuario_log == -1){
        return "Usuário não logado";
    }
    
    return "";
}

std::string Sistema::sair(){
    if(this->usuario_logado_id == -1){
        return "Não há usuário logado";
    }
    usuario_logado_id = -1;
    servidor_atual = "";
    canal_atual = "";
    
    return "Saindo...";
}

 
std::string Sistema::login(std::string email, std::string senha){
    if(this->usuario_logado_id != -1){
        return "Usuário já está logado";
    }
    
    for(auto i{0}; i < get_usuarios(); i++){
        if(vec_usuarios_cadastrados[i].get_email() == email){
            if(vec_usuarios_cadastrados[i].get_senha() == senha){
                this->usuario_logado_id = vec_usuarios_cadastrados[i].get_id();
                return "Logado como " + vec_usuarios_cadastrados[i].get_nome();
            }
            else{
                return "Senha incorreta";
            }
        }
    }
    
    return "Usuário não cadastrado";
}


std::string Sistema::deslogar(){
    if(this->usuario_logado_id == -1){
        return "Não há usuário logado";
    }
    
    usuario_logado_id = -1;
    return "Deslogado!";
}

std::string Sistema::criar_usuario(const std::string email, const std::string senha, const std::string nome){
    verificar_login(usuario_logado_id);
    
    if(email == "" || senha == "" || nome == ""){
        return "Dados inválidos. Tente novamente";
    }

    for(auto i{0}; i < get_usuarios(); i++){
        if(vec_usuarios_cadastrados[i].get_email() == email){
            return "Usuário já existe";
        }
    }

    if(get_usuarios == 0){
        set_ultimo_id_gerado(0);
    }

    acrescentar_id();

    Usuario novo_usuario(get_ultimo_id_gerado(), email, senha, nome);
    vec_usuarios_cadastrados.push_back(novo_usuario);
    salvar();
    
    return "Usuário criado!";
}

std::string Sistema::criar_servidor(std::string nome){
    verificar_login(usuario_logado_id);
    
    if(nome == ""){
        return "Dados inválidos. Tente novamente";
    }

    for(auto i{0}; i < get_servidores(); i++){
        if(vec_servidores_cadastrados[i].get_nome() == nome){
            return "Servidor já existe";
        }
    }

    if(get_servidores == 0){
        set_ultimo_id_gerado(0);
    }

    Servidor novo_servidor(usuario_logado_id, nome, "", "");
    vec_servidores_cadastrados.push_back(novo_servidor);
    salvar();
    
    return "Servidor criado!";
}

std::string Sistema::set_descricao_servidor(std::string nome, std::string descricao){
    verificar_login(usuario_logado_id);
  
    for(auto i{0}; i < get_servidores(); i++){
        if(vec_servidores_cadastrados[i].get_nome() == nome){
            if(vec_servidores_cadastrados[i].get_id_dono_servidor() == usuario_logado_id){
                vec_servidores_cadastrados[i].set_descricao(descricao);
                salvar();
                return "Descrição do servidor " + nome + " modificada!";
            }
            else{
                return "Você não é dono desse servidor";
            }
        }
    }
    
    return "Servidor não existe";
}

std::string Sistema::set_codigo_convite(std::string nome, std::string codigo){
    verificar_login(usuario_logado_id);
    
    for(auto i{0}; i < get_servidores(); i++){
        if(vec_servidores_cadastrados[i].get_nome() == nome){
            if(vec_servidores_cadastrados[i].get_id_dono_servidor() == usuario_logado_id){
                vec_servidores_cadastrados[i].set_codigo_convite(codigo);
                salvar();
                return "Código de convite do servidor " + nome + " modificado!";
            }
            else{
                return "Você não é dono desse servidor";
            }
        }
    }
    
    return "Servidor não existe";
}

std::string Sistema::entrar_servidor(std::string nome, std::string codigo){
    verificar_login(usuario_logado_id);
    
    for(auto i{0}; i < get_servidores(); i++){
        if(vec_servidores_cadastrados[i].get_nome() == nome){
            if(vec_servidores_cadastrados[i].get_id_dono_servidor() == usuario_logado_id){
                servidor_atual = nome;
                vec_servidores_cadastrados[i].adicionar_participante(usuario_logado_id);
                salvar();
                return "Entrou no servidor " + nome + "!";
            }

            if(vec_servidores_cadastrados[i].get_codigo_convite() == codigo){
                for(auto j{0}; j < get_usuarios(); j++){
                    if(vec_usuarios_cadastrados[j].get_id() == usuario_logado_id){
                        return "Você já está no servidor " + nome;
                    }
                }
                servidor_atual = nome;
                vec_servidores_cadastrados[i].adicionar_participante(usuario_logado_id);
                salvar();
                return "Entrou no servidor " + nome + "!";
            }
            else{
                return "Código de convite inválido";
            }
        }
    }
    
    return "Servidor não existe";
}

std::string Sistema::listar_participantes(){
    verificar_login(usuario_logado_id);
    
    for(auto i{0}; i < get_servidores(); i++){
        if(vec_servidores_cadastrados[i].get_nome() == servidor_atual){
            std::string lista = "";
            for(auto j{0}; j < vec_servidores_cadastrados[i].get_vec_usuarios_ids(); j++){
                for(auto k{0}; k < get_usuarios(); k++){
                    if(vec_usuarios_cadastrados[k].get_id() == vec_servidores_cadastrados[i].get_vec_usuarios_ids()[j]){
                        if(k == get_usuarios() - 1){
                            lista += vec_usuarios_cadastrados[k].get_nome() + "\n";
                            break;
                        }
                    }
                    lista += vec_usuarios_cadastrados[k].get_nome() + "\n";
                }
            }
            if (lista != ""){
                return lista;
            }
            
            return "Não há participantes";
        }
    }
    
    return "Servidor não existe";
}


std::string Sistema::listar_canais(){
    verificar_login(usuario_logado_id);
    
    for(auto i{0}; i < get_servidores(); i++){
        if(vec_servidores_cadastrados[i].get_nome() == servidor_atual){
            std::string lista = "";
            for(auto j{0}; j < vec_servidores_cadastrados[i].get_vec_canais_size(); j++){
                lista += vec_servidores_cadastrados[i].get_vec_canais()[j].get_nome() + "\n";
            }

            return lista;
        }
    }
    return "Servidor não existe";
}


std::string Sistema::criar_canal(std::string nome, std::string tipo){
    verificar_login(usuario_logado_id);
    
    for(auto i{0}; i < get_servidores(); i++){
        if(vec_servidores_cadastrados[i].get_nome() == servidor_atual){
            if(tipo == "texto"){
                CanalTexto novo_canal(nome);
                vec_servidores_cadastrados[i].criar_canal_texto(novo_canal);
                salvar();
                return "Canal " + nome + " criado!";
            }
            else if(tipo == "voz"){
                CanalVoz novo_canal(nome);
                vec_servidores_cadastrados[i].criar_canal_voz(novo_canal);
                salvar();
                return "Canal " + nome + " criado!";
            }
            else{
                return "Tipo de canal inválido";
            }
        }
    }
    
    return "Servidor não existe";

}

std::string Sistema::entrar_canal(std::string nome){
    verificar_login(usuario_logado_id);
    
    for(auto i{0}; i < get_servidores(); i++){
        if(vec_servidores_cadastrados[i].get_nome() == servidor_atual){
            for(auto j{0}; j < vec_servidores_cadastrados[i].get_vec_canais_size(); j++){
                if(vec_servidores_cadastrados[i].get_vec_canais()[j].get_nome() == nome){
                    canal_atual = nome;
                    salvar();
                    return "Entrou no canal " + nome + "!";
                }
            }
            return "Canal não existe";
        }
    }
    
    return "Servidor não existe";
}

std::string Sistema::enviar_mensagem(std::string mensagem){
    verificar_login(usuario_logado_id);
    
    if(canal_atual == ""){
        return "Canal não existe";
    }

    if(servidor_atual == ""){
        return "Servidor não existe";
    }

    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);
    std::string dh = "<" + std::to_string(data_hora_atual->tm_mday) + "/" + std::to_string(data_hora_atual->tm_mon + 1) + "/" + std::to_string(data_hora_atual->tm_year + 1900) + " " + std::to_string(data_hora_atual->tm_hour) + ":" + std::to_string(data_hora_atual->tm_min) + ":" + std::to_string(data_hora_atual->tm_sec) + ">";
    Mensagem nova_mensagem(usuario_logado_id, dh, mensagem);

    for(auto i{0}; i < get_servidores(); i++){
        if(vec_servidores_cadastrados[i].get_nome() == servidor_atual){
            for(auto j{0}; j < vec_servidores_cadastrados[i].get_vec_canais_size(); j++){
                if(vec_servidores_cadastrados[i].get_vec_canais_voz()[j].get_nome() == canal_atual){
                    vec_servidores_cadastrados[i].adicionar_msg_voz(nova_mensagem, canal_atual);
                    salvar();
                    return "Mensagem enviada!";
                }
                else if(vec_servidores_cadastrados[i].get_vec_canais_texto()[j].get_nome() == canal_atual){
                    vec_servidores_cadastrados[i].adicionar_msg_txt(nova_mensagem, canal_atual);
                    salvar();
                    return "Mensagem enviada!";
                }
            }
        }
    }
    return "";
}   

std::string Sistema::listar_mensagens(){
    verificar_login(usuario_logado_id);
    
    if(canal_atual == ""){
        return "Canal não existe";
    }

    if(servidor_atual == ""){
        return "Servidor não existe";
    }

    for(auto i{0}; i < get_servidores(); i++){
        if(vec_servidores_cadastrados[i].get_nome() == servidor_atual){
            for(auto j{0}; j < vec_servidores_cadastrados[i].get_vec_canais_size(); j++){
                if(vec_servidores_cadastrados[i].get_vec_canais_voz()[j].get_nome() == canal_atual){
                    std::string lista = "";
                    lista += vec_servidores_cadastrados[i].get_vec_canais_voz()[j].get_ultima_mensagem().get_autor_id() + "\n";
                    if(lista == "" || lista == ": ")
                        return "Não há mensagens";

                    return lista;
                }

                if(vec_servidores_cadastrados[i].get_vec_canais_texto()[j].get_nome() == canal_atual){
                    std::string lista = "";
                    for(auto k{0}; k < vec_servidores_cadastrados[i].get_vec_canais_texto()[j].get_mensagens_size(); k++){
                        if(k == vec_servidores_cadastrados[i].get_vec_canais_texto()[j].get_mensagens_size() - 1){
                            lista += vec_servidores_cadastrados[i].get_vec_canais_texto()[j].get_mensagens()[k].get_autor_id() + ": " + vec_servidores_cadastrados[i].get_vec_canais_texto()[j].get_mensagens()[k].get_data_hora() + " " + vec_servidores_cadastrados[i].get_vec_canais_texto()[j].get_mensagens()[k].get_conteudo();
                            break;
                        }
                        lista += vec_servidores_cadastrados[i].get_vec_canais_texto()[j].get_mensagens()[k].get_autor_id() + ": " + vec_servidores_cadastrados[i].get_vec_canais_texto()[j].get_mensagens()[k].get_data_hora() + " " + vec_servidores_cadastrados[i].get_vec_canais_texto()[j].get_mensagens()[k].get_conteudo() + "\n";
                        
                    }
                    if(lista == "" || lista == ": ")
                        return "Não há mensagens";


                    return lista;
            
                }
            }
        }
    }
    return "";
}

std::string Sistema::sair_canal(){
    verificar_login(usuario_logado_id);
    
    if(canal_atual == ""){
        return "Canal não existe";
    }

    if(servidor_atual == ""){
        return "Servidor não existe";
    }

    canal_atual = "";
    salvar();
    return "Saiu do canal";
}


void Sistema::carregar_usuarios(){
    std::ifstream arquivo_usuarios;
    arquivo_usuarios.open("usuarios.txt");
    int usuariostam;
    arquivo_usuarios >> usuariostam;

    if(usuariostam == 0){
        arquivo_usuarios.close();
        return;
    }

    int id;
    std::string email, nome, senha;

    while(arquivo_usuarios >> id){
        arquivo_usuarios.ignore();
        std::getline(arquivo_usuarios, nome);
        std::getline(arquivo_usuarios, email);
        std::getline(arquivo_usuarios, senha);
        Usuario novo_usuario(id, email, senha, nome);
        vec_usuarios_cadastrados.push_back(novo_usuario);
        set_ultimo_id_gerado(id);
    }
    arquivo_usuarios.close();
}

void Sistema::carregar_servidores(){
    std::ifstream arquivo_servidores;
    arquivo_servidores.open("servidores.txt");
    int servidorestam;
    arquivo_servidores >> servidorestam;

    if(servidorestam == 0){
        arquivo_servidores.close();
        return;
    }

    int autor_id, canais_tam, mensagens_tam, usuarios;
    std::string nome, descricao, codigo_convite, nome_canal, tipo, conteudo, dh;

    while(arquivo_servidores >> autor_id){
        arquivo_servidores.ignore();
        std::getline(arquivo_servidores, nome);
        std::getline(arquivo_servidores, descricao);
        std::getline(arquivo_servidores, codigo_convite);

        arquivo_servidores >> usuarios;
        arquivo_servidores.ignore();
        Servidor novo_servidor(autor_id, nome, descricao, codigo_convite);
        std::vector<int> usuarios_id;
        for(auto i{0}; i < usuarios; i++){
            int id;
            arquivo_servidores >> id;
            novo_servidor.adicionar_participante(id);
        }
        arquivo_servidores >> canais_tam;
        arquivo_servidores.ignore();

        for(auto i{0}; i < canais_tam; i++){
            std::getline(arquivo_servidores, nome_canal);
            std::getline(arquivo_servidores, tipo);
            arquivo_servidores >> mensagens_tam;
            arquivo_servidores.ignore();

            if(tipo == "TEXTO"){
                CanalTexto novo_canal(nome_canal);
                for(auto j{0}; j < mensagens_tam; j++){
                    int autor_id;
                    arquivo_servidores >> autor_id;
                    arquivo_servidores.ignore();
                    std::getline(arquivo_servidores, dh);
                    std::getline(arquivo_servidores, conteudo);

                    Mensagem nova_mensagem(autor_id, dh, conteudo);
                    novo_canal.enviar_mensagem(nova_mensagem);
                }
                novo_servidor.criar_canal_texto(novo_canal);
            }
            else if(tipo == "VOZ"){
                int autor_id;
                arquivo_servidores >> autor_id;
                arquivo_servidores.ignore();
               
                std::getline(arquivo_servidores, dh);
                std::getline(arquivo_servidores, conteudo);
                
                Mensagem nova_mensagem(autor_id, dh, conteudo);
                CanalVoz novo_canal(nome_canal);
                novo_canal.set_ultima_mensagem(nova_mensagem);
                novo_servidor.criar_canal_voz(novo_canal);
            }
            
        }
        vec_servidores_cadastrados.push_back(novo_servidor);
    }
    arquivo_servidores.close();
}

void Sistema::carregar(){
    carregar_usuarios();
    carregar_servidores();
}

