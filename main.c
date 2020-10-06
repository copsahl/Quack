#include "quack.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){

	Quack_t *q;
	int i;

	// Creating the Quack!
	q = buildQuack();

	// Adding 100 pseudo-random numbers to the Quack
	printf("Filling Quack!\n\n");
	for(i = 0; i < 100; i++){
		addQuackNode(q, i * 45 % 6 +12 / 5 * 4 + i);
	}
	
	// Searching the Quack
	printf("\n\nSearching Quack!\n\n");
	if(searchVal(q, 12) == 1){
		printf("Value Found!\n");
	}

	if(searchVal(q, 100000) == 0){
		printf("Value Not Found!\n");
	}

	// Printing the Quack
	printf("\n\nPrinting the Quack!\n\n");
	printQuack(q);

	// Popping from the Quack
	printf("\n\nPopping from the Quack!\n\n");
	for(i = 0; i < 15; i++){
		printf("%d\n", duckduckGrayduck(q, 0));
	}
	
	// Printing the new Quack
	printf("\n\nPrinting Quack!\n\n");
	printQuack(q);

	return 0;
}
