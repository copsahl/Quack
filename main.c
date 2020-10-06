#include "quack.h"
#include <stdio.h>
#include <stdlib.h>

char *fill = "Filling Quack!";
char *search = "Searching Quack!";
char *valF = "Value Found!";
char *valNF = "Value Not Found!";
char *prQuack = "Printing the Quack!";
char *popQuack = "Popping from the Quack!";

int main(void){

	Quack_t *q;
	int i;

	// Creating the Quack!
	q = buildQuack();

	// Adding 100 pseudo-random numbers to the Quack
	printStatement(fill);
	for(i = 0; i < 100; i++){
		addQuackNode(q, i * 45 % 6 +12 / 5 * 4 + i);
	}
	
	// Searching the Quack
	printStatement(search);
	if(searchVal(q, 12) == 1){
		printStatement(valF);
	}

	if(searchVal(q, 100000) == 0){
		printStatement(valNF);
	}

	// Printing the Quack
	printStatement(prQuack);
	printQuack(q);

	// Popping from the Quack
	printf("\n\nPopping from the Quack!\n\n");
	for(i = 0; i < 15; i++){
		printf("%d\n", duckduckGrayduck(q));
	}
	
	// Printing the new Quack
	printStatement(prQuack);
	printQuack(q);

	return 0;
}
