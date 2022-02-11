#include <iostream>
using namespace std;

bool primo(int n1);

int main(){
    int inicio, fim;
    cin >> inicio >> fim;
    for(int j = inicio;j <= fim;j++){
         if(primo(j)==true){
             cout << j << endl;
         }
    }
   
    return 0;
}

bool primo(int n1){
    for(int i = 2;i <= n1-1; i++){
        if(n1%i==0)
            return false;
    }
}