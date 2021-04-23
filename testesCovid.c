/*
                                        Universidade Federal de Viçosa - CRP
                                                13/05/2021

    -> SIN110 - Prof. Matheus Haddad e Prof. Leandro Furtado
    -> Trabalho Final - testesCovid
    -> Reposiório do projeto: https://github.com/VictorOliveira02/Gerenciador-TestesCovid

*Victor Alves de Oliveira -  6954 - T1
*Rafael Mantovani de Souza - 7319 - T1
*Bruno Marques da Silva -    6972 - T1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int ano_atual()
{
  struct tm *data_atual;
  time_t ano;
  time(&ano);
  data_atual = localtime(&ano);
  int year = data_atual->tm_year + 1900;
  return year;
}

typedef struct sData
{
  int dia;
  int mes;
  int ano;

} Data;

typedef struct sCadastro
{
  char Nome[40];
  char CPF[8];
  int Idade;
  int n_teste;
  char Sexo;
  char Bairro[20];
  char COVID19[3];
  Data nascimento;

} Cadastro;

//Preenche os cadastros;
void Cadastrar_testes(Cadastro testes[], int *posicao)
{

  //pergunta ao usuario o numero de cadastros a ser preenchido.
  int num_testes, i;

  printf("Digite o numero de testes que serao cadastrados: ");
  scanf("%d", &num_testes);
  getchar();

  //inicializa da posicao 0 caso não tenha nehum cadastro anteriormente,caso tenha,inicializa da posição seguinte.
  for (i = *posicao; i < (num_testes + *posicao); i++)
  {

    printf("\nTESTE - %d\n", i + 1);
    testes[i].n_teste = i + 1; //Passando nuemro do teste
    printf("Digite o NOME: ");
    gets(testes[i].Nome);

    printf("Digite seu CPF: ");
    getchar();
    scanf("%s", &testes[i].CPF);

    printf("Sobre a sua data de nascimento digite: ");
    printf("\nDIA: ");
    getchar();
    scanf("%d", &testes[i].nascimento.dia);

    printf("\nMES: ");
    getchar();
    scanf("%d", &testes[i].nascimento.mes);

    printf("\nANO: ");
    getchar();
    scanf("%d", &testes[i].nascimento.ano);

    printf("Digite seu SEXO[M/F]: ");
    getchar();
    scanf("%c", &testes[i].Sexo);

    printf("Digite seu BAIRRO: ");
    getchar();
    gets(testes[i].Bairro);

    printf("Digite o resultado do seu teste [P/N]: ");
    getchar();
    gets(testes[i].COVID19);
  }

  *posicao += num_testes;
}

//consulta o teste pelo nome cadastrado.
void consulta(char nome[], int quant_testes, Cadastro testes[])
{

  int i, aux;

  aux = -1;

  //busca o nome com base na quantidade de testes.
  for (i = 0; i <= quant_testes; i++)
  {

    if (strcmp(nome, testes[i].Nome) == 0)
    {
      //aux recebe o indice do teste
      aux = i;

      break;
    }
  }

  char Valido[3] = "SIM";
  //verifica se a pessoa possui um cadastro(reultado foi encontrado).
  if (aux >= 0)
  {
    printf("Nome: %s\n", testes[aux].Nome);
    printf("CPF: %s\n", testes[aux].CPF);
    printf("Data de Nascimento: %d/%d/%d\n", testes[aux].nascimento.dia, testes[aux].nascimento.mes, testes[aux].nascimento.ano);
    printf("Idade: %d\n", ano_atual() - testes[aux].nascimento.ano);
    printf("Sexo: %c\n", testes[aux].Sexo);
    printf("Bairro: %s \n", testes[aux].Bairro);
    printf("COVID-19: %s \n", testes[aux].COVID19);
    printf("Valido: %s \n ", Valido[aux]);
  }
  else
  {
    printf("Nenhum teste encontrado!");
  }

  getchar();
}

// Cancela testes cadastrados
void cancelar(int n_teste, int quant_testes, Cadastro testes[])
{

  int i, aux;

  aux = -1;

  //busca o num com base na quantidade de testes.
  for (i = 0; i <= quant_testes; i++)
  {

    if (strcmp(n_teste, testes[i].n_teste) == 0)
    {
      //aux recebe o indice do teste
      aux = i;

      break;
    }
  }
  char opcao;
  char Valido[3] = "SIM";
  //verifica se a pessoa possui um cadastro(reultado foi encontrado).
  if (aux >= 0)
  {
    printf("Nome: %s\n", testes[aux].Nome);
    printf("CPF: %s\n", testes[aux].CPF);
    printf("Data de Nascimento: %d/%d/%d\n", testes[aux].nascimento.dia, testes[aux].nascimento.mes, testes[aux].nascimento.ano);
    printf("Idade: %d\n", ano_atual() - testes[aux].nascimento.ano);
    printf("Sexo: %c\n", testes[aux].Sexo);
    printf("Bairro: %s \n", testes[aux].Bairro);
    printf("COVID-19: %s \n", testes[aux].COVID19);
    printf("Valido: %s \n", Valido[aux]);

    printf("Deseja mesmo cancelar o teste 1 ? \n");
    printf("-> SUA OPCAO: [S/N]: \n");
    scanf("%c", &opcao);
    printf("Valido: %s \n", Valido[aux]);

    ((opcao == "S") ? (Valido[aux] = "NAO") : (Valido[aux] = "SIM"));
  }
  else
  {
    printf("Nenhum teste encontrado!");
  }

  getchar();
}

int main()
{
  int quant_testes;
  int opcao, n_testes;
  Cadastro testes[500];
  char nome[50];

  opcao = -1;
  quant_testes = 0;

  while (opcao != 0)
  {
    system("cls||clear");

    printf("\n---------------------------------------\n");
    printf("\n          TestesCovid-19               \n");
    printf("\n---------------------------------------\n");
    printf("\n           Menu de Opcoes              \n");
    printf("\n***************************************\n");
    printf("\nPOR FAVOR,ESCOLHA APENAS UMA DAS OPCOES ABAIXO.\n");
    printf("[ 1 ] - Cadastrar Novos Testes.\n");
    printf("[ 2 ] - Consultar Teste.\n");
    printf("[ 3 ] - Cancelar Teste.\n");
    printf("[ 4 ] - Salvar Informacoes em Arquivo.\n");
    printf("[ 5 ] - Visualizar Informacoes de Testes Realizados.\n");
    printf("[ 6 ] - Relatorio de Testes Realizados.\n");
    printf("[ 0 ] - Sair.\n");

    printf("\n-> DIGITE A SUA OPCAO: ");
    scanf("%d", &opcao);
    getchar();

    system("cls||clear");

    switch (opcao)
    {
    case 1:

      Cadastrar_testes(testes, &quant_testes);

      printf("\n----------------------------------------------------------------------\n");
      break;

    case 2:

      printf("Digite um nome para consulta: ");
      gets(nome);

      consulta(nome, quant_testes, testes);

      printf("\n----------------------------------------------------------------------\n");
      break;

    case 3:
      printf("Digite o numero do teste para cancelar: ");
      scanf("%d", &n_testes);

      cancelar(n_testes, 2, testes);

      printf("\n----------------------------------------------------------------------\n");
      break;

    case 4:

      printf("\n----------------------------------------------------------------------\n");
      break;

    case 5:

      printf("\n----------------------------------------------------------------------\n");
      break;

    case 6:

      printf("\n----------------------------------------------------------------------\n");
      break;
    }
  }
  return 0;
}