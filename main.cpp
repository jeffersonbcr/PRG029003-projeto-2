#include <string>
#include <prglib.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace prglib;

struct Qnt_filmes{ //Declaração da struct.
  string Ator;     //Variável dentro da struct.
  int Qnt_filme_atuado; //Variável dentro da struct.

  bool operator < (const Qnt_filmes & outra){ //Sobrecarga de operador dentro da struct.
      bool booleano = Qnt_filme_atuado < outra.Qnt_filme_atuado; //Variável recebe o valor da comparação entre uma struct e outra por suas variáveis de inteiro dentro da struct.
      return booleano; //Retorna variável booleano.
  }
};

void Lista_ordenada_filmes_atuados(thash<lista<string>> & Tab_ator,int lim){ //Função lista ordenadamente filmes atuados por um limitador de top.
  auto chaves=Tab_ator.chaves(); //Recebendo uma lista contendo as chaves da tabela hash de nome tab_ator.
  lista<Qnt_filmes> l_atores_qnt_filme; //Declaração de uma lista de struct.
  chaves->inicia(); //Iniciando iteração da lista chaves.
  while(!chaves->fim()){ //Loop ocorre enquanto não estiver no fim da lista.
      string apoio_str=chaves->proximo(); //Recebendo dado dentro da lista e jogando na variável de nome apoio.
      Qnt_filmes apoio; //Declaração de struct.
      apoio.Ator=apoio_str; //Struct recebe valor da variável apoio_str.
      apoio.Qnt_filme_atuado=Tab_ator[apoio_str].comprimento(); //Struct recebe o valor do comprimento da lista que esta na tabela hash de nome tab_ator.
      l_atores_qnt_filme.anexa(apoio); //Anexando struct na lista de struct.
  }

  l_atores_qnt_filme.ordena(); //Ordena lista de acordo com a sobrecarga de operador da struct.
  l_atores_qnt_filme.inverte(); //Inverte a lista de struct.
  l_atores_qnt_filme.inicia(); //Inicia iteração da lista.
  int contagem=0; //Declaração de variáveis.
  while(!l_atores_qnt_filme.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
      Qnt_filmes mensagem_saida=l_atores_qnt_filme.proximo(); //Recebendo dado dentro da lista.
      cout<<contagem+1<<")"<<mensagem_saida.Ator<< "__________Quantidade:"<< mensagem_saida.Qnt_filme_atuado<<endl; //Imprime mensagem na tela.
      contagem++; //Incrimentação da variável contagem.
      if(contagem==lim)break; //Se condicional for verdadeiro para loop.
  }
  cout<<endl<<endl; //Quebra de linha.
}

void Atores_trabalharam_atores(string Ator_base,thash<lista<string>> & Tab_ator,thash<lista<string>> & Tab_Filme){ //Função lista ordenadamente atores que trabalharam com um determinado ator passado por parâmetro.
  if(Tab_ator.existe(Ator_base)){ //Se o ator existe dentro da tabela hash de nome Tab_ator faz:
      lista<string> l_apoio_filmes=Tab_ator[Ator_base]; //Lista de string recebe valor de acordo com a chave de nome Ator_base dentro da tabela hash Tab_ator.
      thash<int> tabela_atores_ligados(2000); //Declaração de variável.
      l_apoio_filmes.inicia(); //Inicia iteração da lista.
      while(!l_apoio_filmes.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
          string s_apoio_filme=l_apoio_filmes.proximo(); //variável recebe valor dentro da lista.
          lista<string> l_apoio_atores=Tab_Filme[s_apoio_filme]; // /Lista de string recebe valor de acordo com a chave de nome s_apoio_filme dentro da tabela hash Tab_filme.
          l_apoio_atores.inicia(); //Inicia iteração da lista.
          while(!l_apoio_atores.fim()) { //Loop ocorre enquanto não estiver no fim da lista.
              string s_apoio_atores=l_apoio_atores.proximo(); //Variável recebendo dado dentro da lista.
              if (tabela_atores_ligados.existe(s_apoio_atores))tabela_atores_ligados[s_apoio_atores]++; //Se a chave existe na tabela, incrimenta valor de acordo com a chave que existe.
              else {
                  tabela_atores_ligados.adiciona(s_apoio_atores, 1); //Se a chave não existe adiciona na tabela hash a chave inexistente e com valor 1.
              }
          }
      }
      auto chaves=tabela_atores_ligados.chaves(); //Recebendo uma lista contendo as chaves da tabela de nome tabela_atores_ligados.
      chaves->ordena(); //Ordena a lista de chaves.
      chaves->escrevaSe(cout); //Imprime a lista das chaves com quebra de linha.
      cout<<endl<<endl; //Quebra de linha;
  }else{ //Caso o ator não exista na tabela hash de nome Tab_ator.
      cout<< "Ator_invalido"<<endl<<endl; //Imprime mensagem na tela.
  }
}

lista<string> separa(const string & texto, const string & sep){ //Função realiza separação de substrings de uma string de acordo com um separador e anexa em uma lista.
  int pos = 0; //Declaração de variável.
  int pos0 = 0; //Declaração de variável.
  lista<string> l; //Declaração de variável.
  string palavra; //Declaração de variável.
  if (texto.size() > 0) //Se a variável possuir tamanho maior que zero faça:
  {
      do { //Faça:
          pos = texto.find_first_not_of(sep,pos); //Inteiro de nome pos recebe posição da string.
          pos0 = texto.find_first_of(sep,pos); //Inteiro de nome pos0 recebe posição da string.
          palavra = texto.substr(pos,pos0 - pos); //Gerando uma substring de acordo com as posições obtidas pelos inteiros pos e pos0.
          l.anexa(palavra); //Anexa na lista a substring gerado.
          if(texto.find_first_not_of(sep,pos) == string::npos) break; //Se condicional estiver no fim da string, para o loop que está em execução.
          pos = texto.find_first_not_of(sep,pos0); //Inteiro de nome pos recebe nova posição da string.
      } while (pos != string::npos); //Enquanto não estiver no fim da string.
  }
  return l; //Retorna a lista de nome l.
}

void leitura_arquivo(thash<lista<string>> & tab_filmes,thash<lista<string>> & tab_atores){//Função realiza a leitura do arquivo obtendo duas tabelas hashs uma de nome tab_filmes e outra de nome tab_atores.
  ifstream arq("../dados.txt"); //Declaração de variável.
  lista<string> l; //Declaração de variável.
  string line; //Declaração de variável.
  if(arq.is_open()){ //Se o arquivo estiver aberto faça:
      while(getline(arq,line)){ //Enquanto o arquivo pegar linhas do arquivo e jogar na variável de nome line:
          l = separa(line,";"); //Variável de nome l recebe o retorno da função chamada separa.
          if(l.comprimento() == 3){ //Se o comprimento da lista for igual a três:
              string nome_filme = l.remove(0); //Obtendo o nome do filme do retorno de remover o dado que está na posição zero da lista.
              lista<string> atores = separa(l.remove(1),","); //obtendo uma lista de strings que contêm os nomes dos atores que atuaram naquele filme a partir da posição um da lista.
              tab_filmes.adiciona(nome_filme,atores); //Adiciona na tabela hash de nome tab_filmes, a chave como valor da variável nome_filme e valor da chave como valor da variável atores.
              atores.inicia(); //Inicia iteração da lista.
              while(!atores.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
                  string apoio_ator=atores.proximo(); //Variável recebe valor dentro da lista.
                  if(tab_atores.existe(apoio_ator)){ //Se a chave existe na tabela hash de nome tab_atores:
                      tab_atores[apoio_ator].anexa(nome_filme); //O valor da chave da tabela anexa o nome_filme.
                  }else{ //Senão chave não existe.
                      lista<string> l_add; //Declaração de variável.
                      l_add.anexa(nome_filme); //Anexa nome do filme na lista de nome l_add.
                      tab_atores.adiciona(apoio_ator,l_add); //adiciona na tabela uma chave que não existia até o momento e com valor de uma lista de nome l_add.
                  }
              }
          }

      }
  }
}
void todos_atores_atuaram_conj_filme(thash<lista<string>> & tab_filmes,lista<string> conj_filmes){ //Função imprime todos os atores que atuaram em um conjunto de filmes passado por parãmetro.
  string filme,ator; //Declaração de variáveis.
  lista<string> l_atores; //Declaração de variável.
  thash<int> tab_oa(tab_filmes.tamanho()); //Declaração de variável.
  conj_filmes.inicia(); //Inicia iteração da lista.
  while(! conj_filmes.fim()){ //Loop ocorre enquanto não estiver no fim da lista.
      filme = conj_filmes.proximo(); //Recebendo dado dentro da lista.
      l_atores = tab_filmes[filme]; //Recebendo valor da tabela hash de acordo com a chave de nome filme.
      l_atores.inicia(); //Inicia iteração da lista.
      while(!l_atores.fim()) { //Loop ocorre enquanto não estiver no fim da lista.
          ator = l_atores.proximo(); //Recebendo dado dentro da lista.
          if (tab_oa.existe(ator)) { //Se a chave existe na tabela hash de nome tab_oa:
              tab_oa[ator]++; //Incrimenta valor da chave que existe.
          } else { //Senão a chave não existe.
              tab_oa.adiciona(ator, 1); //Adiciona na tabela hash de nome tab_oa a chave do valor da variável ator e com valor 1.
          }
      }
  }
  auto chaves_oa = tab_oa.chaves(); //Recebendo as chaves da tabela hash de nome tab_oa.
  bool retorno=true; //Declaração de variável.
  chaves_oa->inicia(); //Inicia iteração da lista.
  while(! chaves_oa->fim()){ //Loop ocorre enquanto não estiver no fim da lista.
      string chave_oa = chaves_oa->proximo(); //Recebendo dado dentro da lista.
      int valor_oa = tab_oa[chave_oa]; //Variável recebe valor de acordo com a chave da tabela hash de nome tab_oa.
      if(valor_oa == conj_filmes.comprimento()){ //Caso a variável tenha o mesmo valor do comprimento da lista de nome conj_filmes:
          cout << chave_oa << endl; //Imprime na tela texto.
          retorno=false; //Variável recebe novo estado.
      }
  }
  if(retorno)cout<<"Nenhum ator em comum"<<endl<<endl; //Caso condicional for verdadeiro imprime texto na tela.
}

void list_ord_de_acordo_popularidades(thash<lista<string>> & tab_filmes,int top){ //Função listagem de popularidade de acordo com um ator passado por parâmetro.
  lista<Qnt_filmes> lista_de_contagem; //Declaração de variável.
  thash<int> Tab_contagem(100000); //Declaração de variável.
  auto l_chaves_filmes=tab_filmes.chaves();
  l_chaves_filmes->inicia();
  while(!l_chaves_filmes->fim()){
      string filme_apoio=l_chaves_filmes->proximo();
      lista<string> l_atores_do_filme=tab_filmes[filme_apoio];
      l_atores_do_filme.inicia();
      while(!l_atores_do_filme.fim()){
          string apoio_ator=l_atores_do_filme.proximo();
          if(Tab_contagem.existe(apoio_ator))Tab_contagem[apoio_ator]++;
          else{
              Tab_contagem.adiciona(apoio_ator,1);
          }
      }
  }
  auto lista_p_struct=Tab_contagem.chaves();
  lista_p_struct->inicia();
  while(!lista_p_struct->fim()){
      string str_add_struct=lista_p_struct->proximo();
      Qnt_filmes st_p_ordenar;
      st_p_ordenar.Qnt_filme_atuado=Tab_contagem[str_add_struct];
      st_p_ordenar.Ator=str_add_struct;
      lista_de_contagem.anexa(st_p_ordenar);
  }
  lista_de_contagem.ordena();
  lista_de_contagem.inverte();
  lista_de_contagem.inicia();
  int contagem=0;
  while(!lista_de_contagem.fim()){
      Qnt_filmes apoio_cout=lista_de_contagem.proximo();
      contagem++;
      cout<<contagem<<")Ator:  "<<apoio_cout.Ator<<"_________Quantidade: "<<apoio_cout.Qnt_filme_atuado<<endl<<endl;
      if(contagem==top)break;
  }
}

int menu () //Função de interface menu.
{
  int opcao; //Declaração de variável.
  cout <<"1)Os filmes em que um ator atuou "<< endl; //Imprime texto na tela.
  cout <<"2)Os atores que atuaram em todos os filmes de um certo conjunto de filmes"<< endl; //Imprime texto na tela.
  cout <<"3)Os atores que trabalharam com um dado ator"<< endl; //Imprime texto na tela.
  cout <<"4)A listagem ordenada de atores, de acordo com suas popularidades (a popularidade é dada pela quantidade de atores com que um dado ator trabalhou)"<< endl; //Imprime texto na tela.
  cout <<"5)A listagem ordenada de atores, de acordo com a quantidade de filmes em que atuaram"<< endl; //Imprime texto na tela.
  cout <<"0)Sair do programa"<< endl; //Imprime texto na tela.

  cin>>opcao; //lendo opcao do teclado.
  thash<lista<string>> Tabela_Ator(200000); //Declaração de variável.
  thash<lista<string>> Tabela_Filme(450000); //Declaração de variável.
  leitura_arquivo(Tabela_Filme,Tabela_Ator); //Chama função para ler o arquivo e criar duas tabelas.
  switch (opcao){ //Opcao
      case 1: { //Caso 1.
          string apoio;
          cout<<"Digite o nome do ator desejado"<<endl; //Imprime texto na tela.
          getchar();
          getline(cin,apoio); //Recebendo dado do usuário através.
          if(Tabela_Ator.existe(apoio)){ //Condicional verifica se chave existe.
              lista<string> l_filmes_atores=Tabela_Ator[apoio]; //Recebendo valor referente a chave da tabela hash de nome Tabela_Ator.
              l_filmes_atores.ordena(); //Ordena lista.
              l_filmes_atores.escrevaSe(cout); //Imprime dados dentro da lista.
              cout<<endl<<endl; //Quebra de linha.
          }else{
              cout<<"Ator invalido"<<endl; //Imprime texto na tela.
          }
          break;
      }
      case 2: { //Caso 2.
          string teclado; //Declaração de variável.
          lista<string> conj_filmes; //Declaração de variável.
          do{
              cout << "Digite o nome de um filme: "; //Imprime texto na tela.
              getchar();
              getline(cin,teclado); //Recebendo dado do usuário através do teclado.
              conj_filmes.anexa(teclado); //Anexa variável teclado na lista.
          } while(! teclado.empty()); //Loop acontece enquanto variável teclado não estiver vazia.
          todos_atores_atuaram_conj_filme(Tabela_Filme, conj_filmes); //Chama função todos_atores_atuaram_conj_filme.
          break;
      }
      case 3: { //Caso 3.
          string apoio; //Declaração de variável.
          cout<<"Digite o nome do ator desejado"<<endl; //Imprime texto na tela.
          getchar();
          getline(cin,apoio); //Recebendo dado do usuário através do teclado.
          Atores_trabalharam_atores(apoio,Tabela_Ator,Tabela_Filme); //Chama função atores_trabalharam_atores.
          break;
      }
      case 4: { //Caso 4.
          cout<<"Digite a quantidade que você deseja na classificação"<<endl;
          int top_x;
          cin>>top_x;
          list_ord_de_acordo_popularidades(Tabela_Filme,top_x); //Chama função list_ord_acordo_popularidades.
          break;
      }
      case 5: { //Caso 5.
          cout << "Digite qual o comprimento da classificação..." << endl; //Imprime texto na tela.
          int apoio; //Declaração de variável.
          cin >> apoio; //Recebendo dado do usuário através do teclado.
          Lista_ordenada_filmes_atuados(Tabela_Ator, apoio); //Chama função Lista_ordenada_filmes_atuados.
          break;
      }
      case 0: //Caso 0.
          break;
      default: //Nenhuma opção dentre os possíveis de casos.
          cout<< "Operação invalida"<<endl; //Imprime texto na tela.
  }
  return opcao; //Retorna valor da variável opcao.
}


int main () {
  int opcao; //Declaração de variável.
  do{
      opcao = menu();
  } while (opcao != 0);
  return 0;
}





