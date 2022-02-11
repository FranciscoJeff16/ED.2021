#include<iostream>
#include<queue>
using namespace std;
#include <iostream>
#include <queue>
#include <stdexcept>

using namespace std;

// Função que verifica qual time passa de fase e imprime o time que ganhou
queue<char> timeCamp(char competidor1, char competidor2, int golsCompetidor1, int golsCompetidor2,queue<char> compt);

int main(){
    queue<char>compt ;
    char times = 'A'; // Para mudar os times
    // Salva todos os 16 times da copa na fila
    for(char i = 0; i < 16; i++){
        compt.push(times);
        times+=1;
    }

    //atrasves dos resultados faço ...
    while(compt.size() != 1){
        char time1, time2;
        int gols1, gols2;  
        cin>> gols1 >> gols2;
        time1 = compt.front();
        compt.pop();
        time2 = compt.front();
        compt.pop();
        timeCamp(time1,time2,gols1,gols2,compt);
    }
    cout<<compt.front()<<'\n';
}
queue<char> timeCamp(char competidor1, char competidor2, int golsCompetidor1, int golsCompetidor2, queue<char> compt){
    if(golsCompetidor1 < golsCompetidor2){
        compt.push(competidor2);
    }else{
        compt.push(competidor1);
    }
    return compt;
}