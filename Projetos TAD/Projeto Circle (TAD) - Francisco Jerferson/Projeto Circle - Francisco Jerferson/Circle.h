#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
#include <cmath>
#include <iostream>
#include <string>

/**
 * Classe 'Circle' que implementa um círculo
 */
class Circle {
private:
    /**
     * Declaração dos atributos do círculo
     */
    double radius; // o raio do círculo
    Point center; // o centro do círculo
    
public:
    // Construtor default
    Circle() {
        radius = 0.0;
        center.setX(0);
        center.setY(0);
        // TODO
    }

    // Construtor com dois argumentos
    Circle(Point& center, double radius) {
        // TODO
        this->radius = radius;
       this->center = center;
    }
    // getters
    Point getCenter() {
        // TODO
        return center;
    }
    double getRadius() {
        // TODO
        return radius;
    }
    // setters
    void setRadius(double radius) {
        this->radius = radius;
    }
    void setCenter(double x, double y) {
        // TODO
        center.setX(x);
        center.setY(y);
    }
    void setCenter(Point& center) {
        // TODO
        this->center = center;
    }
    // Operação que calcula a área do círculo
    double area() {
        // TODO 
        return M_PI * pow(radius,2);
    }

    // Operação que verifica se um dado ponto p dado 
    // como entrada está ou não dentro do círculo
    bool interior(Point& p) {
        // TODO
        double distancia; // distância entre o raio e o ponto;
        distancia = center.distance(p);
        if(distancia < radius){
            return true;
        }else{
            return false;
        }
    }

    // Retorna uma string com os dados do círculo
    std::string toString() {
        // TODO
        std::string infor = "Circle[radius: " + std::to_string(radius) + ", center: (" + std::to_string(center.getX())
        + "," + std::to_string(center.getY()) + ")]";
        return infor;
    }
};
#endif