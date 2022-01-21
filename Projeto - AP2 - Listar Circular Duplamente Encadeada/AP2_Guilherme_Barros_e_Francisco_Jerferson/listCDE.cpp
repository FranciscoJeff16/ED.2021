//Guilherme Barros Vieira de Araujo     Matricula: 509873
//Francisco Jerferson Martins da Silva  Matricula: 502002
#include <vector>
#include "listCDE.h"
#include <iostream>
#include <stdexcept>

//M_head vai ser usado apenas como parâmetro, ou seja, não será usado nas operações de troca.
//g++ -Wall *.cpp -o main; ./main
using namespace std;

typedef int Item;

List::List(){
    //Criando um no sentinela, apenas para o "next", o "last" e o "end", apontarem para ele de inicio.
    m_head = new Node();
    m_head->next = m_head;
    m_head->last = m_head;
    m_end = m_head;
    //Valor simbólico atribuido ao "data", não vai interferir no código, já que o nó sentinela é apenas um "auxiliar".
    m_head->data = -22;
    m_size = 0;
}

List::~List(){
    //Checar se não está vazio.
    if(!empty()){
        Node *deletar = m_head->last;
        Node *correr = deletar->last;
    //Deletando de tras para frente, para evitar conflito com o m_head.
        while(deletar != m_head){
            delete deletar;
            deletar = correr;
            correr = correr->last;
        }
    }
    //Deletar o m_head, já que é um destrutor no final das contas.
    delete m_head;
    //Ajustes de tamanho.
    m_size = 0;
}

List::List(const List& lst){
    Node *percorrer = lst.m_head->next;
    while(percorrer != lst.m_head){
        push_back(percorrer->data);
        percorrer = percorrer->next;
    }
    percorrer = nullptr;
    delete percorrer;
}

bool List::empty() const{
    //Utilizando m_size ao invés dos nos, para ficar mais simples.
    return(m_size == 0);
}

size_t List::size() const{
    return m_size;
}

void List::clear(){
    //Clear tem a mesma lógica do delete só que por não deletar o no sentinela, tem que se ajustar os auxiliares.
    if(!empty()){
        Node *deletar = m_head->last;
        Node *correr = deletar->last;
    //Percorrendo toda a lista e deletando todos os elementos, exceto m_head.
        while(deletar != m_head){
            delete deletar;
            deletar = correr;
            correr = correr->last;
        }
    //Garantindo a circularidade da lista, ja que o m_head ainda esta na lista.
        m_head->next = m_head;
        m_head->last = m_head;
        m_end = m_head;
    }
    m_size = 0;
}

Item& List::front(){
    if(!empty()){
        return m_head->next->data;
    }else{
        throw std::out_of_range("empty list");
    }
    
}

Item& List::back(){
    if(!empty()){
        return m_head->last->data;
    }else{
        throw std::out_of_range("empty list");
    }
}

void List::push_front(const Item& data){
    //Novo no que vai ser inserido.
    Node *front = new Node;
    front->data = data;
    //Salvar o primeiro elemento para fazer o next.
    Node *primeiro = m_head->next;

    //Circularidade.
    primeiro->last = front;
    m_head->next = front;

    front->next = primeiro;
    front->last = m_head;

    //Circularidade do tail.
    m_end = m_head->last;
    m_end->next = m_head;
    m_end->last = m_head->last->last;
    //Ajuste de Tamanho.
    m_size++;
}

void List::push_back(const Item& data){
    //Novo no que vai ser inserido.
    Node *back = new Node;
    back->data = data;
    
    //Salvar o ultimo elemento para fazer o next.
    Node *ultimo = m_head->last; 
    
    //Circularidade.
    ultimo->next = back;
    m_head->last = back;
    
    back->next = m_head;
    back->last = ultimo;

    // Circularidade com o tail.
    m_end = m_head->last;
    m_end->next = m_head;
    m_end->last = ultimo;

    //Ajustes de tamanho.
    m_size++;
}


void List::pop_front(){
    if(!empty()){
        Node *deletar = m_head->next;
        m_head->next = m_head->next->next;
        m_head->next->last = m_head;
        m_size--;
        delete deletar;
    }
}

void List::pop_back(){
    if(!empty()){
    //Como o ultimo elemento vai ser deletado, teremos que modificar o elemento antes dele
    //para manter a circularidade.
        Node *deletar = m_end;
        Node *antes = m_end->last;

        m_end = antes;
        m_head->last = m_end;
        m_head->last->next = m_head;

        m_end->next = m_head;
    //Verificando se tem um antepenultimo elemento.
        if(m_head->last == m_head ){
            m_end->last = m_head;
        }else{
            m_end->last = m_head->last->last; 
        }
    //Desalocando memória.  
        delete deletar;
        antes = nullptr;
        delete antes;
    //Ajuste de tamanho.
        m_size--;
    }
}
//Duvida, perguntar para o professor.
void List::insertAt(const Item& data, int index){
    if(index < 0 || index > m_size) {
        throw std::out_of_range("index out of range");
    }
    if(index == 0){
        push_front(data);
        return;
    }
    if(index == m_size){
        push_back(data);
        return;
    }
    int contador = 0;
    Node *correndo = m_head->next;
    while(contador < index-1){
        contador++;
        correndo = correndo->next;
    }
    Node *novo = new Node;
    novo->data = data;
    novo->next = correndo;
    novo->last = correndo->last;
    
    correndo->last->next = novo;
    correndo->last = novo;
    m_size++;
}

Item List::removeAt(int index){
    if(index < 0 || index > m_size - 1){
        throw std::out_of_range("index out of range");
    }
    int contador = 0;
    int guardar = 0;
    if(index == 0){
        guardar = m_head->next->data;
        pop_front();
        contador = index;
    }else{
        Node *correndo = m_head->next->next;
        while(contador <index-1){
            contador++;
            correndo = correndo->next;
    }
        Node *deletar = correndo;
        guardar = correndo->data;
        correndo->last->next = correndo->next;
        correndo->next->last = correndo->last; 

        delete deletar;
        m_size--;
    }
    return guardar;
}

void List::removeAll(const Item& data){
    if(!empty()){
        while(m_head->next->data == data){
            pop_front();
        }
        while(m_head->last->data == data){
            pop_back();
        }
        Node *percorrer = m_head->next;
        while(percorrer != m_head){
            if(percorrer->data == data){
                percorrer->last->next = percorrer->next;
                percorrer->next->last = percorrer->last;
                Node *deletar = percorrer;
                percorrer = percorrer->next;
                delete deletar;
                m_size--;
            }else{
                percorrer = percorrer->next;
            }
        }
    }
}

void List::swap(List& lst){
    //Criando uma copia de lst, para ficar de auxiliar de trocas.
    List *copia = lst.copy();
    lst.clear();
    
    // Trocando os elementos de lst pelos elementos de m_head.
    Node *percorrer = m_head->next;
    while(percorrer != m_head){
        lst.push_back(percorrer->data);
        percorrer = percorrer->next;
    }
    lst.m_size = m_size;
    //Desalocando memória.
    percorrer = nullptr;
    delete percorrer;
   
   //Trocando os elementos de m_head pelos elementos da lista de parametro.
    clear();
    Node *caminhar = copia->m_head->next;
    while(caminhar != copia->m_head){
        push_back(caminhar->data);
        caminhar = caminhar->next;
    }
    m_size = copia->m_size;
    //Desalocando memória.
    caminhar = nullptr;
    delete caminhar;
}


void List::concat(List& lst){
    Node *percorrer = lst.m_head->next;
    while(percorrer != lst.m_head){
        push_back(percorrer->data);
        percorrer = percorrer->next;
    }
    lst.clear();
    percorrer = nullptr;
    delete percorrer;
}

List *List::copy(){
    List *copia = new List;
    if(!empty()){
        Node *percorrer = m_head->next;
        while(percorrer != m_head){
            copia->push_back(percorrer->data);
            percorrer = percorrer->next;
        }
        copia->m_size = m_size;
    }
    return copia;
}

void List::append(Item vec[], int n){
    int i = 0;
    while(i != n){
        push_back(vec[i]);
        i++;
    }
}

bool List::equals(const List& lst) const{
    if(lst.m_size != m_size){
        return false;
    }else{
        Node *correr = m_head->next;
        Node *acompanhar = lst.m_head->next;

        while(correr != m_head){
            if(correr->data != acompanhar->data){
                return false;
            }
            correr = correr->next;
            acompanhar = acompanhar->next;
        }
        return true;
    }
}

void List::reverse(){
    //Caso Nulo.
    if(m_head->next == m_head){
        
        return;
    }
    //Caso Geral.
    Node *inicio = m_head->next;
    Node *fim = m_head->last;
       
       int voltas = m_size/2;

    //Os numeros vao ser trocados entre-si "voltas" vezes.
        while(voltas != 0){
            voltas--;
            
            int trocar = inicio->data;
            
            inicio->data = fim->data;
            fim->data = trocar;

            inicio = inicio->next;
            fim = fim->last;
            
        }
        
    //Desalocando memoria.
        inicio = nullptr;
        fim = nullptr;
        delete inicio;
        delete fim;
    }

void List::merge(List& lst){
    if(empty()){
        swap(lst);
    }
    if(lst.empty()){
        return;
    }
    //criando um novo no para receber o resultado.
    List *copia = lst.copy();
    copia->clear();
    int voltas = 0;
    Node *frente = m_head->next;
    Node *costas = lst.m_head->next;
    
    if(m_size > lst.m_size){
        voltas = m_size;
    }else{
        voltas = lst.m_size;
    }
    while(voltas != 0){
        if(frente != m_head){
            copia->push_back(frente->data);
            frente = frente->next;
        }
        if(costas != lst.m_head){
            copia->push_back(costas->data);
            costas = costas->next;
        }
        voltas--;
    }
    int guardar = m_size + lst.m_size;
    lst.clear();
    clear();
    
    Node *fim = copia->m_head->next;
    while(fim != copia->m_head){
        push_back(fim->data);
        fim = fim->next;
    }
    m_size = guardar;


    frente = nullptr;
    costas = nullptr;
    fim = nullptr;
    delete copia;
    delete frente;
    delete costas;
    delete fim;
}

std::ostream& operator<<(std::ostream& out, const List& lst){
    out << "[ ";
    if(!lst.empty()){
        Node *percorrer = lst.m_head->next;
        while(percorrer != lst.m_head){
            out << percorrer->data << " ";
            percorrer = percorrer->next;
        }
    }
    return out << "]";
}

Item& List::operator[](int index){
    if(index < 0 || index >= m_size) {
        throw std::out_of_range("index out of range");
    }
    int contador = 0;
    Node *correndo = m_head->next;
    while(contador < index) {
        contador++;
        correndo = correndo->next;
    }
    return correndo->data;
}

//Ajustar.
List& List::operator=(const List& lst){
    clear();
    Node *correndo = lst.m_head->next;

    while(correndo != lst.m_head){
        push_back(correndo->data);
    } 
    return *this;
} 