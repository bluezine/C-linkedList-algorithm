#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *before;
	int data;
	struct Node *next;
};

struct Node *start;
struct Node *current;
struct Node *end;

void addList(int data) {
	printf("[Data Input] : %d\n", data);
	current = (struct Node *)malloc(sizeof(struct Node));
	current->before = NULL;
	current->next = NULL;
	current->data = data;
	if (start == NULL) {
		start = end = current;
	}
	else {
		end->next = current;
		current->before = end;
		end = current;
	}
}

void forwardPrint() {
	current = start;
	printf("[Forward Print Data] : ");
	while (1) {
		printf("%d ", current->data);
		if (current->next == NULL) {
			printf("\n");
			break;
		}
		current = current->next;
	}
}

void reversePrint() {
	current = end;
	printf("[Reverse Print Data] : ");
	while (1) {
		printf("%d ", current->data);
		if (current->before == NULL) {
			printf("\n");
			break;
		}
		current = current->before;
	}
}

void deleteList(int index) {
	printf("[Delete Index] : %d [Data : ", index);
	current = start;
	int i;
	for (i = 0;i < index;i++) {
		current = current->next;
	}
	printf("%d]\n", current->data);
	current->before->next = current->next;
	current->next->before = current->before;
}

int main(void) {
	addList(1);
	addList(2);
	addList(3);
	forwardPrint();
	reversePrint();
	addList(4);
	addList(5);
	forwardPrint();
	reversePrint();
	deleteList(1);
	forwardPrint();
	reversePrint();
}