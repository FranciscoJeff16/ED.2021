#include<iostream>
#include<queue>

using namespace std;
// Verifica quais dos times fez mais gols
char verificaGols(char competidor1, char competidor2,int golsCompetidor1, int golsCompetidor2);

int main(){
    queue<char>compt ;
    char times = 'A'; // Para mudar os times
    // Salva todos os 16 times da copa na fila
    for(char i = 0; i < 16; i++){
        compt.push(times);
        times+=1;
    }

    // Verifica o time campeao
    while(compt.size() != 1){
        // representa os times de cada rodada
        char competidor1, competidor2;
        // Gols marcados por cada time;
        int golsCompetidor1, golsCompetidor2;  
        cin >> golsCompetidor1;
        cin >> golsCompetidor2;
        competidor1 = compt.front();
        compt.pop();
        competidor2 = compt.front();
        compt.pop();
        compt.push(verificaGols(competidor1, competidor2, golsCompetidor1, golsCompetidor2));
    }
    cout<<compt.front()<<'\n';
}
char verificaGols(char competidor1, char competidor2,int golsCompetidor1, int golsCompetidor2){
    if(golsCompetidor1 < golsCompetidor2){
        return competidor2;
    }else{
        return competidor1;
    }
}
