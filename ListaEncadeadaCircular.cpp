#include "ListaCircular.hpp"
#include <iostream>

void imprimirListaCircular(No* inicio)
{
    if (!inicio) 
    {
        return;
    }
    
    No* atual = inicio;
    
    do
    {
        std::cout << atual->valor << '\n';
        atual = atual->proximo;
    }
    while (atual != inicio);
}

void destruirListaCircular(No*& inicio)
{
    if (!inicio) 
    {
        return;
    }
    
    No* final = inicio;
    
    while (final && final->proximo != inicio)
    {
        final = final->proximo;
    }
    
    final->proximo = nullptr;
    
    while (inicio)
    {
        No* atual = inicio->proximo;
        delete inicio;
        inicio = atual;
    }
    
    inicio = nullptr;
}

int tamanhoListaCircular(No*& inicio)
{
    if (!inicio)
    {
        std::cout << "Lista vazia.\n";
        return 0;
    }
    
    int cont = 0;
    No* atual = inicio;
    
    do
    {
        cont++;
        atual = atual->proximo;
    }
    while (atual != inicio);
    
    return cont;
}

void inserirInicioCircular(No*& inicio, int valor)
{
    No* novoNo = new No{valor, nullptr};
    
    if (!inicio)
    {
        inicio = novoNo;
        inicio->proximo = inicio;
        return;
    }
    
    No* atual = inicio;
    
    while (atual->proximo != inicio)
    {
        atual = atual->proximo;
    }
    
    novoNo->proximo = inicio;
    inicio = novoNo;
    atual->proximo = novoNo;
}

void inserirFinalCircular(No*& inicio, int valor)
{
    No* novoNo = new No{valor, nullptr};
    
    if (!inicio)
    {
        inicio = novoNo;
        inicio->proximo = inicio;
        return;
    }
    
    No* atual = inicio;
    
    while (atual->proximo != inicio)
    {
        atual = atual->proximo;
    }
    
    atual->proximo = novoNo;
    novoNo->proximo = inicio;
}

void inserirOrdenadoCircular(No*& inicio, int valor)
{
    if (!inicio || inicio->valor > valor)
    {
        inserirInicioCircular(inicio, valor);
        return;
    }
    
    No* atual = inicio;
    
    while (atual->proximo != inicio && atual->proximo->valor < valor)
    {
        atual = atual->proximo;
    }
    
    No* novoNo = new No{valor, atual->proximo};
    
    atual->proximo = novoNo;
}

void removerInicioCircular(No*& inicio)
{
    if (!inicio) 
    {
        return;
    }
    
    if (inicio->proximo == inicio)
    {
        delete inicio;
        inicio = nullptr;
        return;
    }
    
    No* atual = inicio;
    No* final = inicio;
    
    do
    {
        final = final->proximo;
    }
    while (final->proximo != inicio);
    
    inicio = inicio->proximo;
    final->proximo = inicio;
    
    delete atual;
}

void removerFinalCircular(No*& inicio)
{
    if (!inicio) 
    {
        return;
    }
    
    if (inicio->proximo == inicio)
    {
        delete inicio;
        inicio = nullptr;
        return;
    }
    
    No* atual = inicio;
    No* anterior = nullptr;
    
    do
    {
        anterior = atual;
        atual = atual->proximo;
    }
    while (atual->proximo != inicio);
    
    anterior->proximo = inicio;
    delete atual;
}

void removerEspecificoCircular(No*& inicio, int valor)
{
    if (!inicio) 
    {
        return;
    }
    
    if (inicio->valor == valor)
    {
        removerInicioCircular(inicio);
        return;
    }
    
    No* mtual = inicio;
    
    while (mtual->proximo != inicio && mtual->proximo->valor != valor)
    {
        mtual = mtual->proximo;
    }
    
    if (mtual->proximo != inicio)
    {
        No* aDeletar = mtual->proximo;
        mtual->proximo = aDeletar->proximo;
        delete aDeletar;
    }
}

No* buscarEspecifico(No*& inicio, int valor)
{
    if (!inicio) 
    {
        return nullptr;
    }
    
    No* atual = inicio;
    
    do
    {
        if (atual->valor == valor)
        {
            return atual;
        }
        
        atual = atual->proximo;
    }
    while (atual != inicio);
    
    std::cout << "Valor não encontrado.\n";
    return nullptr;
}
