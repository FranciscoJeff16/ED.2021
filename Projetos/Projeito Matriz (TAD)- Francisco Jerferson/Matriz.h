// TAD: Matriz m por n
#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz {
    private:
        int lin;     // numero de linhas da matriz
        int col;     // numero de colunas da matriz
        int** matriz;   // matriz de inteiros (deve ser alocada dinamicamente)
    
    public:
        // Construtor: aloca matriz com l linhas e c colunas
        Matriz(int l, int c);

        // Destrutor: libera memoria alocada
        ~Matriz(); 

        // Retorna o numero de linhas da matriz
        int linhas();

        // Retorna o numero de colunas da matriz
        int colunas();  

        // Imprime matriz 
        // O parametro largura indica o parametro que eh passado para a 
        // funcao std::setw()
        void imprime(int largura);

        // Retorna o valor contido na celula [i][j] da matriz
        int valor(int i, int j); 

        // Atribui o valor v a celula [i][j] da matriz
        void atribui(int v, int i, int j); 

        // Recebe um ponteiro para o objeto B do tipo Matriz que possui
        // l linhas e c colunas e soma a matriz B com a matriz atual.
        // Lembre que a soma de uma matriz A com uma matriz B so eh possivel  
        // se o numero de linhas e de colunas de A for igual ao numero de 
        // linhas e de colunas de B, respectivamente. 
        // Se for possivel fazer a soma, um ponteiro para uma nova matriz C
        // contendo o resultado da soma deve ser retornado (note que a matriz C 
        // deve ser alocada dinamicamente dentro da funcao-membro).
        // Caso contrario, retorna nullptr indicando que nao foi possivel 
        // fazer a soma das matrizes. 
        Matriz *soma(Matriz *B); 

        // Recebe o ponteiro para o objeto B do tipo Matriz que possui
        // l linhas e c colunas e multiplica a matriz que chamar essa funcao-membro pela matriz B.
        // Lembre que a multiplicacao de uma matriz A por uma matriz B so eh possivel  
        // se o numero de colunas de A for igual ao numero de linhas de B. 
        // Se for possivel fazer a multiplicacao, um ponteiro para uma nova matriz C
        // contendo o resultado da multiplicacao deve ser retornado (note que a matriz C 
        // deve ser alocada dinamicamente dentro da funcao-membro).
        // Caso contrario, retorna nullptr indicando que nao foi possivel 
        // fazer a multiplicacao das matrizes. 
        Matriz *multiplica(Matriz *B);   
};

#endif
