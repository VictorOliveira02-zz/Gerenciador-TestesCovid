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
#include <conio.h>

//struct pra data
typedef struct sData
{
  int dia;
  int mes;
  int ano;

} Data;

//calcula a idade atual
int idade_atual(int ano_nasc)
{
  struct tm *data_atual;
  time_t ano;
  time(&ano);
  data_atual = localtime(&ano);
  int year = data_atual->tm_year + 1900;
  return year - ano_nasc;
}

//strcut para os cadastros
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
  char valido[2];

} Cadastro;

//Preenche os cadastros;
void Cadastrar_testes(Cadastro **testes, int *posicao)
{

  int num_testes, i, tam;

  //pergunta ao usuario o numero de cadastros a ser preenchido.
  printf("Digite o numero de testes que serao cadastrados: ");
  scanf("%d", &num_testes);
  getchar();

  //tamanho inicializa da posicao 0 caso n�o tenha nehum cadastro anteriormente,caso tenha,inicializa da posi��o seguinte.
  tam = *posicao + num_testes;

  //Aloca dinamicamente os testes cadastrados
  if (*testes == NULL)
  {
    *testes = (Cadastro *)malloc(sizeof(Cadastro) * tam);
  }
  else
  {
    *testes = (Cadastro *)realloc(*testes, sizeof(Cadastro) * tam);
  }

  if (*testes == NULL)
  {
    printf("Nao existe espaco na memoria! ");
    exit(1);
  }

  //inicializa da posicao 0 caso n�o tenha nehum cadastro anteriormente,caso tenha,inicializa da posi��o seguinte.
  for (i = *posicao; i < tam; i++)
  {

    printf("\nTeste %d\n", i + 1);
    //Passando numero do teste
    printf("\nDigite o nome: ");
    gets((*testes)[i].Nome);

    printf("Digite seu CPF: ");
    gets((*testes)[i].CPF);

    printf("Data de nascimento (D/M/A)");

    printf("\nDia: ");
    scanf("%d", &(*testes)[i].nascimento.dia);
    getchar();

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

//imprime cadatros
void imprime_cad(Cadastro cadastro)
{
  printf("Nome: %s\n", cadastro.Nome);
  printf("CPF: %s\n", cadastro.CPF);
  printf("Data de Nascimento: %d/%d/%d\n", cadastro.nascimento.dia, cadastro.nascimento.mes, cadastro.nascimento.ano);
  printf("Idade: %d anos\n", idade_atual(cadastro.nascimento.ano));
  printf("Sexo: %c\n", cadastro.Sexo);
  printf("Bairro: %s \n", cadastro.Bairro);
  printf("COVID-19: %s \n", cadastro.COVID19);
  printf("Valido: %s \n", cadastro.valido);
  getchar();
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

  //verifica se a pessoa possui um cadastro(reultado foi encontrado).
  if (aux >= 0)
  {
    printf("\nNome: %s\n", testes[aux].Nome);
    printf("CPF: %s\n", testes[aux].CPF);
    printf("Data de Nascimento: %d/%d/%d\n", testes[aux].nascimento.dia, testes[aux].nascimento.mes, testes[aux].nascimento.ano);
    printf("Idade: %d\n", idade_atual(testes[aux].nascimento.ano));
    printf("Sexo: %c\n", testes[aux].Sexo);
    printf("Bairro: %s \n", testes[aux].Bairro);
    printf("COVID-19: %s \n", testes[aux].COVID19);
    printf("Valido: %s \n ", testes[aux].valido);
  }
  else
  {
    printf("Nenhum teste encontrado!");
  }

  printf("\nPressione enter para continuar.");
  printf("\n----------------------------------------------------------------------\n");
  getchar();
}

//imprime cadastro atraves do txt
void imprime_cad_txt(char nome_teste_txt[])
{
  FILE *arquivo;

  char linha[100];

  // Abre um arquivo TEXTO para LEITURA
  arquivo = fopen(nome_teste_txt, "r");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir arquivo!");
  }

  while (fgets(linha, 100, arquivo) != NULL)
  {
    printf("%s", linha);
  }
  getch();
  fclose(arquivo);
}

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

  //Caso a escolha seja sim,a fun�ao strcpy copia 'N' para "Valido".
  if (opcao == 'S')
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
  strcat(nome_teste_txt, ".txt");
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
    fprintf(arquivo, "\n----------------------------------------------------------------------\n");
    fprintf(arquivo, "TESTE : %d\n", cont + 1);
    fprintf(arquivo, "NOME: %s\n", testes[cont].Nome);
    fprintf(arquivo, "CPF: %s\n", testes[cont].CPF);
    fprintf(arquivo, "Data de Nasc: %d/%d/%d\n", testes[cont].nascimento.dia, testes[cont].nascimento.mes, testes[cont].nascimento.ano);
    fprintf(arquivo, "SEXO: %c\n", testes[cont].Sexo);
    fprintf(arquivo, "BAIRRO: %s\n", testes[cont].Bairro);
    fprintf(arquivo, "COVID-19: %s\n", testes[cont].COVID19);
    fprintf(arquivo, "\n----------------------------------------------------------------------\n");
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

//Conta a quantidade de jovens infectados.
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

//Conta a quantidade de adultos infectados.
int adultos_infect(Cadastro cadastros[], int quant_testes)
{
  int i, adultos;

  adultos = 0;
  for (i = 0; i < quant_testes; i++)
  {
    if ((idade_atual(cadastros[i].nascimento.ano) >= 20) && ((idade_atual(cadastros[i].nascimento.ano) < 60)) && (strcmp(cadastros[i].COVID19, "P") == 0))
    {
      adultos++;
    }
  }

  return adultos;
}

//Conta a quantidade de idosos infectados.
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

//Funcao basica pra calcular porcentagem.
float porcentagem(int total, int quant_element)
{
  float pct;

  pct = (quant_element * 100.0) / total;

  return pct;
}

//Funcao responavel por criar os relatorios
void relatorio(Cadastro cadastros[], int quant_testes)
{
  float pct_jovens, pct_adultos, pct_idosos, pct_infectados, pct_naoinfectados;
  int jovens, adultos, idosos, nao_infectados, pessoa_infectada;

  printf("Total de pessoas cadastradas: %d\n", quant_testes);

  //Total de pessoas infectadas
  pessoa_infectada = num_infectados(cadastros, quant_testes);

  //Total de pessoas nao infectadas
  nao_infectados = quant_testes - pessoa_infectada;

  //Porcentagem de infectados
  pct_infectados = porcentagem(quant_testes, pessoa_infectada);
  pct_naoinfectados = porcentagem(quant_testes, nao_infectados);

  //Quantidade de jovens infectados
  jovens = jovens_infect(cadastros, quant_testes);

  //Quantidade de adultos infectados
  adultos = adultos_infect(cadastros, quant_testes);

  //Quantidade de idosos infectados
  idosos = idosos_infect(cadastros, quant_testes);

  //porcentagem de jovens infectados
  pct_jovens = porcentagem(pessoa_infectada, jovens);

  //porcentagem de adultos infectados
  pct_adultos = porcentagem(pessoa_infectada, adultos);

  //porcentagem de jidosos infectados
  pct_idosos = porcentagem(pessoa_infectada, idosos);

  printf("Pessoas no infectadas: %d (%.2f%%)\n", nao_infectados, pct_naoinfectados);
  printf("Pessoas infectadas: %d (%.2f%%)\n", pessoa_infectada, pct_infectados);
  printf("\tJovens infectados:%d (%.2f%% dos infectados)\n", jovens, pct_jovens);
  printf("\tAdultos infectados:%d (%.2f%% dos infectados)\n", adultos, pct_adultos);
  printf("\tIdosos infectados:%d (%.2f%% dos infectados)\n", idosos, pct_idosos);
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
      printf("\nPressione enter para continuar.");
      printf("\n----------------------------------------------------------------------\n");

      getchar();
      break;

    case 2:
      printf("Digite um nome para consulta: ");
      gets(nome);

      consulta(nome, quant_testes, testes);
      break;

    case 3:
      printf("Digite o numero do teste para cancelar: ");
      scanf("%d", &num_do_teste);
      printf("\nPressione enter para continuar.");

      printf("\n----------------------------------------------------------------------\n");

      getchar();

      cancela_teste(testes, num_do_teste);
      break;

    case 4:
      printf("Como deseja nomear o arquivo ?: ");
      scanf("%s", &nome_teste_txt);

      salvar_txt(nome_teste_txt, quant_testes, testes);
      printf("\nPressione enter para continuar.");
      printf("\n----------------------------------------------------------------------\n");
      getchar();
      break;

    case 5:
      imprime_cad_txt(nome_teste_txt);
      printf("\nPressione enter para continuar.");
      printf("\n----------------------------------------------------------------------\n");
      getchar();
      break;

    case 6:
      relatorio(testes, quant_testes);
      printf("\nPressione enter para continuar.");
      printf("\n----------------------------------------------------------------------\n");
      getchar();
      break;
    }
  }

  free(testes);
  return 0;
}
