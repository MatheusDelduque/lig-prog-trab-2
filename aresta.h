// Linguagem de Programacao - Trabalho 02
// Aluno: Matheus Delduque
// Professor: Miguel Elias Mitre Campista

#ifndef ARESTA_H
#define ARESTA_H
#include <string>

class Aresta
{
private:
    std::string vertice1;
    std::string vertice2;
    double peso;

public:
    Aresta(std::string vertice1, std::string vertice2, double peso);
    std::string getVertice1() const;
    std::string getVertice2() const;
    double getPeso() const;
    void setVertice1(std::string vertice1);
    void setVertice2(std::string vertice2);
    void setPeso(double peso);
};

#endif // ARESTA_H