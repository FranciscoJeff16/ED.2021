#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
#include <string>

/*
 * Declaração da classe Point, que modela um ponto no plano
 */
class Point {
private:
    // Atributos da classe Ponto
    double x; // coordenada do eixo x
    double y; // coordenada do eixo y

public:
    /**
     * Construtor default
     */
    Point() {
        x = y = 0.0;
    }

    /**
     * Construtor que recebe bois argumentos
     */
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }

    /**
     * getter: retorna o valor da coordenada x
     */
    double getX() {
        return x;
    }

    /**
     * getter: retorna o valor da coordenada y
     */
    double getY() {
        return y;
    }

    /**
     * setter: modifica o valor da coordenada x deste ponto
     */
    void setX(double x) {
        this->x = x;
    }

    /**
     * setter: modifica o valor da coordenada y deste ponto
     */
    void setY(double y) {
        this->y = y;
    }

    /**
     * Calcula a distância entre este ponto e o ponto p passado
     * como parâmetro. Note que o ponto p foi passado como uma
     * referência. Logo, não houve cópia de dados.
     */
    double distance(Point& p) {
        double dx = this->x - p.x;
        double dy = this->y - p.y;
        return sqrt(dx*dx + dy*dy);
    }

    /**
     * Função toString, que retorna uma string contendo
     * os dados deste ponto
     */
    std::string toString() {
        std::string str = "(" + std::to_string(x) + "," + std::to_string(y) + ")";
        return str;
    }
};

#endif