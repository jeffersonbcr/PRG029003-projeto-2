#include <iostream>  //Inclusão de biblioteca.
#include <string>    //Inclusão de biblioteca.
#include <prglib.h>  //Inclusão de biblioteca.
#include <fstream>  //Inclusão de biblioteca.
#include <stdio.h>  //Inclusão de biblioteca.

using namespace std;
using namespace prglib;

struct info_filme{  //Declaração de struct.
    string Nome_filme;  //Declaração de variável.
    int ano;            //Declaração de variável.
    lista<string> atores;  //Declaração de variável.
    bool operator < (const info_filme & outra){ //Sobrecarga de operador.
        bool booleano0 = ano < outra.ano;  //variável bool recebe o valor de comparação entre o ano de cada struct.
        return booleano0; //retorna variável.
    }
};

struct info_atores{  //Declaração de struct.
    string nome_ator;  //Declaração de variável.
//    lista<string> filmes_do_ator;  //Declaração de variável.
    int num_filmes_atuados;
    bool operator < (const info_atores & outra){ //Sobrecarga de operador.
        bool booleano = num_filmes_atuados < outra.num_filmes_atuados;
//        bool booleano = filmes_do_ator.comprimento() < outra.filmes_do_ator.comprimento(); //variável bool recebe o valor da comparação entre o comprimento de cada struct.
        return booleano; //retorna variável.
    }
};
struct info_atores_comum{ //Declaração de struct.
    string nome_ator_comum; //Declaração de variável.
    int quantidade_filmes_comum;  //Declaração de variável.
    bool operator < (const info_atores_comum & outra){  //Sobrecarga de operador.
        bool booleano2 = quantidade_filmes_comum < outra.quantidade_filmes_comum; //variável bool recebe o valor da comparação entre a quantidade de filmes de struct.
        return booleano2; //retorna variável.
    }
};

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

void ator_atuou(lista<info_filme> & l_geral,string Nome_ator){ //Função imprime na tela atores que atuaram com um ator recebido como parâmetro.
    lista<info_filme> filmes_atuados; //Declaração de variáveis.
    l_geral.inicia(); //Inicia iteração da lista l_geral.
    while(!l_geral.fim()) { //Loop acontece enquanto não estiver no fim da lista.
        info_filme apoio=l_geral.proximo(); //Recebendo dado que esta na lista l_geral.
        info_filme apoio2; //Declaração de variáveis.
        try { //Tente:
            apoio.atores.procura(Nome_ator); //Procura nome_ator na lista de atores que esta na struct apoio.
            apoio2.ano = apoio.ano; //struct recebe dado de outra struct.
            apoio2.Nome_filme = apoio.Nome_filme; //struct recebe dado de outra struct.
            filmes_atuados.anexa(apoio2); //anexa struct gerada na lista.
        } catch (...) {}
    }
    if(filmes_atuados.vazia()) cout<<"Ator não encontrado"<<endl; //Se ator não atuou em nenhum filme imprime mensagem na tela.
    else{ //Senão
        filmes_atuados.ordena(); //Ordena lista dos filmes atuados pelo ator.
        filmes_atuados.inicia(); //Inicia iteração da lista.
        cout << "Filmes do ator: " << Nome_ator << endl; //Imprime texto na tela.
        while(! filmes_atuados.fim()){ //Loop acontece enquando não estiver no fim da lista.
            info_filme apoio3 = filmes_atuados.proximo(); //struct recebe dado dentro da lista.
            cout << apoio3.Nome_filme << " ano: " << apoio3.ano << endl; //Imprime texto na tela.
        }
        cout<<endl<<endl;
    }
}

lista<string> list_ator_atuou_x_filmes(lista<info_filme> & l_geral,string Nome_ator){ //Função retorna uma lista de filmes que um ator atuou.
    l_geral.inicia(); //Inicia iteração da lista.
    lista<string> Filmes_atuados; //Declaração de variáveis.
    while(!l_geral.fim()) { //Loop acontece enquanto não estiver no fim da lista.
        try { //Tente:
            info_filme apoio=l_geral.proximo(); //struct recebe dado da lista.
            apoio.atores.procura(Nome_ator); //procura na lista o nome do ator.
            Filmes_atuados.anexa(apoio.Nome_filme); //anexa na lista o nome do filme da struct.
        } catch (...) {}
    }
    if(Filmes_atuados.comprimento() != 0){ //se o comprimento da lista for diferente de zero:
        return Filmes_atuados; //retorna lista.
    }
}

int list_ator_atuou_filmes(lista<info_filme> & l_geral,string Nome_ator){ //Função retorna um inteiro com tamanho
    l_geral.inicia(); //Inicia iteração da lista.
    int apoio_cont=0; //Declaração de variáveis.
    while(!l_geral.fim()) { //Loop acontece enquanto não estiver no final da lista.
        try { //Tente:
            info_filme apoio=l_geral.proximo(); //struct recebe dado da lista.
            apoio.atores.procura(Nome_ator); //procura o nome do ator dentro da lista da struct apoio.
            apoio_cont++; //incrementa contador.
        } catch (...) {}
    }
    return apoio_cont; //retorna o numero de filmes atuados por um ator.
}

void Atores_filme(lista<info_filme> & L_geral,string filme){//Função imprime na tela o numero de atores de um filme.
    lista<string> atores_do_filmes; //Declaração de variáveis.
    L_geral.inicia(); //Inicia iteração da lista.
    bool x=true; //variável recebe true.
    while(!L_geral.fim()) { //Loop acontece enquanto lista não estiver no fim.
        info_filme apoio=L_geral.proximo(); //recebe dado da lista.
        if(apoio.Nome_filme==filme){ //Se nome do filme da struct for igual ao filme.
            cout<< "Os atores do filme: "<< filme << endl; //imprime texto na tela.
            atores_do_filmes = apoio.atores; //lista recebe lista da struct apoio.
            atores_do_filmes.ordena(); //Ordena lista dos atores do filme.
            atores_do_filmes.escrevaSe(cout); //Imprime lista na tela.
            cout<<endl<<endl;
            x=false; //variável recebe false;
        }
    }
    if(x)cout<<"Não foi encontrado nenhum filme com esse nome..."<<endl; //Se variável for true imprime texto na tela.
}

void Atores_atuaram_ator(lista<info_filme> & L_geral,string nome_ator){ //Função imprime na tela atores que atuaram com um ator passado por parâmetro.
    lista<string> atores_comum; //Declaração de variáveis.
    L_geral.inicia(); //Inicia iteração da lista.
    while(!L_geral.fim()){ //Loop acontece enquanto não estiver no fim da lista.
        info_filme apoio=L_geral.proximo(); // struct recebe dado dentro da lista.
        try { //tente:
            apoio.atores.procura(nome_ator); //lista dentro da struct procura nome do ator.
            apoio.atores.inicia(); //Inicia iteração da lista dentro da struct.
            while(!apoio.atores.fim()) { //Loop acontece enquanto não estiver no fim da lista.
                string aux=apoio.atores.proximo(); //variável recebe dado da lista.
                try { //Tente:
                    atores_comum.procura(aux); //lista atores_comum procura conteudo da variável aux.
                } catch (...) {if(aux!=nome_ator)atores_comum.anexa(aux);} //Caso mensagem de erro condicional não inclui o mesmo ator que foi passado por parâmetro.
            }
        }catch(...){}
    }
    atores_comum.ordena(); //Ordena lista.
    atores_comum.escrevaSe(cout); //Imprime na tela a lista atores_comum;
    cout<<endl<<endl<<endl; //Quebra de linhas.
}
lista<string> list_atores_atuaram(lista<info_filme> & L_geral,string nome_ator){ //Função retorna lista de atores com um ator passado por parâmetro.
    lista<string> atores_comum; //Declaração de variáveis.
    L_geral.inicia(); //Inicia iteração da lista.
    while(!L_geral.fim()){ //Loop ocorre enquanto lista não estiver no fim.
        info_filme apoio=L_geral.proximo(); //Recebendo dado dentro da lista.
        try { //Tente:
            apoio.atores.procura(nome_ator); //Lista dentro da struct procura o nome do ator.
            apoio.atores.inicia(); //Inicia iteração da lista.
            while(!apoio.atores.fim()) { //Loop ocorre enquanto lista não estiver no fim.
                string aux=apoio.atores.proximo(); //Recebendo dado dentro da lista.
                try { //Tente:
                    atores_comum.procura(aux); //Procura dentro da lista aux.
                } catch (...) {if(aux!=nome_ator)atores_comum.anexa(aux);} //Condicional verifica que aux seja diferente do ator que foi passado por parâmetro.
            }
        }catch(...){}
    }
    return atores_comum; //Retorna lista de atores em comum.
}

lista<string> list_todos_atores(lista<info_filme> & l_geral){ //Função retorna uma lista com todos os atores de uma lista de struct.
    lista<string> todos_atores; //Declaração de variáveis.
    int cont=0; //Declaração de variáveis.
    l_geral.inicia(); //Inicia iteração da lista.
    while(! l_geral.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
        info_filme apoio = l_geral.proximo(); //Recebendo dado dentro da lista.
        lista<string> atores_apoio=apoio.atores; //uma lista recebe a lista que estava dentro da struct.
        atores_apoio.inicia(); //Inicia iteração da lista.
        while(! atores_apoio.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
            string ator_apoio = atores_apoio.proximo(); //Recebendo dado dentro da lista.
            try{ //Tente:
                todos_atores.procura(ator_apoio); //procura na lista o ator_apoio.
            }
            catch (...){
                todos_atores.anexa(ator_apoio); //Caso mensagem de erro anexa na lista.
            }
        }
        cont++; //Incrimenta contador;
        if(cont==10000)break; //Condador condicional para 10 mil linhas de arquivo, caso queira para mais linhas mudar valor de comparação do condicional pelo valor desejado.
    }
    return todos_atores; //retorna lista de todos atores da lista de struct.
}

void listagem_ord_atores_filmes(lista<string> todos_atores,lista<info_filme> & l_geral,int top_x){ //Imprime na tela uma listagem ordena de atores pelos seus numeros de filmes atuados.
    info_atores info_apoio,apoio_atores_filmes; //Declaração de variáveis.
    lista<info_atores> l_atores_filmes; //Declaração de variáveis.
    int contador=0; //Declaração de variáveis.
    todos_atores.inicia(); //Inicia iteração da lista.
    while(! todos_atores.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
        string apoio_ator = todos_atores.proximo(); //Recebendo dado dentro da lista.
        info_apoio.nome_ator = apoio_ator; //struct recebe string.
        info_apoio.num_filmes_atuados = list_ator_atuou_filmes(l_geral,apoio_ator); //variável recebendo valor que retorna a função list_ator_atuou_filmes.
        l_atores_filmes.anexa(info_apoio); //Anexando struct na lista.
    }
    l_atores_filmes.ordena(); //Ordena lista.
    l_atores_filmes.inverte(); //Inverte lista.
    l_atores_filmes.inicia(); //Inicia iteração.
    while(!l_atores_filmes.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
        if(contador == top_x) break; //Se contador for igual ao valor de top_x passado por parâmetro.
        else { //Senão.
            apoio_atores_filmes = l_atores_filmes.proximo(); //Recebendo dado dentro da lista.
            cout <<contador+1<<") " << apoio_atores_filmes.nome_ator << " atuou em: " << apoio_atores_filmes.num_filmes_atuados<< " filmes." << endl; //Imprime texto na tela.
        }
        contador++; //Incrimenta contador.

    }
    cout<<endl<<endl; //Quebra de linha.
}

void listagem_ord_filmes_em_comum(lista<info_filme> & l_geral,int top_x,string ator_desejado){ //Função Para um dado ator, o programa possibilita mostrar a listagem ordenada de atores de acordo com a quantidade de filmes em que atuaram em comum (limitada a uma quantidade mínima de filmes em comum).
    int contador =0; //Declaração de variáveis.
    lista<string> atores_em_comum_ator_x = list_atores_atuaram(l_geral,ator_desejado); //Criando lsita a partir da função list_atores_atuaram.
    lista<string> filmes_do_ator_desejado = list_ator_atuou_x_filmes(l_geral,ator_desejado); //Criando lista a partir da função list_ator_atuou_x_filmes
    lista<info_atores_comum> list_info_atores_comum; //Declaração de variáveis.
    atores_em_comum_ator_x.inicia(); //Inicia iteração da lista.
    while(!atores_em_comum_ator_x.fim()){ //Loop ocorre enquanto fila não estiver no fim.
        info_atores_comum apoio; //Declaração de variáveis.
        string ator_em_comum = atores_em_comum_ator_x.proximo(); //Recebendo dado da lista.
        apoio.nome_ator_comum = ator_em_comum; //struct recebendo dado de uma string.
        apoio.quantidade_filmes_comum = filmes_do_ator_desejado.comprimento(); //struct recebe comprimento da lista filmes_do_ator_desejado.
        lista<string> filmes_do_ator_em_comum = list_ator_atuou_x_filmes(l_geral,ator_em_comum); //Lista recebendo retorno da função list_ator_atuou_x_filmes.
        filmes_do_ator_em_comum.inicia(); //Inicia iteração da lista.
        while(!filmes_do_ator_em_comum.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
            string filme_do_ator_em_comum = filmes_do_ator_em_comum.proximo(); //Recebendo dado da lista.
            try{ //Tente:
                filmes_do_ator_desejado.procura(filme_do_ator_em_comum); // Procura na lista filme do ator em comum.
            }
            catch(...){
                apoio.quantidade_filmes_comum = apoio.quantidade_filmes_comum - 1; //Caso mensagem de erro decrementa dado da struct.
            }

        }
        list_info_atores_comum.anexa(apoio); //Anexa struct na lista.
    }
    list_info_atores_comum.ordena(); //Ordena lista.
    list_info_atores_comum.inverte(); //Inverte lista.
    list_info_atores_comum.inicia(); //Inicia iteração da lista.
    while(! list_info_atores_comum.fim()) { //Loop acontece enquanto lista não estiver no fim.
        if (contador == top_x) break; //Condicional para loop.
        else {
            info_atores_comum apoio2 = list_info_atores_comum.proximo(); //Recebendo dado da lista.
            cout << contador+1<<") " << apoio2.nome_ator_comum << " atuou com: " << ator_desejado << " em : "<< apoio2.quantidade_filmes_comum << " filmes." << endl; //Imprime texto na tela.
        }
        contador++; //Incrimenta contador.
    }
    cout<<endl<<endl; //Quebra de linha.
}
int menu () //Função de interface de menu.
{
    int opcao; //Declaração de variáveis.
    cout <<"1)Os filmes em que um ator atuou "<< endl; //Imprime mensagem na tela.
    cout <<"2)Os atores que atuaram em um dado filme"<< endl; //Imprime mensagem na tela.
    cout <<"3)Os atores que trabalharam com um dado ator"<< endl; //Imprime mensagem na tela.
    cout <<"4)A listagem ordenada de atores, de acordo com a quantidade de filmes em que atuaram"<< endl; //Imprime mensagem na tela.
    cout <<"5)Para um dado ator, a listagem ordenada de atores de acordo com a quantidade de filmes em que atuaram em comum"<< endl; //Imprime mensagem na tela.
    cout <<"0)Sair do programa"<< endl; //Imprime mensagem na tela.

    cin>>opcao; //Captura do teclado opcao.

    lista<info_filme> L_geral; //Declaração de variáveis.

    switch (opcao){
        case 1: {
            if (L_geral.vazia())L_geral = Leitura_arquivo(); //Condicional chama função.
            cout << "Digite o nome do Ator que deseja saber os nomes do filmes atuados" << endl; //Imprime mensagem na tela.
            string Nome_ator; //Declaração de variáveis.
            getchar();
            getline(cin, Nome_ator); //Captura do teclado nome do ator.
            ator_atuou(L_geral, Nome_ator); //Chama função ator_atuou.
            break;
        }
        case 2: {
            if (L_geral.vazia())L_geral = Leitura_arquivo(); //Condicional chama função.
            cout<< "Os atores que atuaram em um dado filme... Digite o nome do filme"<<endl; //Imprime mensagem na tela.
            string Nome_filme; //Declaração de variáveis.
            getchar();
            getline(cin, Nome_filme); //Captura do teclado nome do filme.
            Atores_filme(L_geral,Nome_filme); //Chama função atores_filme.
            break;
        }
        case 3: {
            if (L_geral.vazia())L_geral = Leitura_arquivo(); //Condicional chama função.
            cout<< "Digite o nome do ator..."<<endl; //Imprime mensagem na tela.
            string Nome_ator; //Declaração de variáveis.
            getchar();
            getline(cin, Nome_ator); //Captura do teclado nome do ator.
            Atores_atuaram_ator(L_geral,Nome_ator); //Chama função atores_atuaram_ator.
            break;
        }
        case 4: {
            if (L_geral.vazia())L_geral = Leitura_arquivo(); //Condicional chama função.
            lista<string> lista_atores = list_todos_atores(L_geral);
            cout << "Digite a quantidade de ator que deseja aparecer no top..." << endl; //Imprime mensagem na tela.
            int top_x; //Declaração de variáveis.
            cin>>top_x;
            listagem_ord_atores_filmes(lista_atores, L_geral,top_x); //Chama função a listagem_ord_atores_filmes.
            break;
        }
        case 5: {
            if (L_geral.vazia())L_geral = Leitura_arquivo(); //Condicional chama função.
            cout<< "Digite o nome do ator..."<<endl; //Imprime mensagem na tela.
            string Nome_ator; //Declaração de variáveis.
            getchar();
            getline(cin, Nome_ator);  //Captura do teclado nome do ator.
            cout << "Digite a quantidade de ator que deseja aparecer no top..." << endl; //Imprime mensagem na tela.
            string apoio; //Declaração de variáveis.
            getline(cin,apoio);    //Captura do teclado apoio.
            int top_x=stoi(apoio); //transforma variavel apoio em inteiro.
            listagem_ord_filmes_em_comum(L_geral,top_x,Nome_ator); //Chama função a listagem_ord_filmes_em_comum.
            break;
        }
        case 0:
            break;
        default:
            cout<< "Operação invalida"<<endl; //Imprime mensagem na tela.
    }
    return opcao; //retorna opcao.
}






