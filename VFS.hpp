#pragma once
#include <string>

enum Tipo { PASTA, ARQUIVO };

struct NoVFS
{
    std::string nome;
    Tipo tipo;
    
    NoVFS* primeiroFilho;
    NoVFS* proximoIrmao;
};

NoVFS* criarNoVFS(std::string nome, Tipo tipo);
void inserirNoVFS(NoVFS* pai, NoVFS* novoNo);
NoVFS* buscarNoVFS(NoVFS* inicio, std::string nomeAlvo);
void destruirVFS(NoVFS*& no);
void exibirVFS(NoVFS* no, int nivel = 0);