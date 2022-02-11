#include <iostream>
using namespace std;

int main(){
int n1, ord[n1];
cin >> n1;
for(int i = 0;i < n1;i++){
    cin >> ord[i];
    if(ord[i-1]>ord[i]){
        cout << "precisa de ajuste" << endl;
        return 0;
    }
}
cout << "ok" << endl;

    return 0;
}