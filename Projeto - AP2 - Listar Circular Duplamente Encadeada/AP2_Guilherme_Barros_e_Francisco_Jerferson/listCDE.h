//Guilherme Barros Vieira de Araujo     Matricula: 509873
//Francisco Jerferson Martins da Silva  Matricula: 502002

#ifndef LISTCDE_H
#define LISTCDE_H
#include <stdexcept>
#include <iostream>

// Define um tipo de dado chamado Item, nome relativo de variavel int.
typedef int Item;

struct Node {
    Item data;
    Node *last;
    Node *next;
     
};


class List{
    private:
    Node *m_head; // Ponteiro para o primeiro elemento.
    Item m_size; // Numero de elementos na lista.
    Node *m_end;
    
    public:
    //Construtor vazio
    List();

    //Destrutor
    ~List();

    //Construtor de copia
    List(const List& lst);
    
    //Verifica se a lista esta vazia
    bool empty() const;

    //Retorna o numero de nos
    size_t size() const;

    //Limpa a lista
    void clear();

    //Retorna a referencia para o primeiro elemento da lista
    Item& front();

    //Retorna uma referencia para o ultimo elemento na lista.
    Item& back();

    //Adiciona um Item no inicio da lista.
    void push_front(const Item& data);

    //Adiciona um Item ao final da lista.
    void push_back(const Item& data);

    //Remove o elemento no inicio da lista.
    //Se a lista estiver vazia, essa funcao deve lancar uma excecao (exception).
    void pop_front();

    //Remove o elemento no final da lista. 
    //Se a lista estiver vazia, essa funcao deve lancar uma excecao (exception).
    void pop_back();

    //Insere um novo Item na posicao index da lista.
    void insertAt(const Item& data, int index);
    
    //Remove o elemento na posicao index da lista e retorna o seu valor.
    Item removeAt(int index);

    //Remove da lista todas as ocorrencias do elemento data passado como parametro.
    void removeAll(const Item& data);

    //Troca o conteudo da lista com o conteudo da lista lst.
    void swap(List& lst);
    
    //concat a lista atual com a lista lst passada por parametro.
    void concat(List& lst);

    //Retorna um ponteiro para uma copia desta lista.
    List *copy();
    
    //Copia os elementos de um array e insere na lista
    void append(Item vec[], int n);

    //Compara duas listas e retorna se sao iguais ou nao
    bool equals(const List& lst) const;

    //Inverte a ordem dos elementos da lista
    void reverse();

    //Intercala os elementos da lista original com a lista recebida
    void merge(List& lst);
    
    //Sobrecarrega o operador de inserçao (<<)
    friend std::ostream& operator<<(std::ostream& out, const List& lst);

    //Sobrecarrega o operador de indexaçao ([])
    Item& operator[](int index);

    //Sobrecarrega o operador de atribuiçao
    List& operator=(const List& lst);


    
};

#endif