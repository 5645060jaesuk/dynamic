#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 10


typedef int element;


typedef struct {
	element* data;
	int capacity;
	int top;
} StackType;

void init_stack(StackType* p)
{
	p->top = -1;
	p->capacity = 1;
	p->data = (element*)malloc(p->capacity * sizeof(element));
}

int is_empty(StackType* p)
{
	return (p->top == -1);
}


int is_full(StackType* p)
{
	return (p->top == (p->capacity - 1));
}


void push(StackType* p, element item)
{
	if (is_full(p))
	{
		p->capacity *= 2;
		p->data = (element*)realloc(p->data, p->capacity * sizeof(element));
	}
}


element pop(StackType* p)
{
	if (is_empty(p))
	{
		fprintf(stderr, "스택 공백 에러\n");
	}
	else return p->data[(p->top)--];
}

int main(void)
{
	srand(time(NULL));
	StackType p;

	init_stack(&p);

	for (int i = 0; i < 30; i++)
	{
		int rand_num = rand() % 100 + 1;
		if (rand_num % 2 == 0)
		{
			push(&p, rand_num);
			printf("push %d\n", rand_num);
		}
		else
		{
			printf("pop %d\n", pop(&p));
		}
	}
	free(p.data);
	return 0;
}