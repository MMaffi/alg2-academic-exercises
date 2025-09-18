/*
  Nome: Mateus Maffi
	Data: 17/09/2025
  
	Programas com operações para exemplificar operações 
	em listas simplesmente encadeadas 

*/

#include <stdio.h>
#include <stdlib.h>

/* Definição de tipo */
typedef struct _cel{ 
	int num;
	struct _cel *prox;
}cel;

/* Funções */
void insereFim(cel **L, int x);
void imprimeLista(cel *L);
void liberaLista(cel **L);
void insereFim(cel **L, int x);


/* Função Main */
int main() {
	/* Declaração das variáveis */

	cel *L = NULL; /* Cria uma lista vazia*/

	/* Insere os elementos do exemplo */
	insereFim(&L, 10);
	insereFim(&L, 25);
	insereFim(&L, 30);
	insereFim(&L, 40);
	insereFim(&L, 50);
	
	/*printf("Lista original: ");*/
	imprimeLista(L);

	/* Chama a função para NOVA */
	removeNesimoelemento(&L, 1);
	
	printf("\nLista após função: ");
	imprimeLista(L);

	/* Libera a memória da lista */
	liberaLista(&L);

	return 0;
}

void insereFim(cel **L, int x){
	cel *p, *novo;

	novo = (cel*) malloc(sizeof(cel));
	if(novo == NULL){
		printf("\nErro ao alocar novo elemento na lista.");
		return;
	}
	novo->num = x;
	novo->prox = NULL;
	
	if(*L == NULL){
		*L = novo;
	}
	else{
		p = *L;
		while(p->prox != NULL){
			p = p->prox;
		}
		p->prox = novo;
	}
	printf("\n MEM:%p (num:%d - prox: %p) inserido na lista.",novo, novo->num, novo->prox);
}
void imprimeLista(cel *L){
	cel *p;

	printf("\nElementos da lista:");
	
	for(p = L; p!=NULL; p = p->prox){
		printf("\n MEM:%p (num:%d - prox: %p)", p, p->num, p->prox);
	}
	printf("\n");
}
void liberaLista(cel **L){
	cel *p;

	while(*L!=NULL){
		p = *L;
		(*L) = (*L)->prox;
		printf("\n MEM:%p (num:%d - prox: %p) liberado",p, p->num, p->prox);
		free(p);
	}
	printf("\n Lista Liberada.");
}

void removeNesimoelemento(cel **L, int n) {
	/* Pare remover o n-ésimo elemento da lista */
	cel *patual, *panterior;
	int count = 0;

	patual = *L;
	while (patual != NULL) {
		count++;
		if (count == n){
			if (L != NULL && n == 1) {
				*L = patual->prox;
			} else {
				panterior->prox = patual->prox;
			}
			printf("%d foi removido.\n", patual->num);
			free(patual);
			patual = NULL;
		} else {	
			panterior = patual;
			patual = patual->prox;
		}	
	}
	
}