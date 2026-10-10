#include "Pilhas.hpp"
#include <iostream>

// =========================================================================
// MÓDULO DE PILHA (STACK - LIFO)
// =========================================================================

// -------------------------------------------------------------------------
// 1. FUNÇÃO: empilhar (Push)
// -------------------------------------------------------------------------
void empilhar(NoPilha*& topo, int valor)
{
    // Roteiro Lógico:
    // 1. Crie o novo nó na Heap conectado ao topo atual.
    // 2. Atualize a âncora 'topo' para este novo nó.
    NoPilha* novoNo = new NoPilha{valor, topo};
    topo = novoNo;
}

// -------------------------------------------------------------------------
// 2. FUNÇÃO: desempilhar (Pop)
// -------------------------------------------------------------------------
void desempilhar(NoPilha*& topo)
{
    // Roteiro Lógico:
    // 1. Se vazia, encerre.
    // 2. Segure o nó em um temporário.
    // 3. Avance a âncora topo.
    // 4. Delete o temporário.
    if(!topo) return;
    
    NoPilha* aDeletar = topo;
    topo =  topo->proximo;
    delete aDeletar;
}

// -------------------------------------------------------------------------
// 3. FUNÇÃO: olharTopo (Peek / Top)
// -------------------------------------------------------------------------
int olharTopo(NoPilha* topo)
{
    // Roteiro Lógico:
    // 1. Verifique se é vazia para evitar SegFault.
    // 2. Retorne o valor do topo.
    if(!topo) 
    {std::cout << "Erro. Lista vazia.\n"; return -1;}
    
    return topo->dado;
}

// -------------------------------------------------------------------------
// 4. FUNÇÃO: estaVazia (IsEmpty)
// -------------------------------------------------------------------------
bool estaVazia(NoPilha* topo)
{
    // Roteiro Lógico: Retorne verdadeiro se for nullptr.
    return topo == nullptr;
}

// -------------------------------------------------------------------------
// 5. FUNÇÃO: destruirPilha (Clear / Destructor)
// -------------------------------------------------------------------------
void destruirPilha(NoPilha*& topo)
{
    // Roteiro Lógico: Aplique a lógica do desempilhar iterativamente enquanto existir o topo.
    if(!topo) return;
    
    while(topo)
    {
        NoPilha* aDeletar = topo;
        topo =  topo->proximo;
        delete aDeletar;
    }
    
    topo = nullptr;
}

// -------------------------------------------------------------------------
// FUNÇÃO AUXILIAR: imprimirPilha
// -------------------------------------------------------------------------
void imprimirPilha(NoPilha* topo)
{
    // Roteiro Lógico: Crie um ponteiro de varredura temporário e imprima do topo até o fim.
    if(!topo) return;
    
    NoPilha* atual = topo;
    
    while(atual)
    {
        std::cout << atual->dado << "\n";
        atual = atual->proximo;
    }
}