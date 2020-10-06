#include "quack.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

Quack_t *buildQuack(){

	Quack_t *tmp = malloc(sizeof(Quack_t));
	if(tmp == NULL){
		return NULL;
	}

	tmp->size = 0;
	tmp->start = NULL;
	tmp->end = NULL;
	srand(time(NULL));
	return tmp;
}

int addQuackNode(Quack_t *quack, int val){

	struct Node_t *tmp = malloc(sizeof(struct Node_t));
	struct Node_t *i;

	if(tmp == NULL){
		return -1;
	}

	if(quack->start == NULL){
		tmp->val = val;
		tmp->next = NULL;
		tmp->prev = NULL;
		quack->start = tmp;
	}else{
		for(i = quack->start; i->next != NULL; i = i->next){
			continue;
		}
		tmp->val = val;
		tmp->next = NULL;
		tmp->prev = i;
		i->next = tmp;
	}
	quack->end = tmp;
	quack->size++;
	return 0;
}

int searchVal(Quack_t *quack, int val){
	struct Node_t *i;
	if(quack->size < 1){
		return -1;
	}

	for(i = quack->start; i != NULL; i=i->next){
		if(i->val == val){
			return 1;
		}
	}

	return 0;
}

int duckduckGrayduck(Quack_t *quack){


	int r;
	int num;
	struct Node_t *tmp;

	r = rand();

	if(r % 3 == 0){
		// Queue
		num = quack->start->val;
		tmp = quack->start;
		quack->start = tmp->next;
		free(tmp);
		printf("Quack!");
		return num;
	}else if(r % 3 == 1){
		// Stack
		tmp = quack->end->prev;
		num = quack->end->val;
		free(quack->end);
		quack->end = tmp;
		quack->end->next = NULL;
		printf("quack!");
		return num;
	}else if(r % 3 == 2){
		// Gray Duck - Returns -9999 and does nothing because it hates you.
		printf("qUAcK?");
		return rand();
	}

}

void printQuack(Quack_t *quack){
	struct Node_t *i;
	printf("<^)\n(3)\n \"\n");
	for(i = quack->start; i != NULL; i = i->next){
		printf("%d  ", i->val);
	}
	printf("\n");
}

