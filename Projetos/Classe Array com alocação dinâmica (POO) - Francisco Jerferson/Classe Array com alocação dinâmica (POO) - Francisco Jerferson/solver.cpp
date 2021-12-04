#include <iostream>
#include <sstream>
#include "Array.h"
using namespace std;

/* NAO MEXA DAQUI PRA BAIXO */
int main(){
    string line, cmd;
    int value;
    Array v(0);
    while(true){
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        } else if(cmd == "init"){
            ss >> value;
            v = Array(value);
        } else if(cmd == "status"){
            cout << " capacity:" << v.getCapacity() << "\n";
        } else if(cmd == "insert"){
            int index;
            ss >> value;
            ss >> index;
            v[index] = value;
        } else if(cmd == "show"){
            cout << v << endl;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
}