#ifndef LISTA_CIRCULAR_HPP
#define LISTA_CIRCULAR_HPP

struct No
{
    int valor;
    No* proximo;
};

void imprimirListaCircular(No* inicio);
void destruirListaCircular(No*& inicio);
int tamanhoListaCircular(No*& inicio);
void inserirInicioCircular(No*& inicio, int valor);
void inserirFinalCircular(No*& inicio, int valor);
void inserirOrdenadoCircular(No*& inicio, int valor);
void removerInicioCircular(No*& inicio);
void removerFinalCircular(No*& inicio);
void removerEspecificoCircular(No*& inicio, int valor);
No* buscarEspecifico(No*& inicio, int valor);

#endif // LISTA_CIRCULAR_HPP
