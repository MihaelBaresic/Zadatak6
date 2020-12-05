#define _CRT_SECURE_NO_WARNINGS
//LIFO dodavanje na poc. skidanje s poc.
//FIFO last in head next out

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _Queue* Position;
struct _Queue;
typedef struct _Queue {
	int El;
	Position next;
}Queue;

void Push(Position, Position);
Position createEl(int);
Position findLast(Position);
void printList(Position);
void Pop(Position);

int main() {
	int d, random;
	Queue head;
	head.next = NULL;
	Position K = NULL;
	Position Last = NULL;
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
			Last = findLast(&head);
			random = rand(10) % 101;
			K = createEl(random);
			Push(Last,K);
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
	Q = (Position)malloc(sizeof(Queue));
	if (!Q)
		printf("Memory not allocated!");
	Q->El = El;
	Q->next = NULL;
	return Q;
}

Position findLast(Position head) {
	Position Last;
	while (head->next != NULL)
		head = head->next;
	Last = head;
	return Last;
}

void Push(Position Last, Position K) {
	K->next = Last->next;
	Last->next = K;
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
