#include <iostream>
#include <iomanip>

using namespace std;

double fatorial(int fat);
double euler(int fato);

int main(){
    int n1;
    cin >>n1;
    cout << fixed << euler(n1) << endl;
    return 0;
}

double fatorial(int fat){
    double rest=1.0;
    for(int i=1;i<=fat;i++){
        rest=rest*i;
    }
    return rest;
}

double euler(int fato){
	double e=1.0;
	for(int i=1;i<=fato;i++){
		e=e+1.0/fatorial(i);
	}
	return e;
}