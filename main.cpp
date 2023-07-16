#include <iostream>
#include <prglib.h>
#include <string>
#include "projeto2.h"

using namespace std;
using namespace prglib;


string ler_escolha(string & escolha) {
    cout << "Digite: ";

    while(true){
        getline(cin,escolha);
        if(escolha.size() != 0)break;
    }
    cout << endl;

    return escolha;
}


int main() {
    
    cout << "Programa de estatísticas sobre atores e filmes inciado..." << endl;

    lista <info_filme> Mapa = Leitura_arquivo();

    cout << "MENU: " << endl << "1 - Os filmes em que um ator atuou." << endl;
    cout << "2- Os atores que atuaram em um dado filme." << endl << "3 - Os atores que trabalharam com um dado ator." << endl;
    cout << "4 - A listagem ordenada de atores, de acordo com a quantidade de filmes em que atuaram." << endl << "5 - Para um dado ator, a listagem ordenada de atores de acordo com a quantidade de filmes em que atuaram em comum." << endl;

    string opcao;
    int conv = 0; 
    cout << "Digite a opção: ";
    while(true) {
        getline(cin,opcao);
        conv = stoi(opcao);
        if(conv <= 5 && conv != 0)break;
    }
    
    string escolha; 
    lista <info_filme> search_filmes; 
    lista <string> search_atores; 
    lista <string> busca_ator; 
    lista <papeis> list_ator; 
    lista <comum> list_comum; 

    switch (conv) {

        case 1:
            cout << "Busca de filmes em que um ator atuou; digite inicialmente o nome de um ator." << endl;
            ler_escolha(escolha);
            funcao_um(escolha, "", Mapa);
            break;

        case 2:
            cout << "Busca de atores que atuaram em um dado filme; digite inicialmente o nome de um filme." << endl;
            ler_escolha(escolha);
            lista<string> filmes;
            filmes.anexa(escolha);
            funcao_dois(filmes, Mapa);
            break;

        case 3:
            cout << "Busca dos atores que trabalharam com um dado ator; digite inicialmente o nome de um ator." << endl;
            ler_escolha(escolha);
            lista<string> atores;
            atores.anexa(escolha);
            funcao_dois(atores, Mapa);
            break;

        case 4:
            cout << "A listagem ordenada de atores, de acordo com a quantidade de filmes em que atuaram." << endl;
            lista<string> todos_atores;
            todos_atores.inicia();
            todos_atores.escrevaSe(cout);
            funcao_dois(todos_atores, Mapa);
            break;

        case 5:
            cout << "A listagem ordenada de atores de acordo com a quantidade de filmes em que atuaram em comum; digite o ator." << endl;
            ler_escolha(escolha);
            funcao_um(escolha, "", Mapa);
            break;

    }

    //Fim do programa.
    return 0;

}
