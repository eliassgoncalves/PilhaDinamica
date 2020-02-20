/*
*
* Computer Science Section
* Faculdades Doctum de Caratinga
* Caratinga, MG, Brazil
* Feb. 20, 2020
* author: Elias Goncalves
* email: falarcomelias@gmail.com
* Licensed under the Apache License, Version 2.0
*
*/

#include "PilhaDinamica.h"

// Pilha
struct pilha_dinamica{
	NO *topo;
};


// Implementações das operações da pilha
Pilha *create( ){   // Criar pilha
	
	Pilha *pilha = ( Pilha* ) malloc( sizeof( Pilha ) );
	if( pilha != NULL ){
		//pilha->topo->dado = EMPTY;
		pilha->topo = NULL;
		printf( "Pilha criada com sucesso...\n" );
		return pilha;
	}

	printf( "Erro ao alocar memória...\n" );
	return NULL;
}

int top( Pilha *pilha ){
	printf( "Verificando topo da pilha...\n" );
	if( !is_empty( pilha ) )
		return pilha->topo->dado; // se pilha NÃO vazia retun é o dado
	
	return EMPTY; // se pilha vazia retun é -1
}


bool is_empty( Pilha *pilha ){  // Verificar se a pilha está vazia
	printf( "Verificando se a pilha está vazia...\n" );
	return ( pilha->topo == NULL );
}


bool push( Pilha *pilha, int item ){ // Empilhar item
	NO *novo = (NO*)malloc(sizeof(NO));
	novo->dado = item;
	novo->prox = NULL;
	pilha->topo = novo;
	printf( "Empilhando %d...\n", item );
	return true;
}


bool pop( Pilha *pilha ){  // Desempilhar item
	if( !is_empty( pilha ) ){

		
		NO *aux = pilha->topo;
		pilha->topo = pilha->topo->prox;
		
		printf( "Desempilhando %d...\n", pilha->topo->dado );
		free(aux);
		return true;
	}
	else
		printf( "Pilha vazia!\n" );

	return false;
}


bool pull( Pilha *pilha, int item ){ // Alterar o dado no topo da pilha
	if( !is_empty( pilha ) ){
		printf( "Alterando topo da pilha...\n" );
		pilha->topo->dado = item;
		return true;
	}
	return false;
}