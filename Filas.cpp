#include "Filas.hpp"
#include <iostream>

// =========================================================================
// MÓDULO DE FILA (QUEUE - FIFO)
// =========================================================================

// -------------------------------------------------------------------------
// FUNÇÃO: enfileirar
// -------------------------------------------------------------------------
void enfileirar(NoFila*& cabeca, int valor)
{
    // Roteiro Lógico:
    // 1. Crie um novo nó que aponta para nulo.
    // 2. Se a fila estiver vazia, vai no início (se torna a nova cabeça).
    // 3. Se não, varre até o fim e anexa o novo nó lá.
    NoFila* novoNo = new NoFila{valor, nullptr};
    
    if(!cabeca) {cabeca = novoNo; return;}
    
    NoFila* atual = cabeca;
    while(atual->proximo) atual = atual->proximo;
    atual->proximo = novoNo;
}

// -------------------------------------------------------------------------
// FUNÇÃO: desenfileirar
// -------------------------------------------------------------------------
void desenfileirar(NoFila*& cabeca)
{
    // Roteiro Lógico:
    // 1. Se estiver vazia, encerre a função.
    // 2. Guarde o nó cabeça numa variável temporária.
    // 3. Avance a cabeça e delete o nó que foi retirado.
    if(!cabeca) return;
    
    NoFila* aDeletar = cabeca;
    cabeca = cabeca->proximo;
    delete aDeletar;
}

// -------------------------------------------------------------------------
// FUNÇÃO: olharCabeca
// -------------------------------------------------------------------------
NoFila* olharCabeca(NoFila* cabeca)
{
    // Roteiro Lógico:
    // 1. Verifica se não está vazia e retorna o início da fila de atendimento.
    if(!cabeca) return nullptr;
    else return cabeca;
}

// -------------------------------------------------------------------------
// FUNÇÃO: destruirFila
// -------------------------------------------------------------------------
void destruirFila(NoFila*& cabeca)
{
    // Roteiro Lógico:
    // 1. Basicamente um destruir lista padrão, limpando a fila por completo iterativamente.
    if(!cabeca) return;
    
    while(cabeca)
    {
        NoFila* aDeletar = cabeca;
        cabeca = cabeca->proximo;
        delete aDeletar;
    }
    
    cabeca = nullptr;
}

// -------------------------------------------------------------------------
// FUNÇÃO AUXILIAR: imprimirFila
// -------------------------------------------------------------------------
void imprimirFila(NoFila* cabeca)
{
    // Roteiro Lógico:
    // 1. Impressão normal de todos os elementos varrendo a fila.
    if(!cabeca) return;
    
    NoFila* atual = cabeca;
    
    while(atual)
    {
        std::cout << atual->dado << "\n";
        atual = atual->proximo;
    }
}