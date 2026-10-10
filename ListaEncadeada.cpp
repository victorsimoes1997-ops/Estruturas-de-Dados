#include "ListaEncadeada.hpp"
#include <iostream> 

void imprimirLista(No* inicio)
{
    if (!inicio) 
    {
        return;
    }
    
    No* atual = inicio;
    
    while (atual)
    {
        std::cout << atual->valor << '\n';
        atual = atual->proximo;
    }
}

void destruirLista(No*& inicio)
{
    if (!inicio) 
    {
        return;
    }
    
    while (inicio)
    {
        No* atual = inicio->proximo; 
        delete inicio;
        inicio = atual;
    }
    
    inicio = nullptr;
}

int tamanhoLista(No*& inicio)
{
    if (!inicio)
    {
        std::cout << "Lista vazia.\n";
        return 0;
    }
    
    int cont = 0;
    No* atual = inicio;
    
    while (atual)
    {
        cont++;
        atual = atual->proximo;
    }
    
    return cont;
}

void inserirInicio(No*& inicio, int valor)
{
    No* novoNo = new No{valor, nullptr};
    
    novoNo->proximo = inicio;
    inicio = novoNo;
}

void inserirFinal(No*& inicio, int valor)
{
    No* novoNo = new No{valor, nullptr};
    
    if (!inicio)
    {
        inicio = novoNo;
        return;
    }
    
    No* atual = inicio;
    
    while (atual->proximo)
    {
        atual = atual->proximo;
    }
    
    atual->proximo = novoNo;
}

void inserirOrdenado(No*& inicio, int valor)
{
    No* novoNo = new No{valor, nullptr};
    
    if (!inicio || inicio->valor > valor)
    {
        novoNo->proximo = inicio;
        inicio = novoNo;
        return;
    }
    
    No* atual = inicio;
    
    while (atual->proximo && atual->proximo->valor < valor)
    {
        atual = atual->proximo;
    }
    
    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;
}

void removerInicio(No*& inicio)
{
    if (!inicio) 
    {
        return;
    }
    
    No* atual = inicio;
    inicio = inicio->proximo;
    delete atual;
}

void removerFinal(No*& inicio)
{
    if (!inicio) 
    {
        return;
    }
    
    if (!inicio->proximo)
    {
        delete inicio;
        inicio = nullptr;
        return;
    }
    
    No* atual = inicio;
    
    while (atual->proximo->proximo)
    {
        atual = atual->proximo;
    }
    
    delete atual->proximo;
    atual->proximo = nullptr;
}

void removerEspecifico(No*& inicio, int valor)
{
    if (!inicio) 
    {
        return;
    }
    
    if (inicio->valor == valor)
    {
        No* aDeletar = inicio;
        inicio = inicio->proximo;
        delete aDeletar;
        return;
    }
    
    No* atual = inicio;
    
    while (atual->proximo && atual->proximo->valor != valor)
    {
        atual = atual->proximo;
    }
    
    if (atual->proximo)
    {
        No* aDeletar = atual->proximo;
        atual->proximo = aDeletar->proximo;
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
    
    while (atual != nullptr && atual->valor != valor)
    {
        atual = atual->proximo;
    }
    
    if (atual)
    {
        return atual;
    }
    else
    {
        std::cout << "Valor não encontrado.\n";
        return nullptr;
    }
}
