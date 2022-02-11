#include <iostream>

using namespace std;

struct Aluno{
    char nome[80];
    int matricula;
    char disciplina[120];
    double nota;
};

Aluno mostrar(Aluno primeiro);

int main(){
Aluno primeiro;
cin >> primeiro.nome;
cin.ignore();
cin >> primeiro.matricula;
cin.ignore();
cin >> primeiro.disciplina;
cin.ignore();
cin >> primeiro.nota;
mostrar(primeiro);
return 0;
}
Aluno mostrar(Aluno primeiro){
    if(primeiro.nota >= 7){
        cout << primeiro.nome << " aprovado(a) em " << primeiro.disciplina << endl;
    }else if(primeiro.nota < 7){
         cout << primeiro.nome << " reprovado(a) em " << primeiro.disciplina << endl;
    }
    
}
