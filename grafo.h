// Linguagem de Programacao - Trabalho 02
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#ifndef GRAFO_H
#define GRAFO_H

#include "aresta.h"
#include <vector>

class Grafo
{
private:
    int numVertices;
    int numArestas;
    std::vector<std::string> nomeVertices;
    std::vector<Aresta> vertices;

public:
    void setNomeVertices();
    void setNumVertices();
    void setNumArestas();
    void adicionarAresta(const Aresta &aresta);
    void exibirListaEnlaces();
    void lerArquivoEntrada(const std::string &caminhoArquivo);
    void calcularDensidade();
    void verificarVerticeMaiorCentralidade();
    void dijkstra(const std::string &verticeOrigem, const std::string &verticeDestino);
    void verificarVerticeMaiorCentralidadeProximidade();
};

#endif // GRAFO_H