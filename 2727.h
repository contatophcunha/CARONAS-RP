#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct agenda {
	char nome[30];
	int matricula;
	char curso[16];
}Elemento;

typedef struct celulA{
	Elemento info;
	struct celulA *prox;
}Celula;

typedef struct filA{
	Celula *inicio;
	Celula *fim;
}Fila;

//INICIAR FILA
void iniciarFila(Fila *fila){
	fila->inicio= NULL;
	fila->fim=NULL;
}

//OP�AO 1 DO MENU
//VERIFICAR SE ESTA VAZIA
int filaVazia(Fila *fila){
	if (fila->inicio==NULL) {
		return 1;
	}
	
	return 0;
}

//CRIAR CELULA
Celula *criarCelula (){
	Celula *nova = (Celula *) malloc (sizeof(Celula));
	nova->prox = NULL;
	
	return nova;
}

//CRIAR UM ELEMENTO
Elemento criarElemento(char nome[], char curso[], int matricula) {
	Elemento elemento;
	strcpy(elemento.nome, nome);
	strcpy(elemento.curso, curso);
	elemento.matricula=matricula;
	
	return elemento;
}

//COMPARAR ELEMENTO
int compararElemento (Elemento e1,Elemento e2){
	return strcmp(e1.nome,e2.nome);
}


//OPCAO 2 DO MENU
//ENFILEIRA NA FILA
int enfileirar (Fila *fila,Elemento novo){
	Celula *novaCelula;
	
	novaCelula = criarCelula();
	
	if (novaCelula == NULL ){
		printf("erro - memoria cheia.\n");
		return 0;
	}
	
	(*novaCelula).info = novo;
	
	 if (filaVazia(fila)) {
	 	 fila->fim= novaCelula;
	 	 fila->inicio= novaCelula;
	 	return 1;
	 	
	 }
	 
	fila->fim->prox=novaCelula;
	fila->fim=novaCelula;
	 return 1;
}
//OPCAO 3
//DESENFILA DA FILA
Elemento desenfileirar(Fila *fila) {
	Celula *removida;
	Elemento removido = criarElemento (" "," ", 0);
	
	if (filaVazia(fila)){
		printf("erro- lista vazia.");
		return removido;
	}
	
	removida = fila->inicio;
	removido = removida-> info;
	fila->inicio =  fila->inicio-> prox;
	free(removida);
	

	return removido;
}




//IMPRIMIR ELEMENTO, USADO NO MENU PARA IMPRIMIR A LISTA TODA.
void imprimirElemento(Elemento elemento){
	printf("\nNome: %s\n nCurso: %s\n Matricula: %d\n",elemento.nome,elemento.curso,elemento.matricula);
} 

//OP�AO 4
//SABER PROXIMO DA FILA
int proximo(Fila *fila){
	if (filaVazia(fila)){
		
		printf("erro - filha vazia\n");
	
		return 0;
	}
	
	printf("Primeiro da fila: \n");
	imprimirElemento(fila->inicio->info);

	return 0;
}
int Ultimo(Fila *fila){
	if (filaVazia(fila)){
		
		printf("erro - filha vazia\n");
	
		return 0;
	}
	
	printf("Ultimo da fila: \n");
	imprimirElemento(fila->fim->info);

	return 0;
}
int tamanhoFila(Fila * fila){
	Celula *  aux=fila->inicio;
	int tamanho=0;
	if(filaVazia(fila)){
		return tamanho;
	}else{

		while(aux!=NULL){
			
			aux=aux->prox;
			tamanho++;
		}
		return tamanho;
	}

}
void liberarFila(Fila *fila){
	while(fila->inicio!=NULL){
		desenfileirar(fila);
	}
	printf("Fila liberada");
}
//OPCAO 5 DO MENU
//IMPRIMIR TODOS OS VALORES DA FILA
void imprimirFila(Fila *fila, Fila * faux){

		
		
		Elemento Aux=criarElemento("","",0);
		
		//faux->inicio=NULL;
		
		//puts("aqui");
		if(filaVazia(fila)) {
			
			printf("fila vazia\n");
			return ;
		}
		
		else{
			//puts("vish");
			printf(": FILA:\n");
			while(fila->inicio != NULL){
				Aux= desenfileirar(fila);
				imprimirElemento(Aux);
				enfileirar(faux,Aux);
			}
			while(faux->inicio != NULL){
				Aux=desenfileirar(faux);
				enfileirar(fila,Aux);
			}
		
		
		}
	}
void backupFila(Fila * fila, Fila *bck){
	Celula *  aux=fila->inicio;
	while(aux!=NULL){
		enfileirar(bck,aux->info);
		aux=aux->prox;

	}


}
void imprimirRecursivo(Fila * fila){
	Celula *aux;
	if(fila->inicio==NULL){
		puts("\nFIm da Fila\n");
		return ;
	}else{
		imprimirElemento(fila->inicio->info);
		fila->inicio=fila->inicio->prox;
		return imprimirRecursivo(fila);
	}

}

