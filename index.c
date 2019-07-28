/*
	Wallace Junio Silva
	Estudante de Sistema de Informação - 3º Período
	Estrutura de Dados - Lista Alocada dinamicamente
	Programa: CADASTRO DE NOTAS DE ALUNOS 
*/

//Bibliotecas linguagem C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


//Estrutura dados do aluno 
typedef struct aluno {
	char nome[30];
	int matricula;
	float n1,n2,n3;	
}tipo_dados;


//Estrutura de Elemento
typedef struct elemento {
	tipo_dados aluno_dados; 
	struct elemento* prox;	
}tipo_elemento;


//Ponteiro para inicio da lista
typedef struct elemento* Lista;


//ASSINATURA DE FUNÇOES 
Lista* cria_lista();
int inserir_lista_fim(Lista* list);
int exibir_lista(Lista* list);

//Funçao cria  lista
Lista* cria_lista() {
	
	Lista* list = (Lista*) malloc(sizeof(Lista));
	*list = NULL;
	
	if(list == NULL ){
		system("cls");
		printf("\nERRO ao criar lista!");
		getch();
		return 0;
	}

	return list;	
} 	



int inserir_lista_fim(Lista* list) {
	
	if(list == NULL) {
		system("cls");
		printf("\nLista Vazia! Crie a Lista primeiro");
		getch();
		return 0;
	}
	
	tipo_elemento* no = (tipo_elemento*) malloc(sizeof(tipo_elemento));
	
	if(no == NULL) {
		printf("\nERRO ao tentar inserir novo elemento.");
		getch();
		return 0;
	}
	
	system("cls");
	printf("\n------------------------");
	printf("\n  [ INSERIR ALUNO ]");
	printf("\n------------------------");
	printf("\nNome: ");
	gets(no->aluno_dados.nome);
	printf("\nMatricula: ");
	scanf("%d",&no->aluno_dados.matricula);
	fflush(stdin);
	printf("\nNota 1: ");
	scanf("%f",&no->aluno_dados.n1);
	fflush(stdin);
	printf("\nNota 2: ");
	scanf("%f",&no->aluno_dados.n2);
	fflush(stdin);
	printf("\nNota 3: ");
	scanf("%f",&no->aluno_dados.n3);
	fflush(stdin);
	
	no->prox = NULL; //nó em andamento aponta para NULL sendo o ultimo elemento
	
	if((*list) == NULL) {
		
		*list = no;
		return 1;
	}
	
	if((*list ) != NULL) {
		
		tipo_elemento* aux = *list;
		
		while(aux->prox != NULL) {
			aux = aux->prox;
		} 
		aux->prox = no;
		
	}
	return 1;
}




int exibir_lista(Lista* list) {
	
	if(list == NULL) {
		printf("\nLista não existe!");
		getch();
		return 0;
	}
	
	if(*list == NULL) {
		printf("\nLista vazia!");
		getch();
		return 0;
	}
	
	tipo_elemento* aux = *list;
	
	if(aux == NULL)
		return 0;
		system("cls");
		printf("\n---------------------");
		printf("\n [ LISTA DE ALUNO ]");
		printf("\n---------------------");
	 	
		
	while(aux != NULL) {
		printf("\nNome: %s",aux->aluno_dados.nome);
		printf("\nMatricula: %d",aux->aluno_dados.matricula);
		printf("\nNota 1 : %.2f",aux->aluno_dados.n1);
		printf("\nNota 2 : %.2f ",aux->aluno_dados.n2);
		printf("\nNota 3 : %.2f \n\n",aux->aluno_dados.n3);
		
		aux = aux->prox;
	}
	getch();
	return 1;
}


int  liberar_lista(Lista* list) {
	
	if(list == NULL)
		return 0;
		
	tipo_elemento* aux;
	
	
	while((*list) != NULL) {
		aux = *list;
		*list = (*list)->prox;
		free(aux);
	}
	
	free(list);
	
	printf("\nLista liberada com sucesso!");
	getch();
	return 1;
}




int main() {
	
	int op;   //variavel para interação do usuario com menu principal
	
	//Ponteiro para ponteiro - inicio lista
	Lista *inicio_lista;
	
	//cria lista
	inicio_lista = cria_lista();
	
	do{
		system("cls");
		printf("\n ---------------------------");
		printf("\n [ FACULDADE F.H.L.AUDE ]");
		printf("\n-----------------------------");
		printf("\n1-Incluir");
		printf("\n2-Lista");
		printf("\n3-Sair");
		printf("\n>>Opcao: ");
		scanf("%d",&op);
		fflush(stdin);
		
		if(op == 1) {
						
			inserir_lista_fim(inicio_lista);
		}	
		
		
		if(op == 2) {
					
			exibir_lista(inicio_lista);	
		}
		
		if(op == 3) {
			
			liberar_lista(inicio_lista);
			
		}	
			
	}while(op != 3);
	
	
	
	
}
