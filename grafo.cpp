// Linguagem de Programacao - Trabalho 02
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include "grafo.h"
#include "aresta.h"
#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>
#include <list>
#include <sstream>
#include <fstream>
#include <unordered_set>

// Adiciona uma aresta ao grafo.
void Grafo::adicionarAresta(const Aresta &aresta)
{
    vertices.push_back(aresta);
}

// Exibe a lista de arestas no grafo.
void Grafo::exibirListaEnlaces()
{
    std::cout << "(";

    // Itera sobre cada aresta no vetor vertices.
    for (const auto &aresta : vertices)
    {
        // Obtem os nomes dos vertices da aresta atual.
        std::string vertice1 = aresta.getVertice1();
        std::string vertice2 = aresta.getVertice2();

        // Imprime os vertices e o peso da aresta atual.
        std::cout << vertice1 << "-" << vertice2 << ": " << aresta.getPeso();

        // Verifica se nao eh a ultima aresta no vetor.
        if (&aresta != &vertices.back())
        {
            // Imprime um ponto e virgula se não for a ultima aresta.
            std::cout << "; ";
        }
    }

    std::cout << ")" << std::endl;
}
// Le um arquivo de entrada contendo as arestas do grafo.
void Grafo::lerArquivoEntrada(const std::string &caminhoArquivo)
{
    // Abre o arquivo de entrada.
    std::ifstream arquivoEntrada(caminhoArquivo);

    // Verifica se o arquivo foi aberto com sucesso.
    if (!arquivoEntrada.is_open())
    {
        std::cout << "Erro ao abrir o arquivo de entrada." << std::endl;
        return;
    }

    // Le cada linha do arquivo.
    std::string linha;
    while (std::getline(arquivoEntrada, linha))
    {
        // Cria um objeto istringstream para analisar a linha.
        std::istringstream iss(linha);

        // Le os nomes dos vertices e o peso da aresta.
        std::string vertice1, vertice2;
        double peso;
        if (iss >> vertice1 >> vertice2 >> peso)
        {
            // Cria uma aresta com os dados lidos e a adiciona ao grafo.
            Aresta aresta(vertice1, vertice2, peso);
            adicionarAresta(aresta);
        }
        else
        {
            std::cout << "Erro ao ler a linha: " << linha << std::endl;
        }
    }

    arquivoEntrada.close();
}

// Define o numero de arestas do grafo.
void Grafo::setNumArestas()
{
    numArestas = vertices.size();
}

// Define os nomes dos vertices do grafo.
void Grafo::setNomeVertices()
{
    // Cria um conjunto não ordenado (unordered_set) para armazenar os nomes únicos de vértices.
    std::unordered_set<std::string> uniqueNames;

    // Itera sobre cada aresta no vetor vertices.
    for (const auto &aresta : vertices)
    {
        // Insere os nomes dos vertices da aresta no conjunto uniqueNames.
        uniqueNames.insert(aresta.getVertice1());
        uniqueNames.insert(aresta.getVertice2());
    }

    // Itera sobre cada nome de vértice unico no conjunto uniqueNames.
    for (const auto &vertice : uniqueNames)
    {
        // Adiciona cada nome de vertice ao vetor nomeVertices.
        nomeVertices.push_back(vertice);
    }
}

// Define o numero de vertices do grafo.
void Grafo::setNumVertices()
{
    numVertices = nomeVertices.size();
}

// Calcula a densidade do grafo.
void Grafo::calcularDensidade()
{
    // Calcula o número máximo de arestas possíveis no grafo.
    int maxArestas = (numVertices * (numVertices - 1)) / 2;

    // Calcula a densidade do grafo.
    double densidade = static_cast<double>(numArestas) / maxArestas;

    std::cout << numVertices << " vertices e " << numArestas << " arestas." << std::endl;

    std::cout << "Densidade do grafo: " << densidade << std::endl;
}

// Encontra o vertice com a maior centralidade no grafo.
void Grafo::verificarVerticeMaiorCentralidade()
{
    std::string vertice_maior_centralidade;
    double maior_centralidade = 0.0;

    // Itera sobre cada vértice no grafo.
    for (int i = 0; i < numVertices; i++)
    {
        // Inicializa a variavel que armazenara a centralidade do vertice atual.
        double centralidade = 0.0;

        // Obtém o nome do vértice atual.
        std::string vertice = nomeVertices.at(i);

        // Itera sobre cada aresta no grafo.
        for (const auto &aresta : vertices)
        {
            // Verifica se a aresta esta conectada ao vertice atual.
            if (aresta.getVertice1() == vertice || aresta.getVertice2() == vertice)
            {
                // Adiciona o peso da aresta a centralidade do vertice atual.
                centralidade += aresta.getPeso();
            }
        }

        // Verifica se a centralidade do vertice atual eh maior do que a maior centralidade encontrada.
        if (centralidade > maior_centralidade)
        {
            maior_centralidade = centralidade;
            vertice_maior_centralidade = vertice;
        }
    }

    std::cout << "Vertice com maior centralidade: " << vertice_maior_centralidade << std::endl;
}
// Implementa o algoritmo de Dijkstra para encontrar o caminho mais curto entre dois vertices em um grafo.
void Grafo::dijkstra(const std::string &verticeOrigem, const std::string &verticeDestino)
{
    // Cria um mapa de vertices para armazenar o nome do vertice e o endice correspondente.
    std::unordered_map<std::string, int> vertexMap = {
        {"Ana", 0}, {"Bruno", 1}, {"Carlos", 2}, {"Daniel", 3}, {"Enzo", 4}, {"Fabio", 5}, {"Gustavo", 6}, {"Heitor", 7}, {"Italo", 8}};

    // Cria uma lista de adjacencias para cada vertice.
    std::list<std::pair<int, int>> list[9];

    // Itera sobre cada aresta no grafo.
    for (const Aresta &aresta : vertices)
    {
        // Obtem os endices dos vertices inicio e fim.
        int startIndex = vertexMap[aresta.getVertice1()];
        int endIndex = vertexMap[aresta.getVertice2()];

        // Obtem o custo da aresta.
        int cost = aresta.getPeso();

        // Adiciona o par (endice do vertice final, custo) e lista de adjacencias do vertice inicial.
        list[startIndex].push_back(std::make_pair(endIndex, cost));
    }

    // Obtem os indices dos vertices de origem e destino.
    int origem = vertexMap[verticeOrigem];
    int destino = vertexMap[verticeDestino];

    // Obtem o numero de vertices no grafo.
    int numVertices = vertices.size();

    // Cria arrays para armazenar as distancias e os status de visitacao de cada vertice.
    int distancias[numVertices];
    int visitados[numVertices];

    // Cria uma fila de prioridade para armazenar os vertices com as distancias minimas.
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>
        fila_prioridade;

    // Inicializa as distancias e os status de visitacao de cada vertice.
    for (int i = 0; i < numVertices; i++)
    {
        distancias[i] = 10000000;
        visitados[i] = false;
    }

    // Define a distancia do vertice de origem como 0.
    distancias[origem] = 0;

    // Adiciona o par (distancia, indice do vertice) a fila de prioridade.
    fila_prioridade.push(std::make_pair(distancias[origem], origem));

    // Enquanto a fila de prioridade nao estiver vazia.
    while (!fila_prioridade.empty())
    {
        // Obtem o par (distancia, indice do vertice) com a distância minima.
        std::pair<int, int> p = fila_prioridade.top();
        int vertice = p.second;

        // Remove o par da fila de prioridade.
        fila_prioridade.pop();

        // Se o vertice ainda não foi visitado.
        if (visitados[vertice] == false)
        {
            // Marca o vertice como visitado.
            visitados[vertice] = true;

            // Itera sobre a lista de adjacencias do vertice.
            std::list<std::pair<int, int>>::iterator it;

            for (it = list[vertice].begin(); it != list[vertice].end(); it++)
            {
                // Obtem o vizinho e o custo da aresta.
                int vizinho = it->first;
                int custo = it->second;

                // Verifica se o vizinho ainda não foi visitado e se a nova distancia eh menor.
                if (visitados[vizinho] == false && distancias[vizinho] > distancias[vertice] + custo)
                {
                    // Atualiza a distancia do vizinho.
                    distancias[vizinho] = distancias[vertice] + custo;

                    // Adiciona o vizinho a fila de prioridade com a nova distancia.
                    fila_prioridade.push(std::make_pair(distancias[vizinho], vizinho));
                }
            }
        }
    }

    std::cout << "Custo total do caminho: " << distancias[destino] << std::endl;
}

// Verifica o vertice com maior centralidade de proximidade
void Grafo::verificarVerticeMaiorCentralidadeProximidade()
{

    std::string verticeMaiorCentralidadeProximidade;
    double maiorCentralidadeProximidade; 

    // Itera sobre cada vertice no grafo
    for (int i = 0; i < numVertices; i++)
    {
        double centralidade = 0.0; 
        std::string vertice = nomeVertices.at(i); 

        // Itera sobre cada aresta no grafo
        for (const auto &aresta : vertices)
        {
            // Verifica se o vertice atual eh um dos vertices da aresta atual
            if (aresta.getVertice1() == vertice || aresta.getVertice2() == vertice)
            {
                // Adiciona o peso da aresta a centralidade do vertice atual
                centralidade += aresta.getPeso();
            }
        }

        // Verifica se e o primeiro vertice ou se a centralidade atual é maior que a centralidade do vertice com maior centralidade de proximidade
        if (i == 0 || centralidade < maiorCentralidadeProximidade)
        {
            // Atualiza a centralidade do vértice com maior centralidade de proximidade
            maiorCentralidadeProximidade = centralidade;
            verticeMaiorCentralidadeProximidade = vertice;
        }
    }

    // Imprime o vertice com maior centralidade de proximidade e a centralidade de proximidade correspondente
    std::cout << "Vertice com maior centralidade de proximidade: " << verticeMaiorCentralidadeProximidade << std::endl;
    std::cout << "Centralidade de proximidade: " << 1 / maiorCentralidadeProximidade << std::endl;
}