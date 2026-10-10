#pragma once

struct NoBinario
{
    int dado;
    NoBinario* esquerda;
    NoBinario* direita;
};

// Funções de Árvore Simples
NoBinario* criarNo(int valor);
void inserirEsquerda(NoBinario* pai, int valor);
void inserirDireita(NoBinario* pai, int valor);
void imprimirPreOrdem(NoBinario* raiz);
void destruirArvore(NoBinario* raiz);

// Funções de Árvore de Busca (BST)
void inserirBST(NoBinario*& raiz, int valor);
void imprimirEmOrdem(NoBinario* raiz);
NoBinario* encontrarMinimo(NoBinario* raiz);
void removerBST(NoBinario*& raiz, int valor);