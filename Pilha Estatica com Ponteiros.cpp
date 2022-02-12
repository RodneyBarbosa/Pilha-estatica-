#include<stdio.h>

#define TAMANHO_MAXIMO 10

typedef struct {
  int valor;
} DOCUMENTO;

typedef struct {
	DOCUMENTO elementos[TAMANHO_MAXIMO];
	DOCUMENTO* topo;
  DOCUMENTO* primeiroElem;
  int length;
} PILHA;

void inicializarPilha(PILHA* pilha);
void limpaPilha(PILHA* pilha);
void imprimirPilha(PILHA* pilha);
int push(PILHA* pilha, DOCUMENTO valor);
int pop(PILHA* pilha);
int length(PILHA* pilha);

int main () {
	PILHA minhaPilha;

	inicializarPilha(&minhaPilha);
	
  DOCUMENTO doc1;
  doc1.valor = 2;
  DOCUMENTO doc2;
  doc2.valor = 4;
  DOCUMENTO doc3;
  doc3.valor = 6;

	push(&minhaPilha, doc1);
	push(&minhaPilha, doc2);
	push(&minhaPilha, doc3);

	pop(&minhaPilha);
    pop(&minhaPilha);	
	
	imprimirPilha(&minhaPilha);
	
}

int pop(PILHA* pilha) {
	if(length(pilha) == 0) return 0;

  if (pilha->topo == &pilha->elementos[0]) pilha->topo = NULL;
  else pilha->topo -= 1;

  pilha->length--;

  return 1;
}

int push(PILHA* pilha, DOCUMENTO valor) {
	if(length(pilha) >= TAMANHO_MAXIMO) return 0;

  if (pilha->topo == NULL) pilha->topo = pilha->primeiroElem;
  else pilha->topo += 1;

	*pilha->topo = valor;

	pilha->length++;

	return 1;
}

void inicializarPilha(PILHA* pilha) {
	pilha->topo = NULL;
  pilha->length = 0;
  pilha->primeiroElem = &pilha->elementos[0];
}

void limpaPilha(PILHA* pilha) {
  pilha->length = 0;
	pilha->topo = NULL;
}

int length(PILHA* pilha) {
	return pilha->length;
}

void imprimirPilha(PILHA* pilha) {
	printf("PILHA :)\n");

	for(int i = (length(pilha) - 1); i >= 0; i--)
		printf("|_%d_|\n", pilha->elementos[i].valor);
		
	printf("\n\n");
}
