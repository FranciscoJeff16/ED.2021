#include <iostream>
#include <iomanip>

using namespace std;

struct aluno{
    int matric;
    char nome[100];
    double media;
};

int main(){
int n1, matricula;//tamanho e matricula a ser procurada 
 cin >> n1;
aluno turma[n1];
//lendo dados
for(int i = 0;i < n1;i++){
    cin >> turma[i].matric;
       cin.ignore();
       cin.get(turma[i].nome, 100); 
    cin >> turma[i].media;
}
cin >> matricula; // lendo amtricula a ser procurada
//comparando e imprimindo 
for(int i = 0;i < n1;i++){
  if(matricula == turma[i].matric){
      cout << turma[i].nome << endl << setiosflags(ios::fixed) << setprecision(1) << turma[i].media << endl;
      return 0;
  }
  }
  cout << "NAO ENCONTRADA" << endl;
    return 0;
}