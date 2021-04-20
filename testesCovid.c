/*
                                        Universidade Federal de Viçosa - CRP
                                                13/05/2021

    -> SIN110 - Prof. Matheus Haddad e Prof. Leandro Furtado
    -> Trabalho Final - testesCovid
    -> Reposiório do projeto: https://github.com/VictorOliveira02/Gerenciador-TestesCovid

*Victor Alves de Oliveira - 6954 - T1
*Rafael Mantovani de Souza - 7319 - T1
*Bruno Marques da Silva - 6972 - T1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct sData{

  int dia;
  int mes;
  int ano;

}Data;

typedef struct sCadastro{

  char Nome[40];
  char CPF[8];
  int Idade;
  char Sexo;
  char Bairro[20];
  char COVID19[3];
  char Valido[3];
  Data nascimento; 

}Cadastro;

//Preenche os cadastros;
void Cadastrar_testes(Cadastro testes[], int *posicao){

  //pergunta ao usuario o numero de cadastros a ser preenchido.
  int num_testes,i;

  printf("Digite o numero de testes que serao cadastrados: \n");
  scanf("%d",&num_testes);
  getchar();

  //inicializa da posicao 0 caso não tenha nehum cadastro anteriormente,caso tenha,inicializa da posição seguinte.
  for(i=*posicao;i<(num_testes+*posicao);i++){
    
    printf("teste %d\n",i);

    printf("Digite o NOME: \n");
    gets(testes[i].nome);
    
    printf("Digite seu CPF: \n");
    scanf("%s", &testes[i].CPF);
    getchar();

    printf("Sobre a sua data de nascimento digite: \n");
    printf("O dia :\n");
    scanf("%d",&testes[i].nascimento.dia);
    getchar();

    printf("O mes: \n");
    scanf("%d",&testes[i].nascimento.mes);

    printf("o ano: \n");
    scanf("%d",&testes[i].nacimento.ano);

    printf("Digite sua idade: \n");
    scanf("%d", &testes[i].Idade);
    getchar();

    printf("Digite seu sexo: \n");
    gets(testes[i].Sexo);
    getchar();

    printf("Digite seu bairro: \n");
    gets(testes[i].Bairro);

    printf("Digite o reultado do seu teste: \n");
    gets(testes[i].COVID19);

    printf("Valido:");
    gets(testes[i].Valido);

  }

  *posicao+=num_testes;
  
}

//consulta o teste pelo nome cadastrado.
void consulta(char nome[], int quant_testes,Cadastro testes[]){

    int i,aux;

    aux=-1;

    //busca o nome com base na quantidade de testes.
    for(i=0;i<=quant_testes;i++){
      
      if(strcmp(nome,testes[i].nome)==0){

        //aux recebe o indice do teste
        aux=i;

        break;

      }
      
    }
    
    //verifica se a pessoa possui um cadastro(reultado foi encontrado).
    if(aux>=0){

      printf("Nome: %s\n",testes[aux].nome);
      printf("CPF: %s\n", testes[aux].CPF);
      printf("Data de Nascimento: %d/%d/%d\n",testes[aux].nascimento.dia,testes[aux].nascimento.mes,testes[aux].nascimento.ano);
      printf("Idade: %d\n", testes[aux].Idade);
      printf("Sexo: %c\n", testes[aux].Sexo);
      printf("Bairro: %s \n", testes[aux].Bairro);
      printf("COVID-19: %s \n", testes[aux].COVID19);
      printf("Valido: %s \n ",testes[aux].Valido);

    }else{
      printf("Nenhum teste encontrado!");
    }

    getchar();

  }

int main()
{
  int quant_testes;
  int opcao;
  Cadastro testes[500];
  char nome[50];
  
  opcao=-1;
  quant_testes=0;

  
  while (opcao != 0)
  {
    
    printf("\n---------------------------------------\n");
    printf("\n          TestesCovid-19               \n");
    printf("\n---------------------------------------\n");
    printf("\n           Menu de Opcoes              \n");
    printf("\n*************************************\n\n");
    printf("POR FAVOR,ESCOLHA APENAS UMA DAS OPCOES ABAIXO.\n");
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

      cadastrar_testes(testes,&quant_testes);
        
        printf("\n----------------------------------------------------------------------\n");

    break;

    case 2:
        
        printf("\n----------------------------------------------------------------------\n");
    break;

    case 3:
        
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