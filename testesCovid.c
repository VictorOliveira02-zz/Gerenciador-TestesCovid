/*
                                      Universidade Federal de Vicosa - CRP
                                                  20/05/2021
    -> SIN110 - Prof. Matheus Haddad e Prof. Leandro Furtado
    -> Trabalho Final - testesCovid
    -> Repositorio do projeto: https://github.com/VictorOliveira02/Gerenciador-TestesCovid
    -> Checklist / Anotacoes no Notion: https://www.notion.so/Trabalho-Final-SIN110-testesCovid-1a37d9e7263c44c7a50049e4619e6153
*Victor Alves de Oliveira -  6954 - T1
*Rafael Mantovani de Souza - 7319 - T1
*Bruno Marques da Silva -    6972 - T1
*/

//Bibliotecas Importadas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

typedef struct sData //struct pra data
{
  int dia; //Variavel para armazenar o dia
  int mes; // Variavel para armazenar o mês
  int ano; // Variavel para armazenar o ano

} Data;

int idade_atual(int ano_nasc) // função para calcula a idade atual
{
  struct tm *data_atual;
  time_t ano;
  time(&ano);
  data_atual = localtime(&ano);
  int year = data_atual->tm_year + 1900;
  return year - ano_nasc;
}

typedef struct sCadastro //strcut para os cadastros
{
  char Nome[40];   // Declarando a variável do tipo char para armazenar o nome
  char CPF[8];     // Declarando a variável do tipo char para armazenar cpf
  int Idade;       // Delcarando variável do tipo inteiro para armazenar idade
  int n_teste;     // Declarando Variável do tipo inteiro para armazenar número de teste
  char Sexo;       // Declarando Variável do tipo char para armazenar o sexo
  char Bairro[20]; // Declarando Variável do tipo char para armazenar o bairro
  char COVID19[3]; // Declarando Variável do tipo char para armazenar o resultado do teste de covid-19
  Data nascimento; // Declarando a struct DATA para armazenar a data de nascimento
  char valido[5];

} Cadastro;

void Cadastrar_testes(Cadastro **testes, int *posicao) //Preenche os cadastros
{

  int num_testes, i, tam; // Variáveis, representando o numero de teste, a variável de controle, e o tamanho do espaço a ser alocado

  printf("Digite o numero de testes que serao cadastrados: "); // Pergunta para o usuário a quantidade de teste a ser cadastrado
  scanf("%d", &num_testes);                                    // Guarda a quantidade de teste
  getchar();

  //tamanho inicializa da posicao 0 caso nao tenha nehum cadastro anteriormente,caso tenha,inicializa da posicao seguinte.
  tam = *posicao + num_testes;

  //Aloca dinamicamente os testes cadastrados
  if (*testes == NULL)
  {
    *testes = (Cadastro *)malloc(sizeof(Cadastro) * tam); // Alocação dinâmica, nessa caso, alocando um espaço do tamanho do struct cadastro
  }
  else
  {
    *testes = (Cadastro *)realloc(*testes, sizeof(Cadastro) * tam); //realocacao no caso de ja ter algum teste cadastrado
  }

  if (*testes == NULL) // verificando se a memória foi alocada com sucesso
  {
    printf("Nao existe espaco na memoria! "); // exibindo uma notificação caso a memória nao seja alocada
    exit(1);                                  // caso a memória não seja alocada, o programa é abortado
  }

  for (i = *posicao; i < tam; i++) //inicializacao da estrutura de repeticao
  {

    printf("\nTeste %d\n", i + 1); // exibe o numero do teste e o numero do teste

    printf("\nDigite o nome: "); //exibindo uma pergunta,no caso, o nome do paciênte
    gets((*testes)[i].Nome);     // Guarda a informação do usuário

    printf("Digite seu CPF: "); //Exibindo uma pergunta, no caso, o CPF do paciênte
    gets((*testes)[i].CPF);     // Guarda a informação do usuário

    printf("Data de nascimento (D/M/A)"); // Exibindo a ordem que precisa ser digitado

    printf("\nDia: ");                         // Exibindo uma pergunta, no caso, o dia de nascimento
    scanf("%d", &(*testes)[i].nascimento.dia); // Guarda a informação do usário
    getchar();

    printf("Mes: ");                           // Exibindo uma pergunta, no caso, o mês de nascimento
    scanf("%d", &(*testes)[i].nascimento.mes); // Guarda a informação do usário
    getchar();

    printf("Ano: ");                           // Exibindo uma pergunta, no caso, o ano de nascimento
    scanf("%d", &(*testes)[i].nascimento.ano); // Guarda a informação do usário
    getchar();

    printf("Digite seu sexo [M/F]: "); // Exibindo uma pergunta, no caso, o sexo do usuário
    scanf("%c", &(*testes)[i].Sexo);   // Guarda a informação do usário
    getchar();

    printf("Digite seu bairro: "); // Exibindo uma pergunta, no caso, o nome do bairro usuário
    gets((*testes)[i].Bairro);     // Guarda a informação do usário

    printf("Digite o resultado do seu teste [P/N]: "); // Exibindo uma pergunta, no caso, o resultado do bairro usuário
    gets((*testes)[i].COVID19);                        // Guarda a informação do usário

    strcpy((*testes)[i].valido, "SIM"); // Copia o caracter S para a variavel valido
  }

  *posicao += num_testes; // O for inicializa da posicao 0 caso não tenha nehum cadastro anteriormente,caso tenha,inicializa da posiçãoo seguinte.
}

//imprime cadatros
void imprime_cad(Cadastro cadastro)
{
  printf("Nome: %s\n", cadastro.Nome);                                                                                 // Exibe o nome do usario cadastrado
  printf("CPF: %s\n", cadastro.CPF);                                                                                   // Exibe o cpf do usuario
  printf("Data de Nascimento: %d/%d/%d\n", cadastro.nascimento.dia, cadastro.nascimento.mes, cadastro.nascimento.ano); // Exibindo a Data de nascimento do usuário cadastrado
  printf("Idade: %d anos\n", idade_atual(cadastro.nascimento.ano));                                                    // Exibe a idade do usuário cadastrado
  printf("Sexo: %c\n", cadastro.Sexo);                                                                                 // Exibe o sexo do usuário cadastrado
  printf("Bairro: %s \n", cadastro.Bairro);                                                                            // Exibe o bairro do usuário cadastrado
  printf("COVID-19: %s \n", cadastro.COVID19);                                                                         // Exibe o resultado do teste do usuário cadastrado
  printf("Valido: %s \n", cadastro.valido);                                                                            // Exibe se o cadastro do usário está ativo ou não
  getchar();
}

//consulta o teste pelo nome cadastrado
void consulta(char nome[], int quant_testes, Cadastro testes[])
{

  int i, aux; // Declarando as variáveis para do tipo inteiro

  aux = -1;

  //busca o nome com base na quantidade de testes.
  for (i = 0; i <= quant_testes; i++)
  {

    if (strcmp(nome, testes[i].Nome) == 0) // Comparando o nome digitado pelo usuário com os nomes dos testes salvos, e verificando se ele já foi cadastrado
    {
      //caso o usuario esteja cadastrado,aux recebe o indice do teste
      aux = i;

      break;
    }
  }

  //verifica se a pessoa possui um cadastro(resultado foi encontrado)
  if (aux >= 0)
  {
    printf("\nNome: %s\n", testes[aux].Nome);                                                                                     //Exibe o nome da pessoa registrada
    printf("CPF: %s\n", testes[aux].CPF);                                                                                         // Exibe o cpf da pessoa registrada
    printf("Data de Nascimento: %d/%d/%d\n", testes[aux].nascimento.dia, testes[aux].nascimento.mes, testes[aux].nascimento.ano); // Exibe a data de nascimento da pessoa Registrada
    printf("Idade: %d\n", idade_atual(testes[aux].nascimento.ano));                                                               // Exibe a idade da pessoa registrada
    printf("Sexo: %c\n", testes[aux].Sexo);                                                                                       // Exibe o sexo da pessoa registrada
    printf("Bairro: %s \n", testes[aux].Bairro);                                                                                  // Exibe o bairro da pessoa registrada
    printf("COVID-19: %s \n", testes[aux].COVID19);                                                                               // Exibe o resultado do teste covid-19 da pessoa registrada
    printf("Valido: %s \n ", testes[aux].valido);                                                                                 // Exibe se o cadastro e valido ou nao
  }
  else
  {
    printf("Nenhum teste encontrado!"); // Caso o usuario pesquisado nao tenha um cadastro
  }

  printf("\nPressione enter para continuar.");                                          //Exibe uma ação para o usuário executar
  printf("\n----------------------------------------------------------------------\n"); // formatação
  getchar();
}

//imprime cadastro atraves do txt
void imprime_cad_txt(char nome_teste_txt[])
{
  FILE *arquivo;

  char linha[100]; // Variavel para ler o texto do arquivo

  arquivo = fopen(nome_teste_txt, "r"); // Abre um arquivo TEXTO para LEITURA
  if (arquivo == NULL)                  // condição, caso arquivo seja igual a NULL, o arquivo não abrirá
  {
    printf("Erro ao abrir arquivo!"); //Exibe um erro, o arquivo não foi aberto
  }

  while (fgets(linha, 100, arquivo) != NULL)
  {
    printf("%s", linha); //exbindo as informações do arquivo
  }
  getch();
  fclose(arquivo); // fechando o arquivo
}

// Cancela testes cadastrados
void cancela_teste(Cadastro cadastros[], int num_teste)
{
  int indice; // variavel de controle
  char opcao; // variavel para armazenar a opção do usuário, no caso se deseja excluir teste ou não

  indice = num_teste - 1; // pega a posicao do teste no vetor

  imprime_cad(cadastros[indice]); // Chama a função que imprime os testes e passa como parametro o vetor de cadastros na posicao indice

  printf("\n\n"); // formatação //

  printf("Deseja realmente cancelar o teste %d ?[S/N]: ", num_teste); // Exibe uma pergunta para o usuário, se deseja excluir ou não teste do usuário//
  scanf("%c", &opcao);

  if (opcao == 'S' || opcao == 's') //Caso a escolha seja sim,a funçao strcpy copia 'N' para "Valido".
  {
    strcpy(cadastros[indice].valido, "NAO"); // Copiando o caracter N para o status do teste do usuário
    printf("Cancelado com sucesso!!!");      // Exbe a confirmação de que o teste foi cancelado
  }

  getchar();
}

void salvar_txt(char nome_teste_txt[], int quant_testes, Cadastro testes[]) // função para salavar os testes em .txt
{
  //criando a varivel ponteiro para o arquivo
  FILE *arquivo;
  strcat(nome_teste_txt, ".txt"); // Faz a concatenação para garantir que a extensão do arquivo seja txt

  arquivo = fopen(nome_teste_txt, "a"); //abrindo o arquivo

  if (arquivo == NULL) // Comparando o arquivo com NULL
  {
    printf("Erro ao abrir arquivo!"); //mensagem para o usuario que o arquivo nao foi aberto
  }
  else
  {
    printf("Arquivo %s criado com sucesso!", nome_teste_txt); // Exbindo uma notificação caso o arquivo seja aberto
  }

  for (int cont = 0; cont < quant_testes; cont++) // criando um loop com o fim quando a vairavel de controle seja ligeiramente menor do que a quantidade de teste
  {
    fprintf(arquivo, "\n----------------------------------------------------------------------\n");                                      //formatação
    fprintf(arquivo, "TESTE : %d\n", cont + 1);                                                                                          // Registrando o numero do teste no arquivo
    fprintf(arquivo, "NOME: %s\n", testes[cont].Nome);                                                                                   // Registrando o nome da pessoa registrada no arquivo
    fprintf(arquivo, "CPF: %s\n", testes[cont].CPF);                                                                                     // Registrando o cpf da pessoa registrada no arquivo
    fprintf(arquivo, "Data de Nasc: %d/%d/%d\n", testes[cont].nascimento.dia, testes[cont].nascimento.mes, testes[cont].nascimento.ano); // Gravando a data de nascimento da pessoa registrada no arquivo
    fprintf(arquivo, "SEXO: %c\n", testes[cont].Sexo);                                                                                   // Registrando o sexo da pessoa registrada no arquivo
    fprintf(arquivo, "BAIRRO: %s\n", testes[cont].Bairro);                                                                               // Registrando o bairro da pessoa registrada no arquivo
    fprintf(arquivo, "COVID-19: %s\n", testes[cont].COVID19);                                                                            // Registrando o resultado do teste da covid-19 no arquivo
    fprintf(arquivo, "\n----------------------------------------------------------------------\n");
    // formatação
  }

  fclose(arquivo);
}

// função para registrar o numero de infectados
int num_infectados(Cadastro cadastros[], int quant_testes)
{
  int i, infectados; // variaveis de controle e quantidade de infectados do tipo inteiro

  infectados = 0; // numero de infectados recebe  zero para controle de variavel

  for (i = 0; i < quant_testes; i++) // Estrutura de repeticao apra contar a quantidade de infectados
  {

    if (strcmp(cadastros[i].COVID19, "P") == 0) // Verifica se  o resultado dos testes das pessoas registradas e igual a P (positivo para covid19)
    {
      infectados++; // Se a variavel covid no vetor de cadastros for igual a P, a contagem de infectados aumenta
    }
  }

  return infectados; // retorna o numero de infectados
}

// Função conta a quantidade de jovens infectados.
int jovens_infect(Cadastro cadastros[], int quant_testes)
{
  int i, jovens; // Variaveis de controle i  e variavel que contabiliza a quantidade de jovens

  jovens = 0; // Jovens recebe zero para controle

  for (i = 0; i < quant_testes; i++) // Criacao de um loop inicializado em 0 e que funciona enquanto i for menor que a quantidade de cadastros
  {
    if ((idade_atual(cadastros[i].nascimento.ano) < 20) && (strcmp(cadastros[i].COVID19, "P") == 0)) // Verifica se a idade da pessoa cadastrada na psoição i é menor que 20 e se o teste  é igual a P (positivo para covid 19)
    {
      jovens++; // Caso se encaixe nas condicoes, aumenta em 1 a quantidade de jovens infectados
    }
  }

  return jovens; // Retorna a quantidade de jovens infectados
}

//Função conta a quantidade de adultos infectados.
int adultos_infect(Cadastro cadastros[], int quant_testes)
{
  int i, adultos; // Variavel de controle e variavel que contabiliza a quantidade de adultos infectados

  adultos = 0; //  adultos recebe zero para controle //

  for (i = 0; i < quant_testes; i++) // Criação de um loop inicializado em 0 e que funciona enquanto i for menor que a quantidade de cadastros
  {
    if ((idade_atual(cadastros[i].nascimento.ano) >= 20) && ((idade_atual(cadastros[i].nascimento.ano) < 60)) && (strcmp(cadastros[i].COVID19, "P") == 0)) // Verifica se a idade da pessoa cadastrada na posicao i é maior ou igual a 20 e menor que 60 e se o teste é igual a P (positivo para covid 19)
    {
      adultos++; // Caso se encaixe nas condicoes, aumenta o número de adultos infectados em 1
    }
  }

  return adultos; // Retorna o número de adultos infectados
}

// Função que conta a quantidade de idosos infectados.
int idosos_infect(Cadastro cadastros[], int quant_testes)
{
  int i, idosos; // Variavel de controle e variavel que contabiliza a quantidade de idosos

  idosos = 0; // Idoso recebe 0 para controle
  for (i = 0; i < quant_testes; i++)
  {
    if ((idade_atual(cadastros[i].nascimento.ano) >= 60) && (strcmp(cadastros[i].COVID19, "P") == 0)) // Verifica se  idade das pessoa cadastrada na posicao i é maior ou igual a 60 e se o teste é igual a P (positivo para covid 19)//
    {
      idosos++; //Caso se encaixe nas condicoes, aumenta a quantidade de idosos infectados em 1
    }
  }

  return idosos; // Retorna o numero de idosos infectados
}

//Funcao basica pra calcular porcentagem.
float porcentagem(int total, int quant_element)
{
  float pct; // Variável do tipo real para calcular a porcentagem

  pct = (quant_element * 100.0) / total; // Fórmula para calcular a porcentagem

  return pct; // Retorna o valor da porcentagem
}

//Funcao responavel por criar os relatorios
void relatorio(Cadastro cadastros[], int quant_testes)
{
  float pct_jovens, pct_adultos, pct_idosos, pct_infectados, pct_naoinfectados; // Variaveis utilizadas do tipo real para guardar os valores das porcentagens de jovens,adultos,idosos,pessoas infectadas e não infectadas
  int jovens, adultos, idosos, nao_infectados, pessoa_infectada;                // Variaveis do tipo inteiro para mostrar a quantidade de jovens,adultos,idosos,pessoas não infectadas e pessoas infectadas

  printf("Total de pessoas cadastradas: %d\n", quant_testes); // Exibindo a quantidade de testes cadastrados

  pessoa_infectada = num_infectados(cadastros, quant_testes); //Total de pessoas infectadas

  nao_infectados = quant_testes - pessoa_infectada; //Total de pessoas nao infectadas

  pct_infectados = porcentagem(quant_testes, pessoa_infectada); //Porcentagem de infectados

  pct_naoinfectados = porcentagem(quant_testes, nao_infectados); //Porcentagem de nao infectados

  jovens = jovens_infect(cadastros, quant_testes); //Quantidade de jovens infectados

  adultos = adultos_infect(cadastros, quant_testes); //Quantidade de adultos infectados

  idosos = idosos_infect(cadastros, quant_testes); //Quantidade de idosos infectados

  pct_jovens = porcentagem(pessoa_infectada, jovens); // Porcentagem de jovens infectados

  pct_adultos = porcentagem(pessoa_infectada, adultos); // Porcentagem de adultos infectados

  pct_idosos = porcentagem(pessoa_infectada, idosos); // Porcentagem de idosos infectados

  printf("Pessoas nao infectadas: %d (%.2f%%)\n", nao_infectados, pct_naoinfectados); // Exibe a quantidade de pessoas não infectadas e a porcentagem que elas representam //
  printf("Pessoas infectadas: %d (%.2f%%)\n", pessoa_infectada, pct_infectados);      // Exibe a quantidade de pessoas  infectadas e a porcentagem que elas representam //
  printf("\tJovens infectados:%d (%.2f%% dos infectados)\n", jovens, pct_jovens);     // Exibe a quantidade de jovens infectados e a porcentagem que eles representam //
  printf("\tAdultos infectados:%d (%.2f%% dos infectados)\n", adultos, pct_adultos);  // Exibe a quantidade de adultos infectados e a porcentagem que eles representam //
  printf("\tIdosos infectados:%d (%.2f%% dos infectados)\n", idosos, pct_idosos);     // Exibe a quantidade de idosos infectados e a porcentagem que eles representam //
}

int main() // Função principal
{
  int i;                   // Variavel de controle do tipo inteiro//
  int quant_testes;        // Variavel que armazena a quantidade de teste do tipo inteiro
  int opcao, num_do_teste; // Variaveis do tipo inteiro, que representa a escolha do menu e o numero do teste
  Cadastro *testes;        // Declarando a stuct Cadastro e nomeando ela na forma de vetor
  char nome[50];           // Variavel do tipo char, usada para buscar teste ja cadastrados
  char nome_teste_txt[50]; // Variavel do tipo char, usada para nomear o arquivo em txt

  testes = NULL; // Testes recebe null

  opcao = -1;       // Variavel de controle
  quant_testes = 0; // Varivael de controle

  while (opcao != 0) // Executar as linhas abaixo até o valor digitado ser diferente de zero
  {
    system("cls||clear");

    printf("\n------------------------------------------\n");         // Formatação
    printf("\n              TestesCovid-19              \n");         // Exibe o menu do programa
    printf("\n------------------------------------------\n");         // Formatação
    printf("\n              Menu de Opcoes              \n");         // Exibe o título do menu
    printf("\n------------------------------------------\n");         // Formatação
    printf("\nESCOLHA UMA DAS OPCOES ABAIXO.\n\n");                   // Exibe uma ordem para o usuário, para começar a utilizar o programa
    printf("[ 1 ] - Cadastrar Novos Testes.\n");                      // Exibe a primeira opção do menu
    printf("[ 2 ] - Consultar Teste.\n");                             // Exibe a segunda opção do menu
    printf("[ 3 ] - Cancelar Teste.\n");                              // Exibe a terceira opção do menu
    printf("[ 4 ] - Salvar Informacoes em Arquivo.\n");               // Exibe a quarta opção do menu
    printf("[ 5 ] - Visualizar Informacoes de Testes Realizados.\n"); // Exibe a quinta opção do menu
    printf("[ 6 ] - Relatorio de Testes Realizados.\n");              // Exibe a sexta opção do menu
    printf("[ 0 ] - Sair.\n");                                        // Exibe a sétima opção do menu

    printf("\n-> DIGITE A SUA OPCAO: "); // Pede ao usuário para digitar uma opção
    scanf("%d", &opcao);                 // Guarda a opção digitada
    getchar();

    system("cls||clear");

    switch (opcao) // sistema de escolhar
    {
    case 1:                                                                                 // primeira escolha
      Cadastrar_testes(&testes, &quant_testes);                                             // função cadastrar teste, com o argumento,struct Cadastro e quantidade de testes
      printf("\nPressione enter para continuar.");                                          //Exibindo Ordem para o usuário
      printf("\n----------------------------------------------------------------------\n"); // formatação

      getchar();
      break; // Quebra de continuidade

    case 2:                                     // Segunda escolha
      printf("Digite um nome para consulta: "); //Exibe uma ordem para o usuario
      gets(nome);                               // guarda a informação digitada

      consulta(nome, quant_testes, testes); // Função consulta, com os argumentos, nome para consulta, quantidade de testes e struct cadastro
      break;                                // Quebra de continuidade

    case 3:                                               // Terceira escolha
      printf("Digite o numero do teste para cancelar: "); // Exibe uma ordem para o usuário
      scanf("%d", &num_do_teste);                         // Guarda a infromação digitada pelo usuário
      printf("\nPressione enter para continuar.");        // Ordem para o usuário

      printf("\n----------------------------------------------------------------------\n"); // Formatação

      getchar();

      cancela_teste(testes, num_do_teste); // Função de cancelamento de testes com os argumentos, struct Cadastro e numero de testes//
      break;                               // Quebra de continuidade

    case 4:                                       //Quarta escolha
      printf("Como deseja nomear o arquivo ?: "); // Exibe uma pergunta para o usuário
      scanf("%s", &nome_teste_txt);               // Guarda a resposta da pergunta

      salvar_txt(nome_teste_txt, quant_testes, testes);                                     // Função que Registra os testes no arquivo txt, com os argumentos, para nomear o arquivo ,quantidade de testes e struct Cadastro
      printf("\nPressione enter para continuar.");                                          // Ordem para o usuário
      printf("\n----------------------------------------------------------------------\n"); // Formatação
      getchar();
      break;

    case 5:                                                                                 // Quinta Esolha
      imprime_cad_txt(nome_teste_txt);                                                      // Função que imprime  texto do arquivo txt, com o argumento de nomear arquivo
      printf("\nPressione enter para continuar.");                                          // Ordem para o usuário
      printf("\n----------------------------------------------------------------------\n"); // Formatação
      getchar();
      break; // Quebra de continuidade

    case 6:
      relatorio(testes, quant_testes);                                                      // Função de relatorios, com os argumentos, struct  Cadastro e quantidade de testes
      printf("\nPressione enter para continuar.");                                          // Ordem para o usuário
      printf("\n----------------------------------------------------------------------\n"); // Formatação
      getchar();
      break; // Quebra de continuidade
    }
  }

  free(testes); // Desalocação da memória
  return 0;     // Retorno da função principal
}