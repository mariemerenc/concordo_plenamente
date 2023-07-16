#include <iostream>
#include <vector>
#include <string>
#include "exec.h"

Executor::Executor(Sistema *sistema) {
    this->sistema = sistema;
    this->sair = false;
}

void Executor::executar() {
    sistema->carregar();
    while (this->sair != true) {
        std::string comando;
        std::getline(std::cin, comando);
        std::cout << ler_comando(comando, sistema) << std::endl;
    }
}

std::string Executor::ler_comando(std::string comando, Sistema *sist) {
    std::string linha;

    for(auto caracter : comando){
        if(caracter == ' '){
            break;
        }
        linha += caracter;
    }

    int c = 0;
    std::string restante = "";

    for(auto caracter : comando){
        if(c == 1){
            restante += caracter;
        }
        if(caracter == ' '){
            c=1;
        }
    }

    if(linha == "help"){
        return "Comandos disponíveis:\n" 
        "help\n" 
        "quit\n" 
        "create-user <email> <senha_sem_espaço> <nome com espaço>\n" 
        "login <email> <senha>\n" 
        "disconnect\n" 
        "create-server <nome>\n" 
        "set-server-desc <nome> <descricao>\n" 
        "set-server-invite-code <nome> <codigo>\n" 
        "list-servers\n" 
        "remove-server <nome>\n" 
        "enter-server <nome> <codigo>\n" 
        "list-participants\n" 
        "list-channels\n" 
        "create-channel <nome> <tipo>\n" 
        "enter-channel <nome>\n" 
        "leave-channel\n" 
        "send-message <mensagem>\n" 
        "list-messages\n";
    }

    else if(linha == "quit"){
        this->sair = true;
        return sistema->sair();
    }

    else if(linha == "create-user"){
        std::string email;
        std::string senha;
        std::string nome;
        int i=0;

        for(auto caracter : restante){
            if(caracter == ' '){
                i++;
                continue;
            }
            if(i == 0){
                email += caracter;
            }
            else if(i == 1){
                senha += caracter;
            }
            else if(i == 2){
                nome += caracter;
            }
        }
        return sistema->criar_usuario(email, senha, nome);
    }

    else if(linha == "login"){
        std::string email;
        std::string senha;
        int i=0;

        for(auto caracter : restante){
            if(caracter == ' '){
                i++;
                continue;
            }
            if(i == 0){
                email += caracter;
            }
            else if(i == 1){
                senha += caracter;
            }
        }
        return sistema->login(email, senha);
    }

    else if(linha == "disconnect"){
        return sistema->deslogar();
    }

    else if(linha == "create-server"){
        return sistema->criar_servidor(restante);
    }

    else if(linha == "set-server-desc"){
        std::string nome;
        std::string descricao;
        int i=0;

        for(auto caracter : restante){
            if(caracter == ' '){
                i++;
                continue;
            }
            if(i == 0){
                nome += caracter;
            }
            else if(i == 1){
                descricao += caracter;
            }
        }
        return sistema->set_descricao_servidor(nome, descricao);
    }

    else if(linha == "set-server-invite-code"){
        std::string nome;
        std::string codigo;
        int i=0;

        for(auto caracter : restante){
            if(caracter == ' '){
                i++;
                continue;
            }
            if(i == 0){
                nome += caracter;
            }
            else if(i == 1){
                codigo += caracter;
            }
        }
        return sistema->set_codigo_convite(nome, codigo);
    }

    else if(linha == "list-servers"){
        return sistema->listar_servidores();
    }

    else if(linha == "remove-server"){
        return sistema->remover_servidor(restante);
    }

    else if(linha == "enter-server"){
        std::string nome;
        std::string codigo;
        int i=0;

        for(auto caracter : restante){
            if(caracter == ' '){
                i++;
                continue;
            }
            if(i == 0){
                nome += caracter;
            }
            else if(i == 1){
                codigo += caracter;
            }
        }
        return sistema->entrar_servidor(nome, codigo);

    }  

    else if(linha == "list-participants"){
        return sistema->listar_participantes();
    }

    else if(linha == "list-channels"){
        return sistema->listar_canais();
    }

    else if(linha == "create-channel"){
        std::string nome;
        std::string tipo;
        int i=0;

        for(auto caracter : restante){
            if(caracter == ' '){
                i++;
                continue;
            }
            if(i == 0){
                nome += caracter;
            }
            else if(i == 1){
                tipo += caracter;
            }
        }
        return sistema->criar_canal(nome, tipo);
    }

    else if(linha == "enter-channel"){
        return sistema->entrar_canal(restante);
    }

    else if(linha == "leave-channel"){
        return sistema->sair_canal();
    }

    else if(linha == "send-message"){
        return sistema->enviar_mensagem(restante);
    }

    else if(linha == "list-messages"){
        return sistema->listar_mensagens();
    }

    else{
        return "Comando inválido";
    }

}