#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

// Estrutura do nó da lista
struct No 
{
    int valor;
    No* proximo;
};

// Declaração de todas as funções disponíveis
void imprimirLista(No* inicio);
void destruirLista(No*& inicio);
int tamanhoLista(No*& inicio);
void inserirInicio(No*& inicio, int valor);
void inserirFinal(No*& inicio, int valor);
void inserirOrdenado(No*& inicio, int valor);
void removerInicio(No*& inicio);
void removerFinal(No*& inicio);
void removerEspecifico(No*& inicio, int valor);
No* buscarEspecifico(No*& inicio, int valor);

#endif // LISTA_ENCADEADA_H
