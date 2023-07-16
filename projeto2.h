#ifndef PROJETO2_H
#define PROJETO2_H

// Aqui neste arquivo se declaram os protótipos das funções disponibilizadas nesta biblioteca

#include <string>    //Inclusão de biblioteca.
#include <prglib.h>  //Inclusão de biblioteca.
#include <fstream>  //Inclusão de biblioteca.
#include <iostream> //Inclusão de biblioteca.

using namespace std;
using namespace prglib;

struct info_filme{  //Declaração de struct.
    string Nome_filme;  //Declaração de variável.
    int ano;            //Declaração de variável.
    lista<string> atores;  //Declaração de variável.
};
struct info_atores{  //Declaração de struct.
    string nome_ator;  //Declaração de variável.
//    lista<string> filmes_do_ator;  //Declaração de variável.
    int num_filmes_atuados;
};
struct info_atores_comum{ //Declaração de struct.
    string nome_ator_comum; //Declaração de variável.
    int quantidade_filmes_comum;  //Declaração de variável.

};

lista<string> Separa(string Separador,char sep); //Função separa de uma string substrings e anexa em uma lista.

info_filme Add_struct(string dados); //Função retorna uma struct do tipo info_filme.

lista<info_filme> Leitura_arquivo(); //Função realiza a leitura de um arquivo e transforma em uma lista de struct.

void ator_atuou(lista<info_filme> & l_geral,string Nome_ator); //Função imprime na tela atores que atuaram com um ator recebido como parâmetro.

lista<string> list_ator_atuou_x_filmes(lista<info_filme> & l_geral,string Nome_ator); //Função retorna uma lista de filmes que um ator atuou.

int list_ator_atuou_filmes(lista<info_filme> & l_geral,string Nome_ator); //Função retorna um inteiro com tamanho.

void Atores_filme(lista<info_filme> & L_geral,string filme);//Função imprime na tela o numero de atores de um filme.

void Atores_atuaram_ator(lista<info_filme> & L_geral,string nome_ator); //Função imprime na tela atores que atuaram com um ator passado por parâmetro.

lista<string> list_atores_atuaram(lista<info_filme> & L_geral,string nome_ator); //Função retorna lista de atores com um ator passado por parâmetro.

lista<string> list_todos_atores(lista<info_filme> & l_geral); //Função retorna uma lista com todos os atores de uma lista de struct.

void listagem_ord_atores_filmes(lista<string> todos_atores,lista<info_filme> & l_geral,int top_x); //Imprime na tela uma listagem ordena de atores pelos seus numeros de filmes atuados.

void listagem_ord_filmes_em_comum(lista<info_filme> & l_geral,int top_x,string ator_desejado); //Função Para um dado ator, o programa possibilita mostrar a listagem ordenada de atores de acordo com a quantidade de filmes em que atuaram em comum (limitada a uma quantidade mínima de filmes em comum).

int menu (); //Função de interface de menu.
#endif
