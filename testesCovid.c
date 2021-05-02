/*
                                      Universidade Federal de Vicosa - CRP
                                                  13/05/2021
    -> SIN110 - Prof. Matheus Haddad e Prof. Leandro Furtado
    -> Trabalho Final - testesCovid
    -> Repositorio do projeto: https://github.com/VictorOliveira02/Gerenciador-TestesCovid

*Victor Alves de Oliveira -  6954 - T1
*Rafael Mantovani de Souza - 7319 - T1
*Bruno Marques da Silva -    6972 - T1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct sData
{
  int dia;
  int mes;
  int ano;

} Data;

int idade_atual(int ano_nasc)
{
  struct tm *data_atual;
  time_t ano;
  time(&ano);
  data_atual = localtime(&ano);
  int year = data_atual->tm_year + 1900;
  return year - ano_nasc;
}

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
  char valido;

} Cadastro;

//Preenche os cadastros;
void Cadastrar_testes(Cadastro **testes, int *posicao)
{

  //pergunta ao usuario o numero de cadastros a ser preenchido.
  int num_testes, i;

  printf("Digite o numero de testes que serao cadastrados: ");
  scanf("%d", &num_testes);

  //chamar função  malloc aqui
  if (*testes == NULL)
  {
    *testes = (Cadastro *)malloc(sizeof(Cadastro) * num_testes);
  }
  else
  {
    *testes = (Cadastro *)realloc(*testes, sizeof(Cadastro) * num_testes);
  }

  if (*testes == NULL)
  {
    printf("Nao existe espaco na memoria! ");
    exit(1);
  }

  //inicializa da posicao 0 caso não tenha nehum cadastro anteriormente,caso tenha,inicializa da posição seguinte.
  for (i = *posicao; i < (num_testes + *posicao); i++)
  {

    printf("\nTeste %d\n", i + 1);
    //Passando numero do teste
    printf("\nDigite o nome: ");
    gets((*testes)[i].Nome);

    printf("Digite seu CPF: ");
    getchar();
    gets((*testes)[i].CPF);

    printf("Data de nascimento (D/M/A)");
    getchar();
    printf("\nDia: ");
    scanf("%d", &(*testes)[i].nascimento.dia);

    printf("Mes: ");
    scanf("%d", &(*testes)[i].nascimento.mes);
    getchar();

    printf("Ano: ");
    scanf("%d", &(*testes)[i].nascimento.ano);
    getchar();

    printf("Digite seu sexo [M/F]: ");
    scanf("%c", &(*testes)[i].Sexo);
    getchar();

    printf("Digite seu bairro: ");
    gets((*testes)[i].Bairro);

    printf("Digite o resultado do seu teste [P/N]: ");
    gets((*testes)[i].COVID19);

    strcpy((*testes)[i].valido, "S");
  }

  *posicao += num_testes;
}

//imprime cadastro atraves do txt
// void imprime_cad(Cadastro cadastro)
// {
//   FILE *pont_arq;
//   int i;

//   pont_arq = fopen("TesteCovid2.txt", "r");

//   if (pont_arq == NULL)

//   {

//     printf("ERRO NA  ABERTURA");
//     return 1;
//   }

//   for (i = *posicao; i < (num_testes + *posicao); i++)
//   {

//     fprintf("Nome: %s\n", testes[i].Nome);
//     fprintf("CPF: %s\n", testes[i].CPF);
//     fprintf("Data de Nascimento: %d/%d/%d\n", testes[i].nascimento.dia, testes[i].nascimento.mes, testes[i].nascimento.ano);
//     fprintf("Idade: %d anos\n", idade_atual(testes[i].nascimento.ano));
//     fprintf("Sexo: %c\n", testes[i].Sexo);
//     fprintf("Bairro: %s \n", testes[i].Bairro);
//     fprintf("COVID-19: %s \n", testes[i].COVID19);
//     fprintf("Valido: %s \n", testes[i].valido);
//   }

//   fclose(pont_arq);
// }

// ///////////////////////////////////MODIFICAÇÃO NO REGISTRO, POIS PRECISA SER GRAVADO////////////////////////////////

// FILE *pont_arq;
// int i;

// pont_arq = fopen("TesteCovid2.txt", "w");

// if (pont_arq == NULL)

// {

//   printf("ERRO NA  ABERTURA");
//   return 1;
// }

// for (i = *posicao; i < (num_testes + *posicao); i++)
// {

//   printf("\nTeste %d\n\n", i + 1);
//   //Passando numero do teste
//   printf("Digite o nome: ");
//   gets((*testes)[i].Nome);

//   printf("Digite seu CPF: ");
//   gets((*testes)[i].CPF);
//   getchar();

//   printf("Data de nascimento (D/M/A)");
//   printf("\nDia: ");
//   scanf("%d", &(*testes)[i].nascimento.dia);
//   getchar();

//   printf("Mes: ");
//   scanf("%d", &(*testes)[i].nascimento.mes);
//   getchar();

//   printf("Ano: ");
//   scanf("%d", &(*testes)[i].nascimento.ano);
//   getchar();

//   printf("Digite seu sexo [M/F]: ");
//   scanf("%c", &(*testes)[i].Sexo);
//   getchar();

//   printf("Digite seu bairro: ");
//   gets((*testes)[i].Bairro);

//   printf("Digite o resultado do seu teste [P/N]: ");
//   gets((*testes)[i].COVID19);

//   strcpy((*testes)[i].valido, "SIM");
// }

// *posicao += num_testes;
// }

// fclose(pont_arq);
// }

// Cancela testes cadastrados
void cancela_teste(Cadastro cadastros[], int num_teste)
{
  int indice;
  char opcao;

  indice = num_teste - 1;

  imprime_cad(cadastros[indice]);

  printf("\n\n");

  printf("Deseja realmente cancelar o teste %d ?[S/N]: ", num_teste);
  scanf("%c", &opcao);

  if (opcao == "S")
  {
    strcpy(cadastros[indice].valido, "N");
    printf("Cancelado com sucesso!!!");
  }
  getchar();
}

void salvar_txt(char nome_teste_txt[], int quant_testes, Cadastro testes[])
{
  //criando a varivel ponteiro para o arquivo
  FILE *arquivo;

  //abrindo o arquivo
  arquivo = fopen(nome_teste_txt, "a");

  //mensagem para o usuario
  if (arquivo == NULL)
  {
    printf("Erro ao abrir arquivo!");
  }
  else
  {
    printf("Arquivo %s criado com sucesso!", nome_teste_txt);
  }

  for (int cont = 0; cont < quant_testes; cont++)
  {
    if (testes[cont].valido == "S")
    {
      fprintf(arquivo, "TESTE Nº: %d", cont + 1);
      fprintf(arquivo, "NOME: %s", testes[cont].Nome);
      fprintf(arquivo, "CPF: %s", testes[cont].CPF);
      fprintf(arquivo, "Data de Nasc: %d/%d/%d", testes[cont].nascimento.dia, testes[cont].nascimento.mes, testes[cont].nascimento.ano);
      fprintf(arquivo, "SEXO: %c", testes[cont].Sexo);
      fprintf(arquivo, "BAIRRO: %s", testes[cont].Bairro);
      fprintf(arquivo, "COVID-19: %s", testes[cont].COVID19);
    }
  }

  fclose(arquivo);
  getchar();
}

int num_infectados(Cadastro cadastros[], int quant_testes)
{
  int i, infectados;

  infectados = 0;
  //conta a quantidade de infectados
  for (i = 0; i < quant_testes; i++)
  {

    if (strcmp(cadastros[i].COVID19, "P") == 0)
    {
      infectados++;
    }
  }

  return infectados;
}

int jovens_infect(Cadastro cadastros[], int quant_testes)
{
  int i, jovens;

  jovens = 0;

  for (i = 0; i < quant_testes; i++)
  {
    if ((idade_atual(cadastros[i].nascimento.ano) < 20) && (strcmp(cadastros[i].COVID19, "P") == 0))
    {
      jovens++;
    }
  }

  return jovens;
}

int adultos_infect(Cadastro cadastros[], int quant_testes)
{
  int i, adultos;

  adultos = 0;
  for (i = 0; i < quant_testes; i++)
  {
    if ((idade_atual(cadastros[i].nascimento.ano) < 60) && (strcmp(cadastros[i].COVID19, "P") == 0))
    {
      adultos++;
    }
  }

  return adultos;
}

int idosos_infect(Cadastro cadastros[], int quant_testes)
{
  int i, idosos;

  idosos = 0;
  for (i = 0; i < quant_testes; i++)
  {
    if ((idade_atual(cadastros[i].nascimento.ano) >= 60) && (strcmp(cadastros[i].COVID19, "P") == 0))
    {
      idosos++;
    }
  }

  return idosos;
}

float porcentagem(int total, int quant_element)
{
  float pct;

  pct = (quant_element * 100.0) / total;

  return pct;
}

void relatorio(Cadastro cadastros[], int quant_testes)
{
  float pct_jovens, pct_adultos, pct_idosos, pct_infectados, pct_naoinfectados;
  int jovens, adultos, idosos, nao_infectados, pessoa_infectada;

  printf("Total de pessoas cadastradas: %d\n", quant_testes);

  pessoa_infectada = num_infectados(cadastros, quant_testes);
  nao_infectados = quant_testes - pessoa_infectada;

  pct_infectados = porcentagem(quant_testes, pessoa_infectada);
  pct_naoinfectados = porcentagem(quant_testes, nao_infectados);

  jovens = jovens_infect(cadastros, quant_testes);
  adultos = adultos_infect(cadastros, quant_testes);
  idosos = idosos_infect(cadastros, quant_testes);

  pct_jovens = porcentagem(pessoa_infectada, jovens);
  pct_adultos = porcentagem(pessoa_infectada, adultos);
  pct_idosos = porcentagem(pessoa_infectada, idosos);

  printf("Pessoas no infectadas: %d (%.2f)\n", nao_infectados, pct_naoinfectados);
  printf("Pessoas infectadas: %d (%.2f)\n", pessoa_infectada, pct_infectados);
  printf("\tJovens infectados:%d (%.2f dos infectados)\n", jovens, pct_jovens);
  printf("\tAdultos infectados:%d (%.2f dos infectados)\n", adultos, pct_adultos);
  printf("\tIdosos infectados:%d (%.2f dos infectados)\n", idosos, pct_idosos);
}

int main()
{
  int i;
  int quant_testes;
  int opcao, num_do_teste;
  Cadastro *testes;
  char nome[50];
  char nome_teste_txt[50];

  testes = NULL;

  opcao = -1;
  quant_testes = 0;

  while (opcao != 0)
  {
    system("cls||clear");

    printf("\n---------------------------------------\n");
    printf("\n           TestesCovid-19               \n");
    printf("\n---------------------------------------\n");
    printf("\n           Menu de Opcoes              \n");
    printf("\n***************************************\n");
    printf("\nPOR FAVOR, ESCOLHA APENAS UMA DAS OPCOES ABAIXO.\n");
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

      Cadastrar_testes(&testes, &quant_testes);
      getchar();

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
      scanf("%d", &num_do_teste);
      getchar();

      cancela_teste(testes, num_do_teste);

      printf("\n----------------------------------------------------------------------\n");
      break;

    case 4:
      printf("Como deseja nomear o arquivo ?: ");
      scanf("%s", &nome_teste_txt);

      salvar_txt(nome_teste_txt, quant_testes, testes);

      getchar();
      printf("\n----------------------------------------------------------------------\n");
      break;

    case 5:
      for (i = 0; i < quant_testes; i++)
      {
        printf("\n----------------------------------------------------------------------\n");
        printf("                           Teste %d\n", i + 1);
        printf("\n----------------------------------------------------------------------\n");
        imprime_cad(testes[i]);
        printf("\n----------------------------------------------------------------------\n");
      }
      getchar();
      printf("\n----------------------------------------------------------------------\n");
      break;

    case 6:
      relatorio(testes, quant_testes);
      printf("\n----------------------------------------------------------------------\n");
      break;
    }
  }

  free(testes);
  return 0;
}
