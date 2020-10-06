#ifndef QUACK_H
#define QUACK_H

struct Node_t{

	int val;
	struct Node_t *next;
	struct Node_t *prev;
};

typedef struct{

	int size;
	struct Node_t *start;
	struct Node_t *end;
}Quack_t;


Quack_t *buildQuack();
int addQuackNode(Quack_t *quack, int val);
int searchVal(Quack_t *quack, int val);
int duckduckGrayduck(Quack_t *quack);		// This is where the magic happens
void printQuack(Quack_t *quack);
#endif
