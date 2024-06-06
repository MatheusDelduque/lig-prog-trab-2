#include <iostream>
#include <sstream>
#include "grafo.h"

int main()
{
    Grafo grafo;
    grafo.lerArquivoEntrada("input.txt");
    grafo.setNumArestas();
    grafo.setNomeVertices();
    grafo.setNumVertices();
    std::string verticeDestino;
    std::string verticeOrigem;

    int opcao;
    do
    {
        std::cout << "Menu de opções:" << std::endl;
        std::cout << "1. Exibir grafo" << std::endl;
        std::cout << "2. Calcular densidade" << std::endl;
        std::cout << "3. Verificar vertice com maior centralidade" << std::endl;
        std::cout << "4. Calcular menor caminho entre dois vertices" << std::endl;
        std::cout << "5. Verificar vertice com a maior centralidade de proximidade" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Digite a opção desejada: ";

        std::string linha;
        std::getline(std::cin, linha);

        std::istringstream iss(linha);
        if (iss >> opcao)
        {
            switch (opcao)
            {
            case 1:
                grafo.exibirListaEnlaces();
                break;
            case 2:

                grafo.calcularDensidade();
                break;
            case 3:
                grafo.verificarVerticeMaiorCentralidade();
                break;
            case 4:
                std::cout << "Escolha o vertice de origem :" << std::endl;
                std::getline(std::cin, verticeOrigem);

                std::cout << "Escolha o vertice de destino :" << std::endl;
                std::getline(std::cin, verticeDestino);

                grafo.dijkstra(verticeOrigem, verticeDestino);
                break;
            case 5:
                grafo.verificarVerticeMaiorCentralidadeProximidade();
                break;
            case 0:
                std::cout << "Saindo do programa..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
                break;
            }
        }
        else
        {
            std::cout << "Entrada inválida. Tente novamente." << std::endl;
        }

        std::cout << std::endl;
    } while (opcao != 0);

    return 0;
}