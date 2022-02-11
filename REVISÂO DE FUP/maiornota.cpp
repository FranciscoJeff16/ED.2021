#include <iostream>
#include <iomanip>

using namespace std;

struct Aluno{
    char nome[100];
    int matricula;
    char disciplina[120];
    double nota;
};

Aluno maior(Aluno primeiro, Aluno segundo);

int main(){
Aluno primeiro,segundo;
//lendo primeiro aluno
cin >> primeiro.nome;
cin.ignore();
cin >> primeiro.matricula;
cin.ignore();
cin >> primeiro.disciplina;
cin.ignore();
cin >> primeiro.nota;

//lendo segundo aluno
cin >> segundo.nome;
cin.ignore();
cin >> segundo.matricula;
cin.ignore();
cin >> segundo.disciplina;
cin.ignore();
cin >> segundo.nota;
maior(primeiro,segundo);
return 0;
}

Aluno maior(Aluno primeiro, Aluno segundo){
    if(primeiro.nota > segundo.nota){
        cout << primeiro.nome << " , " << setiosflags(ios::fixed) << setprecision(1) << primeiro.nota << endl;
    } else if(segundo.nota > primeiro.nota){
        cout << segundo.nome << " , " << setiosflags(ios::fixed )<< setprecision(1) << segundo.nota << endl;
    }else if(primeiro.nota == segundo.nota){
        cout << primeiro.nome << " e " << segundo.nome << " , " << setiosflags(ios::fixed ) << setprecision(1) << segundo.nota << endl;
    }
}