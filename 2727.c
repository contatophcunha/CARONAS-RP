#include "fila.h"
int main(){
  Fila  fila1, fila2;
	//inicializarFila(&fila2);
    Elemento novoAluno;
	setbuf(stdin,NULL);
	int opcao,t;					

		do{
			setbuf(stdin,NULL);
			printf("*** MENU *** \n");
			printf("1 - Inicializar fila \n");
			printf("2 - Entrar na fila \n");
			printf("3 - Sair da fila \n");
			printf("4 - Primeiro aluno na fila \n");
			printf("5-  Ultimo aluno da final \n");
			printf("6 - Imprimir fila de espera \n");
            printf("7-  Tamanho da fila\n");
			printf("8- Imprimir Recursivo \n");
            printf("9- Liberar Fila\n");
			
		
			
			scanf("%d", &opcao);
				switch(opcao){
					case 1:
						iniciarFila(&fila1);
                        iniciarFila(&fila2);
						printf("\nFila  INICIALIZADA COM SUCESSO\n");
						break;
					case 2:
						printf("Nome do aluno: \n");
                        setbuf(stdin,NULL);
						gets(novoAluno.nome);
						setbuf(stdin,NULL);
						printf("Curso Aluno: \n");
						setbuf(stdin,NULL);
						gets(novoAluno.curso);
						printf("Matricula do aluno: \n");
						setbuf(stdin,NULL);
						scanf("%d",&novoAluno.matricula);
					
					
						enfileirar(&fila1, novoAluno);
						printf("\n Voce entrou na fila !  \n");
						break;
					
		
					case 3 :
						desenfileirar(&fila1);
						printf("\n Voce saiu da fila \n");
						break; 
		
					case 4:
                          proximo(&fila1);
						//imprimirInicio(&fila1);
						break;
						
					case 5:
                        Ultimo(&fila1);
						//imprimirFinal(&fila1);
						break;
				
					
					case 6:
						imprimirFila(&fila1,&fila2);
						break;
					case 7:
						t=tamanhoFila(&fila1);
                        printf("\nTemos %d pessoas na fila\n",t);
						break;
						
					
					case 8:
                        backupFila(&fila1,&fila2);
                        imprimirRecursivo(&fila2);
						//liberarFila(&fila1);
						break;
					
					case 9:
                        liberarFila(&fila1);
                        return ;
						break;
					
					case 11:
						break;
                }
        }while(opcao != 0);

system("pause");
return 0;
}


