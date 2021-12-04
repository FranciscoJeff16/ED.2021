#include <iostream>
#include <vector>
#include <sstream>
#include "Point.h"
#include "Circle.h"
using namespace std;

int main() {
    Point *p = nullptr;
    Circle *c = nullptr;
    
    while(true) {
        string comando;
        getline(cin, comando);

        stringstream ss( comando );
        vector<string> tokens;
        string word;

        while(ss >> word) {
            tokens.push_back(word);
        }

        if(tokens[0] == "end") {
            cout << "$" << comando << endl;
            if(p != nullptr) delete p;
            if(c != nullptr) delete c;
            break;
        }
        else if(tokens[0] == "circle") {
            cout << "$" << comando << endl;
            double x = std::stof( tokens[1] );
            double y = std::stof( tokens[2] );
            double radius = std::stof( tokens[3] );
            if(p != nullptr) delete p;
            if(c != nullptr) delete c;
            p = new Point(x,y);
            c = new Circle(*p, radius);
        }
        else if(tokens[0] == "show") {
            cout << "$" << comando << endl;
            if(c != nullptr) cout << c->toString() << endl;
            else cout << "fail: nenhum circulo criado" << endl;
        }
        else if(tokens[0] == "getcenter") {
            cout << "$" << comando << endl;
            if(c != nullptr) cout << c->getCenter().toString() << endl;
            else cout << "fail: nenhum circulo criado" << endl;
        }
        else if(tokens[0] == "getradius") {
            cout << "$" << comando << endl;
            if(c != nullptr) cout << c->getRadius() << endl;
            else cout << "fail: nenhum circulo criado" << endl;
        }
        else if(tokens[0] == "setradius") {
            cout << "$" << comando << endl;
            double r = std::stof( tokens[1] );
            if(c != nullptr) c->setRadius(r);
            else cout << "fail: nenhum circulo criado" << endl;
        }
        else if(tokens[0] == "setcenter") {
            cout << "$" << comando << endl;
            double x = std::stof( tokens[1] );
            double y = std::stof( tokens[2] );
            if(c != nullptr) c->setCenter(x,y);
            else cout << "fail: nenhum circulo criado" << endl;
        }
        else if(tokens[0] == "setcenterpoint") {
            cout << "$" << comando << endl;
            double x = std::stof( tokens[1] );
            double y = std::stof( tokens[2] );
            if(p != nullptr) delete p;
            p = new Point(x,y);
            if(c != nullptr) c->setCenter(*p);
            else cout << "fail: nenhum circulo criado" << endl;
        }
        else if(tokens[0] == "area") {
            cout << "$" << comando << endl;
            if(c != nullptr) cout << c->area() << endl;
            else cout << "fail: nenhum circulo criado" << endl;
        }
        else if(tokens[0] == "pertence") {
            cout << "$" << comando << endl;
            double x = std::stof( tokens[1] );
            double y = std::stof( tokens[2] );
            Point ponto(x,y);
            if(c != nullptr)
                cout << std::boolalpha << c->interior(ponto) << endl;
            else   
                cout << "fail: nenhum circulo criado" << endl;
        }
        else {
            cout << "fail: comando invalido" << endl;
        }
    }

    return 0;
}