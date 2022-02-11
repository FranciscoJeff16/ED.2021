#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
#include <iostream>

// Define um tipo de dado chamado Item,
// que é apenas um apelido para int
typedef int Item;

/*******************************************
 * Definição do struct Node
 *******************************************/
struct Node {
    Item data;    
    Node *prox;  

    // Construtor do struct Node
    // Obs.: Em C++ os structs tambem podem ter construtores,
    // destrutores ou quaisquer outras funcoes que voce quiser.
    Node(const Item& k, Node *proxnode = nullptr) {
        data = k;
        prox = proxnode;
    }
};

/*****************************************
 * Declaração da classe LinkedList
 *****************************************/
class LinkedList {
private:
    Node* m_head; // ponteiro para o primeiro elemento
    int m_size;   // número de elementos na lista

public:
    // Construtor
    LinkedList(); 

    // Destrutor
    ~LinkedList(); 

    // Devolve true se e somente se a lista estiver cheia
    bool empty();

    // Deixa a lista vazia, com zero elementos
    void clear();

    // Retorna o número de elementos atualmente na lista 
    int size();

    // adiciona elemento no final da lista
    void push_back(Item data);

    // remove elemento do final da lista
    void pop_back();

    // insere um elemento na posição index
    void insert(int index, Item data);

    // remove o elemento na posição index
    void remove(int index);
    
    // operador de indexação sobrecarregado como função-membro da classe
    Item& operator[](int index);

    // operador<< sobrecarregado como função global friend 
    friend std::ostream& operator<<(std::ostream& out, const LinkedList& l);  

    
    void concat(LinkedList& lst);
    
    void removeAll(const Item& x);
    
    LinkedList *clone();
    
    void appendArray(Item v[], int n);
    
    bool equals(const LinkedList& lst);
    
    void reverse();
};

/***************************************************
 * Implementação das funções-membro da classe
 ***************************************************/

// Constructor: the linked list
// initializes empty
LinkedList::LinkedList() {
    m_size = 0;
    m_head = nullptr;
}

// Returs true if and only if the 
// list is empty
bool LinkedList::empty() {
    return m_head == nullptr;
}

// Empty the list and frees memory
void LinkedList::clear() {
    while(m_head != nullptr) {
        Node *temp = m_head;
        m_head = m_head->prox;
        delete temp;
    }
    m_size = 0;
}

// Returns the size of the list
int LinkedList::size() {
    return m_size;
}

// Adds an element at the end of the list
void LinkedList::push_back(Item data) {
    Node *newnode = new Node(data, nullptr);
    if(m_head == nullptr) {
        m_head = newnode;
    } else {
        Node *atual = m_head;
        while(atual->prox != nullptr) {
            atual = atual->prox;
        }
        atual->prox = newnode;
    }
    m_size++;
}

// Deletes an element from the end of the list
void LinkedList::pop_back() {
    if(m_head == nullptr) {
        throw std::underflow_error("empty list");
    }
    if(m_head->prox == nullptr) {
        delete m_head;
        m_head = nullptr;
        m_size = 0;
        return;
    }
    Node *atual = m_head;
    while(atual->prox->prox != nullptr) {
        atual = atual->prox;
    }
    delete atual->prox;
    atual->prox = nullptr;
    m_size--;
}

// Inserts data at any position in the range [0..size()]
void LinkedList::insert(int index, Item data) {
    if(index < 0 || index > m_size) {
        throw std::out_of_range("index out of range");
    }
    if(index == 0) {
        Node *newnode = new Node(data, m_head);
        m_head = newnode;
        m_size++;
        return;
    }
    int counter = 0;
    Node *atual = m_head;
    while(counter < index-1) {
        counter++;
        atual = atual->prox;
    }
    Node *newnode = new Node(data, atual->prox);
    atual->prox = newnode;
    m_size++;
}

// Deletes data at any position in the range [0..size()-1]
void LinkedList::remove(int index) {
    if(index < 0 || index >= m_size) {
        throw std::out_of_range("index out of range");
    }
    if(index == 0) {
        Node *temp = m_head;
        m_head = m_head->prox;
        delete temp;
        m_size--;
        return;
    }
    int counter = 0;
    Node *atual = m_head;
    while(counter < index-1) {
        counter++;
        atual = atual->prox;
    }
    Node *temp = atual->prox;
    atual->prox = atual->prox->prox;
    delete temp;
    m_size--;
}

// Destructor
LinkedList::~LinkedList() {
    clear();
}

// operator[] overloaded
Item& LinkedList::operator[](int index) {
    if(index < 0 || index >= m_size) {
        throw std::out_of_range("index out of range");
    }
    int counter = 0;
    Node *atual = m_head;
    while(counter < index) {
        counter++;
        atual = atual->prox;
    }
    return atual->data;
}

// operator<< overloaded
std::ostream& operator<<(std::ostream& out, const LinkedList& list) {
    Node *atual = list.m_head;
    out << "[ ";
    while(atual != nullptr) {
        out << atual->data << " ";
        atual =atual->prox;
    }
    out << "]";
    return out;
}


// Concatena a lista atual com a lista lst passada por parametro.
// A lista lst nao eh modificada nessa operacao. Ela permanece intacta ao final.
// Por exemplo, sejam l1 = [ 1 2 3 4 ] e l2 = [ 7 9 8 ]
// Após fazer l1.concat(l2) você deve obter
// l1 = [ 1 2 3 4 7 9 8 ] e l2 = [ 7 9 8 ]
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
void LinkedList::concat(LinkedList& lst) {
    // TODO
    if (lst.m_head == nullptr) {
       throw std::out_of_range("list empty");
    }
    Node *novaLista = lst.m_head;
    for(;novaLista != nullptr;novaLista = novaLista->prox) {
        Node *temp = m_head;
        Node *aux = new Node(novaLista->data,nullptr);

        if(temp != nullptr) {
              while(temp->prox != nullptr) {
                    temp = temp->prox;
            }
            temp->prox = aux;
            } else {
                 m_head = aux;
            }
        }
    } 

// Remove da lista todas as ocorrencias do Item x.
// Se a lista estiver vazia, esta funcao nao faz nada;
// Restricao: Esta funcao deve ter complexidade O(n) no pior caso.
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
void LinkedList::removeAll(const Item& x) {
    // TODO
    if(empty()){
       throw std::underflow_error("empty list");
    }
    //se tamanho do vetor for 1
    while(m_head->data == x){
        if(m_size == 1){
            m_head = nullptr;
            m_size--;
            return;
        }
        m_head = m_head->prox;
        m_size--;  
    }
    // se vetor for maior que 1
    if(m_size > 1){
        Node *aux = m_head;
        int i = 0;
        while(i < m_size-2){
            if(aux->prox->data == x){
                aux->prox = aux->prox->prox;
                m_size--;
                i--;
            }else{
                aux = aux->prox;
            }
            i++;
        }
        if(aux->prox->data == x){
            aux->prox = nullptr;
            m_size--;
        }
    }
}
/*void LinkedList::removeAll(const Item& x) {
    // TODO
      if(this->m_head->next == nullptr){ 
        std::cout << "Lista vazia" << std::endl;
        return;
    }
        else if(m_head != nullptr){
            Node *aux = m_head;
        int i = 0;
        while(i < m_size-2){
            if(aux->next->data == x || m_head->data == x){
                aux->next = aux->next->next;
                m_size--;
                i--;
            }else{
                aux = aux->next;
            }
            i++;
        } 
        if(aux->next->data == x){
            aux->next = nullptr;
            m_size--;
        }
    }
}*/

// Devolve um ponteiro para uma copia desta lista.
// Veja que uma copia nao eh a mesma lista, ela contem uma copia dos dados
// Esta funcao deve ter complexidade O(n) no pior caso
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
LinkedList *LinkedList::clone() {
    // TODO
    LinkedList *novaLista = new LinkedList();
    Node *aux = this->m_head;
    novaLista->push_back(aux->data);
    while(aux->prox != nullptr){
        novaLista->push_back(aux->prox->data);
        aux = aux->prox;
    }
    return novaLista;
}


// Copia os elementos do array v[0..n-1] para o final da lista. 
// Esta funcao deve ter complexidade O(n) no pior caso
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
void LinkedList::appendArray(Item v[], int n) {
    // TODO    
    for(int i = 0; i < n; i++){
        push_back(v[i]);
    }
}

// Determina se a lista lst, passada por parametro, eh igual 
// a lista em questao. Duas listas sao iguais se elas tem o mesmo tamanho 
// e o valor do k-esimo elemento da primeira lista eh igual ao 
// k-esimo valor da segunda lista.
// Restrição: está proibido usar funções auxiliares nesta questão,
// inclusive qualquer dos operadores sobrecarregados
bool LinkedList::equals(const LinkedList& lst) {
    // TODO
    if(m_size != lst.m_size){
        return false;   
    }else{
     Node *aux = m_head;
     Node *aux2 = lst.m_head;
    while(aux->prox != nullptr){
        if(aux->prox->data != aux2->prox->data){
            return false;
        }
        aux = aux->prox;
        aux2 = aux2->prox;
    }
        return true;
    }
}

// Inverte a ordem dos nós (o primeiro node passa a ser o último, 
// o segundo passa a ser o penultimo, etc.) 
// Restricao: Essa operacao faz isso sem criar novos nodes, apenas altera os ponteiros.
// Voce pode criar ponteiros auxiliares (um número constante deles), 
// mas nao pode alocar novos nós.
// Repetindo: está proibido chamar o operador new nesta questão.
// Restrição: Também não é permitido usar funções auxiliares nesta questão
void LinkedList::reverse() {
    // TODO
    Node* pre  = nullptr;
    Node* prox;
   for(Node* agora = m_head;agora != nullptr; agora = prox) {
        prox  = agora->prox;
        agora->prox = pre;   
        pre = agora;
   }
   m_head = pre;
}

#endif