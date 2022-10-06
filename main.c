// Grupo: Gabriella Freitas - 202202528803, João Pedro Rodrigues Cavalcanti - 202212114424, 
//Júlio Cesar Arruda - 202203611763 

#include <stdio.h>
#include "sistema.h"
#include <stdlib.h>

void menu();

int main() {
  menu();

  return 0;
}

void menu(){
  int opcao;

  (*pDay) = (struct classroom){
    .pAluno = (struct aluno*)malloc(10 * sizeof(struct aluno)),
    .length = 0
  };
//Inicio do menu
  a: printf("........Menu........\n\n");
  printf("1: incluir aluno\n");
  printf("2: excluir aluno\n");
  printf("3: pesquisar aluno\n");
  printf("4: Relatório de notas\n");
  printf("5: Sair\n\n");

  printf("Escolha uma opção: \n");
  scanf("%i", &opcao);
    
  switch(opcao){
    case 1:
      incluir(pDay);
      goto a;
    break;
    
    case 2:
      excluir(pDay);
      goto a;
    break;
    
    case 3:
      pesquisa(pDay);
      goto a;

    break;
    case 4:
      relatorio(pDay);
      goto a;
    break;
    
    case 5:
      sair(pDay);
    break;
    
    default:
      printf("Porfavor, escolha novamente: ");
      goto a;
    break;
  }
}