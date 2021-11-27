#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include "Matriz.h"
using namespace std;

int main()
{
	vector<Matriz*> matrizes; // Vetor de ponteiros para matrizes
	
	while(true) {
		string cmd;
		getline(cin, cmd);

		std::stringstream ss{ cmd };
		vector<string> tokens;
		string buffer;

		while(ss >> buffer) {
			tokens.push_back(buffer);
		}

		if(tokens[0] == "libera" || tokens[0] == "exit") {
			for(int i = 0; i < matrizes.size(); ++i) {
				delete matrizes[i];
				matrizes[i] = nullptr;
			}
			matrizes.clear();
			break;
		}
		// cria [l] [c]
		else if(tokens[0] == "cria") {
            int l = std::stoi(tokens[1]);
            int c = std::stoi(tokens[2]);
            Matriz *m = new Matriz(l, c);
            for(int i = 0; i < l; ++i) {
                for(int j = 0; j < c; ++j) {
                    int val = 0;
                    cin >> val;
                    cin.ignore();
                    m->atribui(val, i, j);
                }
            }
			matrizes.push_back( m );
		}
		// imprime [k]
		else if(tokens[0] == "imprime") {
			int k = std::stoi(tokens[1]);
			matrizes[k]->imprime(7);
		}
		// nlinhas [k]
		else if(tokens[0] == "nlinhas") {
			int k = std::stoi(tokens[1]);
			cout << "linhas: " << matrizes[k]->linhas() << endl;
		}
        // ncolunas [k]
		else if(tokens[0] == "ncolunas") {
			int k = std::stoi(tokens[1]);
			cout << "colunas: " << matrizes[k]->colunas() << endl;
		}
        // valor [i] [j] [k]
		else if(tokens[0] == "valor") {
			int k = std::stoi(tokens[3]);
            int i = std::stoi(tokens[1]);
            int j = std::stoi(tokens[2]);
			cout << "valor: " << matrizes[k]->valor(i,j) << endl;
		}
		// soma [p] [q] 
		else if(tokens[0] == "soma") {
            int p = std::stoi(tokens[1]);
            int q = std::stoi(tokens[2]);
			Matriz *C = matrizes[p]->soma(matrizes[q]);
			if(C == nullptr) 
                cout << "nao foi possivel somar" << endl;
            else {
                C->imprime(7);
                delete C;
            }
		}
        // multiplica [p] [q] 
		else if(tokens[0] == "multiplica") {
            int p = std::stoi(tokens[1]);
            int q = std::stoi(tokens[2]);
			Matriz *C = matrizes[p]->multiplica(matrizes[q]);
			if(C == nullptr) 
                cout << "nao foi possivel multiplicar" << endl;
            else {
                C->imprime(7);
                delete C;
            }
		}
		else {
			cout << "comando inexistente" << endl;
		}
	}
	return 0;
}