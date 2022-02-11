#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Pos{
    int l;
    int c;
};
void show(vector<string>& mat);
//retorna um vetor com todos os vizinhos da posição p
vector<Pos> get_vizinhos(Pos p);
bool buscar(vector<string>& mat, Pos inicio, Pos dest);

int main(){
    int nl = 0, nc = 0;
    cin >> nl >> nc;
    vector<string> mat(nl, ""); //começa com nl strings ""
    getchar();//remove \n after nc
    Pos inicio, fim;
    //carregando matriz
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);
    //procurando inicio e fim e colocando ' ' nas posições iniciais
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == 'I'){
                mat[l][c] = ' ';
                inicio = Pos {l, c};
            }
            if(mat[l][c] == 'F'){
                mat[l][c] = ' ';
                fim = Pos {l, c};
            }
        }
    }
    buscar(mat,inicio, fim);
     for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(mat[l][c] == '-'){
                mat[l][c] = ' ';
            }
        }
    
    }
    show(mat);
}
void show(vector<string>& mat){
     for(string line : mat){
        cout << line << endl;
     }
}
vector<Pos> get_vizinhos(Pos p){
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}
bool buscar(vector<string>& mat, Pos inicio, Pos dest){
    stack<Pos> p;
    //stack<Pos> c;
    int aux = 0;
    p.push(inicio);
    //c.push(inicio);

    while(p.top().l != dest.l || p.top().c != dest.c){
        if(p.empty()){
            return false;
        }else{
            Pos atual = p.top();
            mat[atual.l][atual.c]='.';
            for(auto viz : get_vizinhos(atual)){
              if(mat[viz.l][viz.c]==' '){
                  aux = 1;
                  p.push(viz);
                  break;
              }  
            }
            if(aux == 0){
                mat[atual.l][atual.c]='-';
                p.pop();
            }
            aux = 0;
        }

    }
    mat[p.top().l][p.top().c] = '.';
    return true;
}