#include "BST.hpp"
#include <iostream>

// =========================================================================
// MÓDULO DE ÁRVORE BINÁRIA SIMPLES
// =========================================================================

// -------------------------------------------------------------------------
// FUNÇÃO: criarNo
// -------------------------------------------------------------------------
NoBinario* criarNo(int valor)
{
    // Roteiro Lógico:
    // 1. Aloque um novo NoBinario na Heap com o valor informado.
    // 2. Inicialize os ponteiros de esquerda e direita como nullptr.
    // 3. Retorne o nó recém-criado.
    NoBinario* novoNo = new NoBinario{valor, nullptr, nullptr};
    return novoNo;
}

// -------------------------------------------------------------------------
// FUNÇÃO: inserirEsquerda
// -------------------------------------------------------------------------
void inserirEsquerda(NoBinario* pai, int valor)
{
    // Roteiro Lógico:
    // 1. Verifique se o pai existe.
    // 2. Verifique se o ponteiro da esquerda do pai já está ocupado e avise se estiver.
    // 3. Caso livre, crie o novo nó e conecte à esquerda do pai.
    if(!pai) return;
    
    if(pai->esquerda)
    {std::cout << "Erro. Vaga ocupada.\n"; return;}
    
    NoBinario* novoNo = new NoBinario{valor, nullptr, nullptr};
    pai->esquerda = novoNo;
}

// -------------------------------------------------------------------------
// FUNÇÃO: inserirDireita
// -------------------------------------------------------------------------
void inserirDireita(NoBinario* pai, int valor)
{
    // Roteiro Lógico:
    // 1. Lógica análoga a inserirEsquerda, focada no ponteiro da direita.
    if(!pai) return;
    
    if(pai->direita)
    {std::cout << "Erro. Vaga ocupada.\n"; return;}
    
    NoBinario* novoNo = new NoBinario{valor, nullptr, nullptr};
    pai->direita = novoNo;
}

// -------------------------------------------------------------------------
// FUNÇÃO: imprimirPreOrdem
// -------------------------------------------------------------------------
void imprimirPreOrdem(NoBinario* raiz)
{
    // Roteiro Lógico (Travessia: Raiz -> Esquerda -> Direita):
    // 1. Caso base: se a raiz for nula, retorne.
    // 2. Imprima a raiz atual.
    // 3. Desça recursivamente para a esquerda, depois direita.
    if(!raiz) return;
    
    std::cout << raiz->dado << '\n';
    
    imprimirPreOrdem(raiz->esquerda);
    imprimirPreOrdem(raiz->direita);
}

// -------------------------------------------------------------------------
// FUNÇÃO: destruirArvore
// -------------------------------------------------------------------------
void destruirArvore(NoBinario* raiz)
{
    // Roteiro Lógico (Pós-Ordem):
    // 1. Condição de parada: raiz nula.
    // 2. Destrua os filhos à esquerda e depois os filhos à direita.
    // 3. Delete a raiz atual para evitar Memory Leak.
    if(!raiz) return;
    
    destruirArvore(raiz->esquerda);
    destruirArvore(raiz->direita);
    
    delete raiz;
}

// =========================================================================
// MÓDULO DE ÁRVORE BINÁRIA DE BUSCA (BST)
// =========================================================================

// -------------------------------------------------------------------------
// FUNÇÃO: inserirBST
// -------------------------------------------------------------------------
void inserirBST(NoBinario*& raiz, int valor)
{
    // Roteiro Lógico (Recursão Inteligente):
    // 1. CASO BASE: Se a 'raiz' atual for nula, é aqui que o nó entra! 
    // 2. REGRA DA ESQUERDA: Se o 'valor' for MENOR, vaga na subárvore esquerda.
    // 3. REGRA DA DIREITA: Se o 'valor' for MAIOR, vaga na subárvore direita.
    // 4. REGRA DOS IGUAIS: Se for igual, avise e encerre.
    if(!raiz) {raiz = criarNo(valor); return;}
    
    if(valor < raiz->dado) {inserirBST(raiz->esquerda, valor); return;}
    else if(valor > raiz->dado) {inserirBST(raiz->direita, valor); return;}
    else {std::cout << "Valor já existe.\n"; return;}
}

// -------------------------------------------------------------------------
// FUNÇÃO: imprimirEmOrdem
// -------------------------------------------------------------------------
void imprimirEmOrdem(NoBinario* raiz)
{
    // Roteiro Lógico:
    // 1. Condição de parada: se !raiz, return.
    // 2. Vá tudo para a ESQUERDA.
    // 3. Imprima a RAIZ.
    // 4. Vá tudo para a DIREITA.
    if(!raiz) return;
    
    imprimirEmOrdem(raiz->esquerda);
    std::cout << raiz->dado << "\n";
    imprimirEmOrdem(raiz->direita);
}

// -------------------------------------------------------------------------
// FUNÇÃO AUXILIAR: encontrarMinimo
// -------------------------------------------------------------------------
NoBinario* encontrarMinimo(NoBinario* raiz)
{
    // Roteiro Lógico:
    // 1. Avance enquanto houver filho à esquerda.
    // 2. Retorne a raiz.
    if(!raiz) return nullptr;
    
    NoBinario* atual = raiz;
    while(atual->esquerda)
    {
        atual = atual->esquerda;
    }
    return atual;
}

// -------------------------------------------------------------------------
// FUNÇÃO O CHEFÃO: removerBST
// -------------------------------------------------------------------------
void removerBST(NoBinario*& raiz, int valor)
{
    // Roteiro Lógico:
    // PASSO 1: Busca Recursiva pelo nó correspondente ao valor.
    // PASSO 2: Achou o nó! Lide com os 3 cenários (Folha, 1 filho, 2 filhos).
    if(!raiz) return;
    
    if(valor < raiz->dado) removerBST(raiz->esquerda, valor);
    else if(valor > raiz->dado) removerBST(raiz->direita, valor);
    else
    {
        if(!raiz->esquerda && !raiz->direita)
        {
            delete raiz;
            raiz = nullptr;
        }
        else if(!raiz->esquerda && raiz->direita)
        {
            NoBinario* temp = raiz;
            raiz = raiz->direita;
            delete temp;
        }
        else if(raiz->esquerda && !raiz->direita)
        {
            NoBinario* temp = raiz;
            raiz = raiz->esquerda;
            delete temp;
        }
        else if(raiz->esquerda && raiz->direita)
        {
            NoBinario* temp1 = encontrarMinimo(raiz->direita);
            raiz->dado = temp1->dado;
            removerBST(raiz->direita, temp1->dado);
        }
    }
}