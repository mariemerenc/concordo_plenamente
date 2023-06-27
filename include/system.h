#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include "user.h"
#include "server.h"
#include "channel.h"
#include "chtext.h"
#include "chvoice.h"


class Sistema{
    std::vector<User> vecUsuarios;
    std::vector<std::string> vecEmails;
    std::vector<std::string> vecSenhas;
    std::vector<int> vecIds;
    std::vector<Servidor> vecServidores;
    std::vector<std::string> vecNomes;
    std::vector<std::string> vecDescricoes;
    std::vector<int> vecServidorId; //nsei antigo 3
    std::vector<std::string> vecServidorCodigoConvite;//nsei antigo 2
    std::vector<int> vecDesconheco; //nsei
    std::vector<Canal> vecCanais;
    std::vector<std::string> vecNomesCanais;
    std::vector<CanalVoz> vecCanaisVoz;
    std::vector<std::string> vecNomesCanaisVoz;
    std::vector<CanalTexto> vecCanaisTexto;
    std::vector<std::string> vecNomesCanaisTexto;
    int usuarioLogadoId = 0;
    std::string nomeServidorConectado = "";
    std::string nomeCanalConectado;
    std::string tipoCanalConectado;
    std::vector<Mensagem> vecMensagens;

    public:
    std::string sair();
    std::string criarUsuario(const std::string email, const std::string senha, const std::string nome);
    std::string logar(const std::string email, const std::string senha);
    std::string desconectar();
    std::string criarServidor(const std::string nome);
    std::string setServidorDescricao(const std::string nome, const std::string descricao);
    std::string setServidorCodigoConvite(const std::string nome, const std::string codigo);
    std::string listarServidores();
    std::string removerServidor(const std::string nome);
    std::string entrarServidor(const std::string nome, const std::string codigo);
    std::string sairServidor();
    std::string listarParticipantes();
    std::string listarCanais();
    std::string criarCanal(const std::string nome, const std::string tipo);
    std::string entrarCanal(const std::string nome);
    std::string sairCanal();
    std::string enviarMensagem(const std::string mensagem);
    std::string listarMensagens();
    void salvarUsuarios();
    void salvarServidores();
    void salvar();

};
#endif