#include "AST.hpp"
#include <iostream>

// =========================================================================
// MÓDULO ABSTRACT SYNTAX TREE (AST) - AVALIADOR MATEMÁTICO
// =========================================================================

// -------------------------------------------------------------------------
// 1. FUNÇÃO: criarNoOperando
// Objetivo: Criar uma "folha" da árvore contendo apenas um número.
// Assinatura: NoAST* criarNoOperando(int numero)
// -------------------------------------------------------------------------
NoAST* criarNoOperando(int numero)
{
    // Roteiro Lógico:
    // 1. Aloque um NoAST na Heap.
    // 2. Defina o 'tipo' como OPERANDO.
    // 3. Guarde o 'numero' no campo 'valor'.
    // 4. Como operandos são folhas, garanta que 'esquerda' e 'direita' sejam nullptr.
    // 5. Retorne o nó.
    
    NoAST* novoNo = new NoAST{OPERANDO, numero, '\0', nullptr, nullptr};
    return novoNo;
}

// -------------------------------------------------------------------------
// 2. FUNÇÃO: criarNoOperador
// Objetivo: Criar um nó interno que une duas expressões/números.
// Assinatura: NoAST* criarNoOperador(char op, NoAST* esq, NoAST* dir)
// -------------------------------------------------------------------------
NoAST* criarNoOperador(char op, NoAST* esq, NoAST* dir)
{
    // Roteiro Lógico:
    // 1. Aloque um NoAST na Heap.
    // 2. Defina o 'tipo' como OPERADOR.
    // 3. Guarde o 'op' ('+', '-', '*', '/') no campo 'operacao'.
    // 4. Conecte o ponteiro 'esquerda' no nó 'esq' recebido.
    // 5. Conecte o ponteiro 'direita' no nó 'dir' recebido.
    // 6. Retorne o nó.
    
    NoAST* novoNo = new NoAST{OPERADOR, 0, op, esq, dir};
    return novoNo;
}

// -------------------------------------------------------------------------
// 3. FUNÇÃO A MÁGICA: avaliarAST
// Objetivo: Percorrer a árvore de baixo para cima resolvendo a equação.
// Assinatura: int avaliarAST(NoAST* raiz)
// -------------------------------------------------------------------------
int avaliarAST(NoAST* raiz)
{
    // Roteiro Lógico (Recursão Pós-Ordem de Cálculo):
    // 1. Trava de segurança: Se a raiz for nula, retorne 0.
    // 2. CASO BASE (Folha): Se o 'tipo' do nó for OPERANDO, ele É o próprio número! Retorne 'valor'.
    // 3. RECURSÃO: Avalie a esquerda e a direita.
    // 4. CÁLCULO: Faça o switch (raiz->operacao) e calcule os filhos.
    
    if(!raiz) return 0;
    
    if(raiz->tipo == OPERANDO) return raiz->valor;
    
    int valEsq = avaliarAST(raiz->esquerda);
    int valDir = avaliarAST(raiz->direita);
    
    if(raiz->operacao == '+') {return valEsq + valDir;}
    else if(raiz->operacao == '-') {return valEsq - valDir;}
    else if(raiz->operacao == '*') {return valEsq * valDir;}
    else if(raiz->operacao == '/') {return valEsq / valDir;}
    
    return 0;
}

// -------------------------------------------------------------------------
// 4. FUNÇÃO: imprimirEquacao
// Objetivo: Mostrar a equação matemática no terminal usando parênteses.
// Assinatura: void imprimirEquacao(NoAST* raiz)
// -------------------------------------------------------------------------
void imprimirEquacao(NoAST* raiz)
{
    // Roteiro Lógico (Travessia Em Ordem Modificada):
    // 1. Condição de parada: Se nulo, retorne.
    // 2. Se for OPERANDO: Apenas imprima o 'valor'.
    // 3. Se for OPERADOR: Imprima " ( ", recursão esquerda, 'operacao', recursão direita, " ) ".
    
    if(!raiz) return;
    
    if(raiz->tipo == OPERANDO) 
    {std::cout<< raiz->valor; return;}
    else if(raiz->tipo == OPERADOR)
    {
        std::cout<< "(";
        imprimirEquacao(raiz->esquerda);
        std::cout<< " " << raiz->operacao << " ";
        imprimirEquacao(raiz->direita);
        std::cout<< ")"; 
        return;
    }
}

// -------------------------------------------------------------------------
// 5. FUNÇÃO: destruirAST
// Objetivo: Limpar a memória no clássico modelo Pós-Ordem.
// Assinatura: void destruirAST(NoAST*& raiz)
// -------------------------------------------------------------------------
void destruirAST(NoAST*& raiz)
{
    // Roteiro Lógico: Deleta a esquerda, deleta a direita, deleta a raiz, anula a raiz.
    
    if(!raiz) return;
    
    destruirAST(raiz->esquerda);
    destruirAST(raiz->direita);
    
    delete raiz;
    raiz = nullptr;
}