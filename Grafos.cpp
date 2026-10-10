#include "Grafos.hpp"
#include <iostream>


Grafo* criarGrafo(int nro_vert, int Gmax, bool eh_ponderado)
{
    Grafo* gr = new Grafo;

    gr->nro_vert = nro_vert;
    gr->Gmax = Gmax;
    gr->eh_ponderado = eh_ponderado;

    gr->grau = new int[nro_vert]; //O ponteiro grau é um vetor de inteiro, baseado no número de vértices. Cada vértice tem seu grau.

    for(int i = 0; i < nro_vert; i++) {gr->grau[i] = 0;} //Zeramos o grau de nó.

    gr->arestas = new int[nro_vert * Gmax]; //Gmax define o número de arestas máximo por nó. Com o número de nós, temos a quantidade de arestas total.

    if(eh_ponderado) gr->pesos = new float[nro_vert * Gmax]; //Temos tanto pesos quanto arestas.
    else gr->pesos = nullptr;

    return gr;
}

void destruirGrafo(Grafo* gr)
{
    if(!gr) return;

    delete[] gr->grau;
    delete[] gr->arestas;
    if(gr->pesos) delete[] gr->pesos;

    delete gr;
    gr = nullptr;
}

int inserirArestas(Grafo* gr, int origem, int destino, bool digrafo, float peso)
{
    if(!gr) return 0;
    if(origem < 0 || origem > gr->nro_vert) return 0;
    if(destino < 0 || destino > gr->nro_vert) return 0;
    if(gr->grau[origem] >= gr->Gmax) return 0;
    
    int indiceIda = (origem * gr->Gmax) + gr->grau[origem];
    gr->arestas[indiceIda] = destino;
    if(gr->eh_ponderado) gr->pesos[indiceIda] = peso;
    gr->grau[origem]++;

    if(!digrafo)
    {
        if(gr->grau[destino] >= gr->Gmax) return 0;
        int indiceVolta = (destino * gr->Gmax) + gr->grau[destino];
        if(gr->eh_ponderado != 0) gr->pesos[indiceVolta] = peso;
        gr->arestas[indiceVolta] = origem;        
        gr->grau[destino]++;
    }   

    return 1;
}

int removerArestas(Grafo* gr, int origem, int destino, bool digrafo)
{
    if(!gr) return 0;
    if(origem < 0 || origem >= gr->nro_vert) return 0;
    if(destino < 0 || destino >= gr->nro_vert) return 0;
    if(gr->grau[origem] == 0) return 0;

    int i = 0;
    int baseIda = origem * gr->Gmax;

    while(i < gr->grau[origem] && gr->arestas[baseIda + i] != destino) i++;

    if(i == gr->grau[origem])
    {
        if(!digrafo) removerArestas(gr, destino, origem, true);
        return 0;
    }

    for(int j = i; j < gr->grau[origem] - 1; j++)
    {
        gr->arestas[baseIda + j] = gr->arestas[baseIda + j + 1];

        if (gr->eh_ponderado)
        {
            gr->pesos[baseIda + j] = gr->pesos[baseIda + j + 1];
        }
        
    }
    gr->grau[origem]--;

    if(!digrafo) removerArestas(gr, destino, origem, true);

    return 1;
}

void imprimirGrafo(Grafo* gr)
{
    if(!gr) return;

    int base = gr->nro_vert;
    
    for(int v = 0; v < base; v++)
    {
        std::cout << "Vértice: " << v << '\n';

        for(int a = 0; a < gr->grau[v]; a++)
        {
            int indice = (v * gr->Gmax) + a;
            int destino = gr->arestas[indice];

            std::cout << "Aresta " << a << ": " << destino << '\n';

            if(gr->eh_ponderado)
            {
                std::cout << "Peso: " << gr->pesos[indice] << '\n';
            }
        }
    }
}