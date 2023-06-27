#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <iomanip>
#include <ctime>
#include <chrono>
#include "system.h"

using std::chrono::system_clock;
struct tm * tempoAtual(){
    std::time_t tempo = system_clock::to_time_t(system_clock::now());
    return std::localtime(&tempo);
}

std::string Sistema::sair(){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        usuarioLogadoId = 0;
        nomeServidorConectado = "";
        nomeCanalConectado = "";
        tipoCanalConectado = "";
        return "Saindo do Discord...";
    }
}

std::string Sistema::criarUsuario(const std::string email, const std::string senha, const std::string nome){
    if(usuarioLogadoId != 0){
        return "Um usuário já está logado no momento";
    }
    else{
        if(std::find(vecEmails.begin(), vecEmails.end(), email) != vecEmails.end()){
            return "Usuário já existe";
        }
        else{
            User user;
            user.setEmail(email);
            user.setSenha(senha);
            user.setNome(nome);
            user.setId(vecIds.size()+1);
            vecUser.push_back(user);
            vecEmails.push_back(email);
            vecSenhas.push_back(senha);
            vecIds.push_back(vecIds.size()+1);
            return "Usuário criado";
        }
    }
}

std::string Sistema::logar(const std::string email, const std::string senha){
    if(usuarioLogadoId != 0){
        return "Um usuário já está logado no momento";
    }
    else{
        if(std::find(vecEmails.begin(), vecEmails.end(), email) != vecEmails.end()){
            if(std::find(vecSenhas.begin(), vecSenhas.end(), senha) != vecSenhas.end()){
                usuarioLogadoId = std::find(vecEmails.begin(), vecEmails.end(), email) - vecEmails.begin() + 1;
                return "Usuário logado com sucesso";
            }
            else{
                return "Senha incorreta";
            }
        }
        else{
            return "Usuário não existe";
        }
    }
    return "";
}

std::string Sistema::desconectar(){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        usuarioLogadoId = 0;
        nomeServidorConectado = "";
        nomeCanalConectado = "";
        tipoCanalConectado = "";
        return "Usuário desconectado";
    }
    return "";
}

std::string Sistema::criarServidor(const std::string nome){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        if(std::find(vecNomes.begin(), vecNomes.end(), nome) != vecNomes.end()){
            return "Servidor já existe";
        }
        else{
            Servidor servidor;
            servidor.setNome(nome);
            servidor.setDono(usuarioLogadoId);
            servidor.setId(vecServidores.size()+1);
            vecServidores.push_back(servidor);
            vecNomes.push_back(nome);
            vecDescricoes.push_back("");
            vec3.push_back(0);
            vec2.push_back("");
            vec.push_back(0);
            return "Servidor criado";
        }
    }
    return "";
}

std::string Sistema::setServidorDescricao(const std::string nome, const std::string descricao){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        if(std::find(vecNomes.begin(), vecNomes.end(), nome) != vecNomes.end()){
            if(usuarioLogadoId == vecServidores[std::find(vecNomes.begin(), vecNomes.end(), nome) - vecNomes.begin()].getDono()){
                vecDescricoes[std::find(vecNomes.begin(), vecNomes.end(), nome) - vecNomes.begin()] = descricao;
                return "Descrição do servidor " + nome + " modificada!";
            }
            else{
                return "Você não é o dono do servidor";
            }
        }
        else{
            return "Servidor não existe";
        }
    }
    return "";
}

std::string Sistema::setServidorCodigoConvite(const std::string nome, const std::string codigo){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        if(std::find(vecNomes.begin(), vecNomes.end(), nome) != vecNomes.end()){
            if(usuarioLogadoId == vecServidores[std::find(vecNomes.begin(), vecNomes.end(), nome) - vecNomes.begin()].getDono()){
                vec2[std::find(vecNomes.begin(), vecNomes.end(), nome) - vecNomes.begin()] = codigo;
                return "Código de convite do servidor " + nome + " modificado!";
            }
            else{
                return "Você não é o dono do servidor";
            }
        }
        else{
            return "Servidor não existe";
        }
    }
    return "";
}

std::string Sistema::listarServidores(){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        std::string lista = "";
        for(int i = 0; i < vecServidores.size(); i++){
            lista += vecServidores[i].getNome() + " " + vecDescricoes[i] + "\n";
        }
        return lista;
    }
    return "";
}

std::string Sistema::entrarServidor(const std::string nome, const std::string codigo){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        if(std::find(vecNomes.begin(), vecNomes.end(), nome) != vecNomes.end()){
            if(codigo == vec2[std::find(vecNomes.begin(), vecNomes.end(), nome) - vecNomes.begin()]){
                nomeServidorConectado = nome;
                return "Entrou no servidor " + nome;
            }
            else{
                return "Código de convite inválido";
            }
        }
        else{
            return "Servidor não existe";
        }
    }
    return "";
}

std::string Sistema::removerServidor(const std::string nome){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        for(int i = 0; i < vecServidores.size(); i++){
            if(nome == vecServidores[i].getNome()){
                for(int j = 0; j < vecServidores.size(); ++j){
                    if(vecIds[j] != usuarioLogadoId){
                        return "Você não é o dono do servidor";
                    }
                
                vecServidores.erase(vecServidores.begin() + i);
                vecNomes.erase(vecNomes.begin() + i);
                vecDescricoes.erase(vecDescricoes.begin() + i);
                vecServidorId.erase(vecServidorId.begin() + i);
                vecServidorCodigoConvite.erase(vecServidorCodigoConvite.begin() + i);
                return "Servidor " + nome + " removido";
                }
            }
        }
    }
    return "Servidor '" + nome + "' não existe";
}

std::string Sistema::sairServidor(){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        if(nomeServidorConectado == ""){
            return "Não há servidor conectado no momento";
        }
        else{
            nomeServidorConectado = "";
            nomeCanalConectado = "";
            tipoCanalConectado = "";
            return "Saindo do servidor";
        }
    }
    return "";
}

std::string Sistema::listarCanais(){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        if(nomeServidorConectado == ""){
            return "Não há servidor conectado no momento";
        }
        else{
            std::string lista = "";
            for(int i = 0; i < vecCanais.size(); i++){
                lista += vecCanais[i].getNome() + "\n";
            }
            return lista;
        }
    }
    return "";
}

std::string Sistema::listarParticipantes(){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        if(nomeServidorConectado == ""){
            return "Não há servidor conectado no momento";
        }
        else{
            std::string lista = "";
            for(int i = 0; i < vecUsuarios.size(); i++){
                lista += vecUsuarios[i].getNome() + "\n";
            }
            return lista;
        }
    }
    return "";
}

std::string Sistema::criarCanal(const std::string nome, const std::string tipo){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        if(nomeServidorConectado == ""){
            return "Não há servidor conectado no momento";
        }
        else{
            if(tipo == "texto"){
                CanalTexto vecCanaisTexto(nome);
                vecCanais.push_back(canalTexto);
                vecNomesCanaisTexto.push_back(nome);
                return "Canal de texto " + nome + " criado";
            }
            else if(tipo == "voz"){
                CanalVoz canalVoz(nome);
                vecCanais.push_back(canalVoz);
                vecNomesCanaisVoz.push_back(nome);
                return "Canal de voz " + nome + " criado";
            }
            else{
                return "Tipo de canal inválido";
            }
        }
    }
    return "";
}

std::string Sistema::entrarCanal(const std::string nome){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        if(nomeServidorConectado == ""){
            return "Não há servidor conectado no momento";
        }
        else{
            if(std::find(vecNomesCanaisTexto.begin(), vecNomesCanaisTexto.end(), nome) != vecNomesCanaisTexto.end()){
                nomeCanalConectado = nome;
                tipoCanalConectado = "texto";
                return "Entrou no canal " + nome;
            }
            else if(std::find(vecNomesCanaisVoz.begin(), vecNomesCanaisVoz.end(), nome) != vecNomesCanaisVoz.end()){
                nomeCanalConectado = nome;
                tipoCanalConectado = "voz";
                return "Entrou no canal " + nome;
            }
            else{
                return "Canal não existe";
            }
        }
    }
    return "";
}

std::string Sistema::sairCanal(){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        if(nomeServidorConectado == ""){
            return "Não há servidor conectado no momento";
        }
        else{
            if(nomeCanalConectado == ""){
                return "Não há canal conectado no momento";
            }
            else{
                nomeCanalConectado = "";
                tipoCanalConectado = "";
                return "Saindo do canal";
            }
        }
    }
    return "";
}

//escreva uma função de mandar mensagem que recebe o conteúdo da mensagem e retorna o nome do usuário que enviou a mensagem, a data e a hora da mensagem e também o conteúdo da mensagem
std::string Sistema::enviarMensagem(const std::string mensagem){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        if(nomeServidorConectado == ""){
            return "Não há servidor conectado no momento";
        }
        else{
            if(nomeCanalConectado == ""){
                return "Não há canal conectado no momento";
            }
            else{
                if(tipoCanalConectado == "texto"){
                    Mensagem msg;
                    msg.setConteudo(mensagem);
                    vecMensagens.push_back(msg);
                    return "Mensagem enviada";
                }
                else{
                    return "Canal conectado não é de texto";
                }
            }
        }
    }
    return "";
}

std::string Sistema::listarMensagens(){
    if(usuarioLogadoId == 0){
        return "Não há usuário logado no momento";
    }
    else{
        if(nomeServidorConectado == ""){
            return "Não há servidor conectado no momento";
        }
        else{
            if(nomeCanalConectado == ""){
                return "Não há canal conectado no momento";
            }
            else{
                if(tipoCanalConectado == "texto"){
                    std::string lista = "";
                    Mensagem msg;
                    for(int i = 0; i < vecMensagens.size(); i++){
                        lista += vecMensagens[i].getConteudo() + "\n";
                    }
                    return lista;
                }
                else{
                    return "Canal conectado não é de texto";
                }
            }
        }
    }
    return "";
}

void Sistema::salvarUsuarios(){
    std::ofstream arquivoUsuarios("usuarios.txt");
    if(arquivoUsuarios.is_open()){
        for(int i = 0; i < vecUsuarios.size(); i++){
            arquivoUsuarios << vecUsuarios[i].getNome() << "\n";
            arquivoUsuarios << vecUsuarios[i].getEmail() << "\n";
            arquivoUsuarios << vecUsuarios[i].getSenha() << "\n";
        }
        arquivoUsuarios.close();
    }
    else{
        std::cout << "Não foi possível abrir o arquivo de usuários" << std::endl;
    }
}

void Sistema::salvarServidores(){
    std::ofstream arquivoServidores("servidores.txt");
    if(arquivoServidores.is_open()){
        for(int i = 0; i < vecServidores.size(); i++){
            arquivoServidores << vecServidores[i].getNome() << "\n";
            arquivoServidores << vecServidores[i].getDescricao() << "\n";
            arquivoServidores << vecServidores[i].getUsuarioDonoId() << "\n";
        }
        arquivoServidores.close();
    }
    else{
        std::cout << "Não foi possível abrir o arquivo de servidores" << std::endl;
    }
}

void Sistema::salvar(){
    salvarUsuarios();
    salvarServidores();
}









