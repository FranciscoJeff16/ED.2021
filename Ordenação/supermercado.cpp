#include <iostream>
#include <vector>
using namespace std;
 

void selectionSort(vector<pair<int, string>> &vet, int n)
{
    for(int i = 0; i < n; i++){
        int imenor = i;
        for(int j = i+1; j < n; j++){
            if(vet[j] < vet[imenor]) imenor = j;
        }
        if(i != imenor){
            pair<int,string> aux = vet[i];
            vet[i] = vet[imenor];
            vet[imenor] = aux;
            
        }
    }
    
}
 
 
int main() {
 int n,m, p, q;
 cin >> n >> m >> p >> q;
 vector<pair<int,string>> aux;
 vector<pair<int,string>> vet(n);
 for(int i=0; i <n;i++){
     cin >> vet[i].second;
     cin >> vet[i].first;
 }
 vector<pair<int,string>> vet2(m);
 for(int i=0; i <m;i++){
     cin >> vet2[i].second;
     cin >> vet2[i].first;
 }
        selectionSort(vet, n);
        selectionSort(vet2, m);
         
        for(int i=0; i <p;i++){
           
            aux.push_back(vet[i]);
            
            
        }
        for(int i=0; i <q;i++){
         
            aux.push_back(vet2[i]);
        }  
         selectionSort(aux,p+q);
         for(int i=0; i <p+q;i++){
            cout << aux[i].second ;
            if(i < p+q-1){
               cout << " ";
            }
        }  
        cout << endl;
}