//Guilherme Barros Vieira de Araujo     Matricula: 509873
//Francisco Jerferson Martins da Silva  Matricula: 502002

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "listCDE.h"
using namespace std;

int main() {

    vector<List*> listas;
    string comand;
    comand += " _____________________________________________________________________\n";
    comand += "|                         Painel de Comandos                          |\n";
    comand += "|_____________________________________________________________________|\n\n";
    comand += "              Digite o comando desejado e seus parametros                \n";
    comand += "             *comando pode ser digitado letras minusculas*               \n";
    comand += "______________________________________________________________________\n";
    comand += "                         Comandos de operacao                         \n";
    comand += "Mostrar  - Mostra na tela as listas ja criadas (Parametros: comando)\n"; //Estressed Test 1/22
    comand += "Sair     - Fecha o programa (Parametros: comando)\n"; // Estressed Test 2/22
    comand += "Criar    - Cria uma nova lista circular duplamente encadeada (Parametros: comando)\n"; // Estressed Teste 3/22
    comand += "______________________________________________________________________\n";
    comand += "                         Comandos de insercao                          \n";
    comand += "AddPrim  - Adiciona elemento no inicio da lista\n"; // Estressed Test 4/22
    comand += "           Parametros: comando, elemento e lista - E.g.: addprim 12 0\n";
    comand += "AddUlt   - Adiciona elemento no fim da lista\n";   // Estressed Test 5/22
    comand += "           Parametros: comando, elemento e lista - E.g.: addult 12 0\n";
    comand += "Inserir  - Insere um elemento na posicao desejada\n"; //Estressed Test 6/22
    comand += "           Parametros: comando, lista, elemento e indice - E.g: inserir 0 12 1\n";
    comand += "Vetor    - Adiciona os elementos do vetor passado como parametro no final da lista\n";
    comand += "           Parametros: comando, lista e elementos - E.g.: vetor 0 12 112 21 21\n"; // Estressed Test 7/22
    comand += "______________________________________________________________________\n";
    comand += "                         Comandos de remocao                          \n";
    comand += "Deletar  - Deleleta os elementos da lista passada como parametro\n"; //Estressed Test 8/22
    comand += "           Parametros: comando e lista - E.g.: deleta 0\n"; 
    comand += "DltPrim  - Deleta o primeiro elemento da lista\n"; // Estressed Test 9/22
    comand += "           Parametros: comando e lista - E.g.: dltprim 0\n"; 
    comand += "DltUlt   - Deleta o ultimo elemento da lisat\n";  // Estressed Test 10/22
    comand += "           Parametros: comando e lista - E.g.: dltult 0\n";  
    comand += "Remover  - Remove o elemento da posicao desejada de uma lista especifica\n"; // Estressed Test 11/22
    comand += "           Parametros: comando, lista e indice - E.g.: remove 0 1\n";
    comand += "RemoveAl - Remove todas as ocorrencias do elemento desejado de uma lista especifica\n"; //Estressed Test 12/22
    comand += "           Parametros: comando, elemento e lista - E.g.: removeal 12 0\n";
    comand += "______________________________________________________________________\n";
    comand += "                         Comandos de retorno                          \n";
    comand += "Vazia    - Verifica se a lista esta vazia\n"; // Estressed Test 13/22
    comand += "           Parametros: comando e lista - E.g.: vazia 0\n";
    comand += "Tamanho  - Retorna o numero de nos (elementos) que a lista possui\n"; // Estressed Test 14/22
    comand += "           Parametros: comando e lista - E.g.: num 0\n";
    comand += "Primeiro - Retorna uma referencia para o primeiro elemento da lista\n"; // Estressed Test 15/22
    comand += "           Parametros: comando e lista - E.g.: primeiro 0\n";
    comand += "Ultimo   - Retorna uma referencia para o ultimo elemento da lista\n";   // Estressed Test 16/22
    comand += "           Parametros: comando e lista - E.g.: ultimo 0\n";
    comand += "Copiar   - Retorna um ponteiro para a copia da lista\n"; //Estressed Test 17/22
    comand += "           Parametros: comando e lista - E.g.: copia 0\n";
    comand += "Iguais   - Verifica se duas listas sao iguais\n"; //Estressed Test 18/22
    comand += "           Parametros: comando, lista e lista - E.g.: iguais 0 e 1\n";
    comand += "______________________________________________________________________\n";
    comand += "                         Comandos de modicacao                         \n";
    comand += "Trocar     - Troca o conteudo da lista original pela lista passada como paramentro\n"; //Estressed Test 19/22
    comand += "             Parametros: comando, lista e lista - E.g.: troca 0 e 1\n";
    comand += "Concatenar - Concatena a lista passada como parametro para a original\n"; //Estressed Test 20/22
    comand += "             Parametros: comando, lista e lista - E.g.: concat 0 e 1\n";
    comand += "Inverter   - Inverte a ordem dos elementos da lista\n"; //Estressed Test 21/22
    comand += "             Parametros: comando e lista - E.g.: inverte 0\n";
    comand += "Misturar   - Intercala os elementos da lista original com a lista recebida como paramentro\n"; //Estressed Test 22/22
    comand += "             Parametros: comando, lista e lista - E.g.: mistura 0 e 1\n";
    comand += "______________________________________________________________________\n";
    //Imprimir o Menu de comandos
    cout << comand;

    cout << "\nSempre que quiser ver os comandos novamente, basta digitar: comandos\n";
    
    while(true) {
        string comando;
        getline(cin, comando);
        std::stringstream ss{ comando };
        vector<string> indexers;
        string buffer;

        cout << "$" << ss.str() << endl;

        while(ss >> buffer) 
            indexers.push_back(buffer);

//------------------------------Comandos de operacao---------------------------   

        // Fechando algoritmo
        if(indexers[0] == "Sair" || indexers[0] == "sair") {
            for(unsigned i = 0; i < listas.size(); i++)
                delete listas[i];
            listas.clear();
            cout << "Obrigado por usar nosso programa, ate mais\n\n";
            break;
        }

        // Criando lista
        else if(indexers[0] ==  "Criar" || indexers[0] == "criar") {
            List *lst = new List;
            listas.push_back(lst);
            cout << "Lista criada com sucesso\n";
        }

        //Imprimir as listas salvas 
        else if(indexers[0] == "Mostrar" || indexers[0] == "mostrar") {
            for(unsigned i = 0; i < listas.size(); ++i) {
                cout << "lista " << i << ": " << *listas[i] << endl;
            }    
        }

//------------------------------Comandos de insercao---------------------------                          
        // Coloca elemento no incio da lista
        else if(indexers[0] == "AddPrim" || indexers[0] == "addprim") { 
            int x = std::stoi(indexers[1]);
            int l = std::stoi(indexers[2]);
            listas[l]->push_front(x);
        }

        // Coloca elemento no final da lista
        else if(indexers[0] == "AddUlt" || indexers[0] == "addult") {
            int x = std::stoi(indexers[1]);
            int l = std::stoi(indexers[2]);
            listas[l]->push_back(x);
        }

        //Insere na lista deseja o elemento no indice desejado - lista, elemento e indice
        else if(indexers[0] == "Inserir" || indexers[0] == "inserir"){
            int l = std::stoi(indexers[1]);
            int x = std::stoi(indexers[2]);
            int m = std::stoi(indexers[3]);
            listas[l]->insertAt(x,m);
        }

        //Copia os elementos do vetor para o final da lista
        else if(indexers[0] == "Vetor" || indexers[0] == "vetor") {
            int l = std::stoi(indexers[1]);
            int n = indexers.size()-2;
            int *v = new int[n];
            for(int i = 0; i < n; i++)
                v[i] = std::stoi(indexers[i+2]);
            listas[l]->append(v, n);
        }

//------------------------------Comandos de remoção--------------------------- 

        //Deleta a lista passada como parâmetro
        else if(indexers[0] == "Deletar" || indexers[0] == "deletar") {
            int l = std::stoi(indexers[1]);
            listas[l]->clear();
        }

        // Remove o primeiro elemento da lista passada como parâmetro
		else if(indexers[0] == "DltPrim" || indexers[0] == "dltprim"){
			int l = std::stoi(indexers[1]);
			listas[l]->pop_front();
		}

        // Remove o último elemento da lista passada como parâmetro
		else if(indexers[0] == "DltUlt" || indexers[0] == "dltult"){
			int l = std::stoi(indexers[1]);
			listas[l]->pop_back();
		}
        
        // Remove o elemento no indice desejado - lista e indice 
        //com problema, depois que dá um dltprim ou dltult
        else if(indexers[0] == "Remover" || indexers[0] == "remover"){
            int l = std::stoi(indexers[1]);
            int x = std::stoi(indexers[2]);
            cout << "O numero " << listas[l]->removeAt(x) << " foi deletado da lista." << endl;
        }

        //Remove as ocorrências de um determinado elemento - elemento e lista os parametros
        else if(indexers[0] == "RemoveAl" || indexers[0] == "removeal"){
            int x = std::stoi(indexers[1]);
            int l = std::stoi(indexers[2]);
            listas[l]->removeAll(x);
        }
//------------------------------Comandos de retorno--------------------------- 

        //Verifica se a lista esta vazia ou nao
        else if(indexers[0] == "Vazia" || indexers[0] == "vazia"){
            int l = std::stoi(indexers[1]);
            if(!(listas[l]->empty())){
                cout << "Lista com elementos\n";
            }else{
                cout << "Lista vazia\n" << std::endl;
            }
        }
        //Retorna o número de nós da lista
        else if(indexers[0] == "Tamanho" || indexers[0] == "tamanho") {
            int l = std::stoi(indexers[1]);
            int tamanho = listas[l]->size();
            cout << "A lista "<< l << " possui " << tamanho << " elementos." << endl;
        }

         //Retorna eo elemento da primeira posição
        else if(indexers[0] == "Primeiro" ||indexers[0] == "primeiro"){
            int l = std::stoi(indexers[1]);
            if(!listas[l]->empty()){
            cout << "O primeiro elemento da lista " << l << " tem um data igual a: " << listas[l]->front() << endl;
            }else{
            cout << "Error: Lista Vazia, coloque algum elemento na lista antes de usar este comando." << endl;
            }
        }

        //Retorna o elemento da última posição
        else if(indexers[0] == "Ultimo" || indexers[0] == "ultimo"){
            int l = std::stoi(indexers[1]);
            if(!listas[l]->empty()){
            cout << "O ultimo elemento da lista " << l  << " tem um data igual a: " << listas[l]->back()<< endl;
            }else{
            cout << "Error: Lista Vazia, coloque algum elemento na lista antes de usar este comando." << endl;
            }
        }

        //Copia os elementos da lista em uma outra lista
        else if(indexers[0] == "Copia" || indexers[0] == "copiar") {
            int l = std::stoi(indexers[1]);
            List *lcp = listas[l]->copy();
            listas.push_back(lcp);
        }

         //Verifica se duas listas são iguais
        else if(indexers[0] == "Iguais" || indexers[0] == "iguais") {
            int l1 = std::stoi(indexers[1]);
            int l2 = std::stoi(indexers[2]);
            if(listas[l1]->equals(*listas[l2])) cout << "Listas iguais" << endl;
            else cout << "Listas diferentes" << endl;
        }

//------------------------------Comandos de modificação--------------------------- 
        // Troca os valores das listas passadas como parâmetro 
        else if(indexers[0] == "Trocar" || indexers[0] == "trocar") {
            int l1 = std::stoi(indexers[1]);
            int l2 = std::stoi(indexers[2]);
            listas[l1]->swap(*listas[l2]);
        }

        // Unir/concatena duas listas
        else if(indexers[0] == "Concatenar" || indexers[0] == "concatenar") {
            int l1 = std::stoi(indexers[1]);
            int l2 = std::stoi(indexers[2]);
            listas[l1]->concat(*listas[l2]);
        }

        //Inverte as posições dos elementos da lista
        else if(indexers[0] == "Inverter" || indexers[0] == "inverter") {
            int l = std::stoi(indexers[1]);
            listas[l]->reverse();
        }

        // Intercala duas listas 
        else if(indexers[0] == "Misturar" ||indexers[0] == "misturar") {
            int l1 = std::stoi(indexers[1]);
            int l2 = std::stoi(indexers[2]);
            listas[l1]->merge(*listas[l2]);
        }

        //Ver o painel de controle novamente
        else if(indexers[0] == "Comandos" || indexers[0] == "comandos"){
            cout << comand;
        }
        else {
            cout << "Comando inexistente\n" << endl;
        }
    }
    return 0;
}