#include "projeto2.h"

void funcao_um(string ator_um, string ator_dois, lista<info_filme> l_geral) {
    lista<string> filmes_atuados;
    auto conjunto_atores = new conjunto<string>(ator_um);
    conjunto_atores->adicionar(ator_dois);
    l_geral.inicia();
    while(! l_geral.fim()){
        info_filme auxiliar = l_geral.proximo();
        auto conjunto_aux = new conjunto<string> (auxiliar.atores);
        if(conjunto_aux->subconjunto(conjunto_atores)) filmes_atuados.anexa(auxiliar.Nome_filme);
    }
    cout << "todos os filmes em que os dois atores atuaram foram: " << endl;
    filmes_atuados.escrevaSe(cout);
}

void funcao_dois (lista<string> filmes,lista<info_filme> l_geral) {
    auto conjunto_filmes_desejados = new conjunto<string> (filmes); //conjunto com os filmes desejados.
    lista<string> l_atores_desejados;
    l_geral.inicia();
    while(!l_geral.fim()){
        info_filme aux = l_geral.proximo();
        if(conjunto_filmes_desejados->existe(aux.Nome_filme)){
            l_atores_desejados.anexa(aux.atores);
        }
    }
    auto atores_desejados = new conjunto<string> (l_atores_desejados);
    lista<string> extracao;
    atores_desejados->eXtrair(extracao);
    cout << "todos os atores em que atuaram nos filmes foram: " << endl;
    extracao.escrevaSe(cout);
}

lista<string> Separa(string Separador,char sep){ //Função separa de uma string substrings e anexa em uma lista.
    lista<string> l_retorno; //Declaração de variáveis.
    int ini=0, fim = 0; //Declaração de variáveis.
    if (Separador.size()==0){ //Condicional verifica se string está vazia.

    }
    else{
        do{

            fim = Separador.find_first_not_of(sep,fim); //Fim recebe uma posição de separador.
            ini = Separador.find_first_of(sep,fim); //Ini recebe uma posição do separador.
            string sub = Separador.substr(fim, ini - fim); //Gera substring partindo das posições ini e fim.
            l_retorno.anexa(sub); //Anexa na lista substring gerada.

            if (Separador.find_first_not_of(sep,fim) == string::npos) break; //Condicional verifica se está no final da string.
            fim = Separador.find_first_not_of(sep,ini); //Fim recebe uma nova posição.

        }
        while(fim != string::npos); //Loop acontece enqunado fim for diferente da ultima posição da string.
    }
    return l_retorno; //Retorna lista com substrings.
}

info_filme Add_struct(string dados){ //Função retorna uma struct do tipo info_filme.
    lista<string> l_arquivo=Separa(dados,';'); //Lista de string recebe separa da função que recebe parãmetro de dados.
    info_filme Filme; //Declaração de variável.
    Filme.Nome_filme=l_arquivo.remove(0); //remove o que tem na posição um e coloca na struct.
    Filme.ano=stoi(l_arquivo.remove(0)); //remove o que tem na posição um e coloca na struct.
    Filme.atores=Separa(l_arquivo.remove(0),','); //remove o que tem na posição um e realiza um separa e coloca na struct.
    return Filme; //retorna struct com dados de uma string.
}

lista<info_filme> Leitura_arquivo(){ //Função realiza a leitura de um arquivo e transforma em uma lista de struct.
    lista<info_filme> Lista_geral; //Declaração de variáveis.
    ifstream arq("../dados.txt"); //Declaração de variáveis.
    string apoio; //Declaração de variáveis.
    while(getline(arq,apoio)){ //Loop acontece enquando apoio recebe linha de um arquivo.
        try { //tente:
            Lista_geral.anexa(Add_struct(apoio)); //tentativa de anexar na lista uma string que vira uma struct pela função add_struct.
        }catch(...){}
    }

    return Lista_geral; //Retorna lista de struct.
}








