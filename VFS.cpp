#include "VFS.hpp"
#include <iostream>

// =========================================================================
// MÓDULO VIRTUAL FILE SYSTEM (VFS) - ÁRVORE N-ÁRIA
// =========================================================================

// -------------------------------------------------------------------------
// 1. FUNÇÃO: criarNoVFS
// Objetivo: Fabricar um nó isolado na memória.
// -------------------------------------------------------------------------
NoVFS* criarNoVFS(std::string nome, Tipo tipo)
{
    // Roteiro Lógico:
    // 1. Aloque dinamicamente um novo espaço de memória para um NoVFS.
    // 2. Guarde o 'nome' e o 'tipo' recebidos.
    // 3. Garanta que 'primeiroFilho' e 'proximoIrmao' apontem para nulo.
    // 4. Retorne o endereço.
    NoVFS* novoNo = new NoVFS{nome, tipo};
    novoNo->primeiroFilho = nullptr;
    novoNo->proximoIrmao = nullptr;
    return novoNo;
}

// -------------------------------------------------------------------------
// 2. FUNÇÃO: inserirNoVFS
// Objetivo: Colocar um novo arquivo ou subpasta dentro de uma pasta pai.
// -------------------------------------------------------------------------
void inserirNoVFS(NoVFS* pai, NoVFS* novoNo)
{
    // Roteiro Lógico:
    // 1. Trava de Segurança Básica: pai e novoNo não nulos.
    // 2. Trava da Natureza: pai deve ser do tipo PASTA.
    // 3. Cenário A: pasta vazia (primeiroFilho = novoNo).
    // 4. Cenário B: pasta com itens, avança até o último proximoIrmao.
    if(!pai || !novoNo) return;
    
    if(pai->tipo == ARQUIVO)
    {
        std::cout << "Erro: arquivos não podem conter outros arquivos.\n";
        return;
    }
    
    if(!pai->primeiroFilho) {pai->primeiroFilho = novoNo; return;}
    else
    {
        NoVFS* cursor = pai->primeiroFilho;
        
        while(cursor->proximoIrmao)
        {
            cursor = cursor->proximoIrmao;
        }
        
        cursor->proximoIrmao = novoNo;
    }
}

// -------------------------------------------------------------------------
// 3. FUNÇÃO: buscarNoVFS
// Objetivo: Procurar um arquivo ou pasta pelo nome.
// -------------------------------------------------------------------------
NoVFS* buscarNoVFS(NoVFS* inicio, std::string nomeAlvo)
{
    // Roteiro Lógico (Busca em Profundidade):
    // 1. Se nulo, retorne nulo.
    // 2. Se achou no nó atual, retorne.
    // 3. Desça nos filhos e guarde num temporário.
    // 4. Se o temporário for válido, achei. Se não, busque nos irmãos.
    if(!inicio) return nullptr;
    
    if(inicio->nome == nomeAlvo) return inicio;
    
    NoVFS* atual = inicio;
    
    NoVFS* temp = buscarNoVFS(atual->primeiroFilho, nomeAlvo);
    
    if(temp) return temp;
    else return buscarNoVFS(atual->proximoIrmao, nomeAlvo);
}

// -------------------------------------------------------------------------
// 4. FUNÇÃO: destruirVFS
// Objetivo: Liberar toda a memória da árvore de forma segura.
// -------------------------------------------------------------------------
void destruirVFS(NoVFS*& no)
{
    // Roteiro Lógico (Travessia Pós-Ordem adaptada para N-ária):
    // 1. Condição de Parada: 'no' nulo.
    // 2. Limpar para baixo (primeiroFilho).
    // 3. Limpar para o lado (proximoIrmao).
    // 4. Delete o nó atual e zere o ponteiro.
    if(!no) return;
    
    destruirVFS(no->primeiroFilho);
    destruirVFS(no->proximoIrmao);
    
    delete no;
    no = nullptr;
}

// -------------------------------------------------------------------------
// FUNÇÃO AUXILIAR: exibirVFS (Simula o comando 'tree')
// -------------------------------------------------------------------------
void exibirVFS(NoVFS* no, int nivel)
{
    // Roteiro Lógico:
    // 1. Aplica a tabulação baseada no nível hierárquico.
    // 2. Indica visualmente se é Arquivo [F] ou Diretório [D].
    // 3. Processa o filho descendo o nível e o irmão mantendo o nível.
    if (!no) return;

    for (int i = 0; i < nivel; ++i) {std::cout << "  ";}

    if (no->tipo == PASTA) {std::cout << "[D] " << no->nome << "/\n";} 
    else {std::cout << "[F] " << no->nome << "\n";}

    exibirVFS(no->primeiroFilho, nivel + 1);
    exibirVFS(no->proximoIrmao, nivel);
}