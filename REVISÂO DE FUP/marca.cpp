#include <iostream>
#include <string>

using namespace std;

int main(){
    int n1; //quantidade de produtos
     cin >> n1;
    int play1 = 0, play2 = 0; // respectivamente jogador 1 e jogador 2;
    float valor[n1];
    float chute[n1];
    string MaiorOuMenor[n1];
    
    for(int i = 0;i < n1;i++){
        cin >> valor[i];
    }
    for(int i = 0;i < n1;i++){
    	cin >> chute[i];
	}
    
    cin.ignore();
    for(int i = 0;i < n1;i++){
        cin >> MaiorOuMenor[i];
    }
    for(int i = 0;i < n1;i++){
           if((valor[i] > chute[i]) && (MaiorOuMenor[i] == "M"))
           play2++;
           else if((valor[i] < chute[i]) && (MaiorOuMenor[i] == "m")){
                   play2++;
               } else{
                   play1++;
               }
    }
   if (play1 == play2) 
    cout << "empate" << endl;
    else if (play1 > play2) 
     cout << "primeiro" << endl;
      else if (play1 < play2) 
       cout << "segundo" << endl;
} 