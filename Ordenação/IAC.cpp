#include<iostream>
#include<chrono>

using namespace std;

int main(){
auto start = std::chrono::high_resolution_clock::now();
int i; // Endereco de memoria 0000000000
int cont = 0; // Endereco de memoria 0000000100
int ac = 0; // Endereco de memoria 0000001000
char vet[100]; // Endereco de memoria 0100000000
for(i = 0; i < 100; i++){
    ac = ac + vet[i];
    cont++;
}
cout << cont << " valores somados e acumulando " << ac <<" no total" << endl;
auto end = std::chrono::high_resolution_clock::now();
auto int_s = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
cout << int_s.count() <<" nanoseconds" << endl;
}

