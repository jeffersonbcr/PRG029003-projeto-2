#ifndef PROJETO2_H
#define PROJETO2_H

// Aqui neste arquivo se declaram os protótipos das funções disponibilizadas nesta biblioteca

#include <string>    //Inclusão de biblioteca.
#include <prglib.h>  //Inclusão de biblioteca.
#include <fstream>  //Inclusão de biblioteca..
#include <iostream> //Inclusão de biblioteca.
#include <libs/conjunto.h>

using namespace std;
using namespace prglib;

struct info_filme{  //Declaração de struct.
    string Nome_filme;  //Declaração de variável.
    int ano;            //Declaração de variável.
    lista<string> atores;  //Declaração de variável.
    bool operator < (const info_filme & outra){ //Sobrecarga de operador.
        return Nome_filme< outra.Nome_filme;
    }
    bool operator == (const info_filme & outra){
        return Nome_filme == outra.Nome_filme;
    }

};


void funcao_um(string ator_um,string ator_dois,lista<info_filme> l_geral); //função retorna todos os filmes atuados por dois atores.

void funcao_dois (lista<string> filmes,lista<info_filme> l_geral); //função retorna todos os atores atuados por, dois ou mais filmes.

lista<string> Separa(string Separador,char sep); //Função separa de uma string substrings e anexa em uma lista.

info_filme Add_struct(string dados); //Função retorna uma struct do tipo info_filme.

lista<info_filme> Leitura_arquivo(); //Função realiza a leitura de um arquivo e transforma em uma lista de struct.


#endif
