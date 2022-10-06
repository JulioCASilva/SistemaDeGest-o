#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct aluno{
  char nome[50];
  float nota1;
  float nota2;
};

struct classroom{
  struct aluno *pAluno;
  int length;
};

struct classroom Day, *pDay = &Day;

void incluir(struct classroom *sala){
  struct aluno *nAluno = sala->pAluno + sala->length;
  char nome[50];
  float nota1, nota2;

  printf("Digite o primeiro nome do aluno: \n");
  
  scanf("%s", nome);

  printf("Digite sua primeira nota: \n");
  scanf("%f", &nota1);
  
  printf("Digite sua segunda nota: \n");
  scanf("%f", &nota2);

  printf("Incluindo novo aluno...\n");
  if(sala != NULL){
    if(sala->length == sizeof(*(sala->pAluno))/60){
      sala->pAluno = (struct aluno*)realloc(sala->pAluno, 10);
    }

    *nAluno = (struct aluno){
      .nota1 = nota1,
      .nota2 = nota2
    };
    
    strncpy(nAluno->nome, nome, 50);

    sala->length++;
  }

  printf("Nome do aluno: %s, Primeira nota: %.2f Segunda nota: %.2f adicionado.\n\n", nAluno->nome, nAluno->nota1, nAluno->nota2);
}

void excluir(struct classroom *sala){
  int index = 0;
  a: printf("Qual aluno deseja excluir(Digite um numero): (Total: %d)\n", sala->length );
  scanf("%i", &index);

  if(sala != NULL){
    if(index <= sala->length - 0 && index >= 0){
     
      for (int i = index; i < sala->length - 1; i++)
        *(sala->pAluno + index) = (struct aluno)*(sala->pAluno + index + 1);
      
      sala->length--;
      
      
    }else{
      printf("Número inválido, porfavor digite novamente:\n\n");
      goto a;
    }
  }
}

void pesquisa(struct classroom *sala){
  struct aluno *pAluno = NULL;
  char nome[50];

  printf("Digite o nome do aluno para saber as informações: \n");
  scanf("%s", nome);

  if(sala != NULL)
    for (int i = 0; i < sala->length; i++)
      if(strncmp((sala->pAluno + i)->nome, nome, 50) == 0){
        pAluno = sala->pAluno + i;
        break;
      }
  
  if(pAluno != NULL)
    printf("O aluno selecionado, %s, porta notas %.2f e %.2f\n\n", pAluno->nome, pAluno->nota1,pAluno->nota2);
  else 
    printf("Aluno não existente\n\n");
}

void relatorio(struct classroom *sala){
  if(sala != NULL){
    printf("Nome | Nota 1 | Nota 2 | Média | Situação\n");

    for (int i = 0; i < sala->length; i++){ 
      struct aluno *pAluno = sala->pAluno + i;
      float media = (pAluno->nota1 + pAluno->nota2)/2.0f;

      printf("%s | %.2f | %.2f | %.2f | %s\n",pAluno->nome,pAluno->nota1,pAluno->nota2,media,media >= 6.0f ? "Aprovado" : 
      media >= 4.0f ? "Em recuperação" : "Reprovado" );}
    printf("\n");
  }
}
void sair(struct classroom *sala){
  free(sala->pAluno);
  
  printf("Saiu\n");
}