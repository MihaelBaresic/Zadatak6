#define _CRT_SECURE_NO_WARNINGS
//LIFO dodavanje na poc. skidanje s poc.
//FIFO last in head next out

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _Stack* Position;
struct _Stack;
typedef struct _Stack {
	int El;
	Position next;
}Stack;

void Push(Position, Position);
Position createEl(int);
void printList(Position);
void Pop(Position);

int main() {
	int d, random;
	Stack head;
	head.next = NULL;
	Position K = NULL;
	srand(time(NULL));

	while (1)
	{
		printf("\n\tMENU:\n");
		printf("\t1-PUSH\n");
		printf("\t2-POP\n");
		printf("\t0-END \n\tEnter number:\t");
		scanf("%d", &d);
		switch (d)
		{
		case 1:
			random = 10 + rand() % 91;
			K = createEl(random);
			Push(&head,K);
			printList(&head);
			puts("");
			break;
		case 2:
			Pop(&head);
			printList(&head);
			puts("");
			break;
		case 0:
			printList(&head);
			return 0;
			break;
		default:
			puts("Input error!!");
		}
	}
	return 0;
}

Position createEl(int El) {
	Position Q;
	Q = (Position)malloc(sizeof(Stack));
	if (!Q)
		printf("Memory not allocated!");
	Q->El = El;
	Q->next = NULL;
	return Q;
}

void Push(Position head, Position K) {
	K->next = head->next;
	head->next = K;
}

void Pop(Position head) {
	Position temp;
	temp = head->next;
	head->next = temp->next;
	free(temp);
}


void printList(Position head) {
	if (NULL == head->next)
		printf(" Linked list is emtpy!");

	head = head->next;
	while (head != NULL) {
		printf("\t\n%d", head->El);
		head = head->next;
	}

	puts("\n");
}
