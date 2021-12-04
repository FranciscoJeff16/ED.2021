#include <iostream>
#include <sstream>
using namespace std;
using std::stringstream;

struct Vector {
    int capacity;
    int size;
    int * data;
};

Vector * vector_create(int capacity) {
    struct Vector *vet1 = new Vector;          //crie o struct vector dinâmicamente
    vet1->data = new (nothrow) int[capacity];  //crie o vetor data
    if(vet1->data == nullptr){
        return nullptr;
    }
    vet1->capacity = capacity;
    vet1->size = 0;                           //inicialize size e capacity
    return vet1;
}

void vector_destroy(Vector * vector) {
    delete [] vector->data;    //destrua data
    delete [] vector;          //destrua a struct
}

void vector_add(Vector * vector, int value) {
    //utilize capacity e size para verificar se ainda existe espaço
    if(vector->size < vector->capacity){
        vector->data[vector->size] = value;
        vector->size++;
    }else{
        cout << "Não há espaço, o espaçó máximo é: "<< vector->capacity << endl;
    }

}
//retorne a string no formato 
// [ a b c ]
string vector_show(Vector * vector) {
    stringstream ss,s1,s2,s3;
    ss << "[ ";
    for(int i = 0;i < vector->size;i++){
        ss << vector->data[i];
        if(i < vector->size - 1){
            ss << " ";
        }
    }
    ss <<" ]";
    return  ss.str(); 
    //retorne uma string com os dados do vetor
    //você pode usar uma stringstream como buffer
    //stringstream ss;
    //ss << 5 << " eh inteiro";
    //ss.str() será "5 eh inteiro"

}


/* NAO MEXA DAQUI PRA BAIXO */
int main() {
    string line, cmd;
    int value;
    Vector * v = vector_create(0);
    while(true) {
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        } else if(cmd == "init") {
            ss >> value;
            if(v != nullptr)
                vector_destroy(v);
            v = vector_create(value);
        } else if(cmd == "status") {
            cout << "size:" << v->size << " capacity:" << v->capacity << "\n";
        } else if(cmd == "add") {
            while(ss >> value)
                vector_add(v, value);
        } else if(cmd == "show") {
            cout << vector_show(v) << endl;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
    vector_destroy(v);
}