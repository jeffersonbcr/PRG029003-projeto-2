# Prglib: biblioteca de estruturas de dados elementares

A [Prglib](https://wiki.sj.ifsc.edu.br/wiki/index.php/PRG29003:_Etapa_2:_A_constru%C3%A7%C3%A3o_da_prglib) é uma pequena biblioteca contendo estruturas de dados para fins didáticos. Ela foi escrita para a disciplina de [Programação II](https://wiki.sj.ifsc.edu.br/wiki/index.php/PRG29003:_Introdu%C3%A7%C3%A3o_a_C%2B%2B) da [Engenharia de Telecomunicações](https://wiki.sj.ifsc.edu.br/wiki/index.php/Curso_de_Engenharia_de_Telecomunica%C3%A7%C3%B5es) do [IFSC Câmpus São José](http://www.sj.ifsc.edu.br/). E contém as seguintes estruturas de dados:
* __Fila__: uma fila circular com capacidade definido no momento de sua criação
* __Pilha__: uma pilha cuja capacidade também é definida no instante de sua criação
* __Lista__: uma lista duplamente encadeada, e possivelmente circular (depende da implementação do estudante)
* __Tabela hash__: uma tabela hash com quantidade de linhas (buckets) definida no instante de sua criação. Além disso, por simplicidade as chaves são do tipo string
* __Árvore de pesquisa binária__: uma árvore com operações de balanceamento com algoritmo [AVL](https://en.wikipedia.org/wiki/AVL_tree)

# Programa de Estatísticas sobre Atores e Filmes
Este relatório descreve o código em C++ para um programa de estatísticas sobre atores e filmes. O código utiliza a biblioteca prglib e é composto pelos arquivos projeto2.h e projeto2.cpp. O objetivo do programa é fornecer informações sobre os atores e filmes com base nas opções selecionadas pelo usuário.

## Estrutura do Código
O código está organizado da seguinte maneira:

## Definição de funções:

- ler_escolha: lê a escolha do usuário e retorna a opção selecionada.
- funcao_um: realiza a busca de filmes em que um ator atuou ou a listagem ordenada de atores de acordo com a quantidade de filmes em que atuaram em comum.
- funcao_dois: realiza a busca de atores que atuaram em um dado filme, os atores que trabalharam com um dado ator ou a listagem ordenada de atores de acordo com a quantidade de filmes em que atuaram.
- Separa: separa uma string em substrings com base em um separador fornecido e as anexa em uma lista.
- Add_struct: cria uma estrutura info_filme com base nos dados fornecidos em uma string.
- Leitura_arquivo: lê um arquivo de dados e retorna uma lista de estruturas info_filme com as informações dos filmes e atores.
### Função main:

Leitura do arquivo de dados e armazenamento em uma lista Mapa.
Exibição do menu de opções para o usuário.
Leitura da opção selecionada pelo usuário.
Execução da função correspondente à opção selecionada.
Exibição dos resultados.
Funcionamento do Código
O programa lê o arquivo de dados contendo informações sobre filmes e atores e armazena essas informações em uma lista chamada Mapa.

O programa exibe um menu de opções para o usuário, fornecendo diferentes funcionalidades relacionadas a atores e filmes.

O usuário seleciona uma opção digitando o número correspondente.

Com base na opção selecionada, o programa chama a função correspondente para executar a funcionalidade escolhida.

As funções funcao_um e funcao_dois realizam a busca e manipulação dos dados de acordo com as opções escolhidas pelo usuário.

Os resultados da busca são exibidos na tela.

O programa é encerrado.

## Dependências e Arquivos Necessários
O código depende do arquivo "projeto2.h", que contém as definições das funções utilizadas no programa.
O código também requer um arquivo de dados "dados.txt" localizado no diretório ../ para obter as informações dos filmes e atores.
Modificações e Expansões Possíveis
Este código pode ser modificado e expandido de acordo com os requisitos específicos do projeto. Algumas possíveis modificações e expansões incluem:






