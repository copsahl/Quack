#include "quack.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){

	Quack_t *q;
	int i;

	q = buildQuack();
	for(i = 0; i < 100; i++){
		addQuackNode(q, i * 45 % 6 +12 / 5 * 4 + i);
	}
	if(searchVal(q, 12) == 1){
		printf("Value Found!\n");
	}

	if(searchVal(q, 14) == 0){
		printf("Value Not Found!\n");
	}

	printQuack(q);
	printf("3rd to last: %d\n", q->end->prev->prev->val);
	printf("2nd to last: %d\n", q->end->prev->val);
	printf("Last: %d\n", q->end->val);
	for(i = 0; i < 15; i++){
		printf("%d\n", duckduckGrayduck(q, 0));
	}
	
	printQuack(q);

	return 0;
}
