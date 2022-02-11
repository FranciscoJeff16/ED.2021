#include <iostream>
#include <algorithm>
using namespace std;


int tam;
int vet[1000];

void reverse(int r) {
 int i = 1;
    int j = r;
    while(i < j){
    //trocando elementos
    swap(vet[i], vet[j]);
    i++, j--;
  }
}

void Paux(int n) {
  if (n < 1) return;
  int pos = -1;
  for (int i = 1; i <= n; i++) {
    if (vet[i] == n) {
      pos = i;
      break;
    }
  }
  if (pos == n) {
    Paux(n-1);
  } else {
    if (pos != 1) {
      int posEs = tam-pos+1;
      cout << posEs << ' ';
      reverse(pos);
    }
    cout << tam-n+1 << ' ';
    reverse(n);
    Paux(n-1);
  }
}


int main() {
  cin >> tam;

  for (int i = 1; i <= tam; ++i) {
    cin >> vet[i];
  }

  Paux(tam);
  cout << "0\n";
}