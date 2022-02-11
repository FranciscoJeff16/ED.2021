#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
  
void sortArr(int vet[], int n){
    //Utilizando a estrutura de pares
    vector<pair<int, int> > vp;
    // Inserting element in pair vector
    // to keep track of previous indexes
    for (int i = 0; i < n; ++i) {
        vp.push_back(make_pair(arr[i], i));
    }
    // Sorting pair vector
    sort(vp.begin(), vp.end());
  
    // Displaying sorted element
    // with previous indexes
    // corresponding to each element
    for (int i = 0; i < vp.size(); i++) {
        cout << vp[i].second << " ";
    }
}
  
// Driver code
int main(){
    int tam;
    cin >> tam;
    int vet[tam];
    for (int i = 0; i < tam; i++){
        cin >> vet[i];
    }
        sortArr(vet, tam);
  
    return 0;
}