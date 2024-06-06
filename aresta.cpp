// Linguagem de Programacao - Trabalho 02
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#include "aresta.h"

Aresta::Aresta(std::string vertice1, std::string vertice2, double peso)
    : vertice1(vertice1), vertice2(vertice2), peso(peso) {}

std::string Aresta::getVertice1() const
{
    return vertice1;
}

std::string Aresta::getVertice2() const
{
    return vertice2;
}

double Aresta::getPeso() const
{
    return peso;
}

void Aresta::setVertice1(std::string vertice1)
{
    this->vertice1 = vertice1;
}

void Aresta::setVertice2(std::string vertice2)
{
    this->vertice2 = vertice2;
}

void Aresta::setPeso(double peso)
{
    this->peso = peso;
}