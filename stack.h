#include<malloc.h>
//Stack Implementation using Dubbly-LinkedList
//-------------------------------Stack Structure-----------------------------------
typedef struct node Node;

typedef struct node{
	int data;
	Node* next;
	Node* prev;
}Node;

typedef struct stack Stack;

typedef struct stack{
	unsigned int size;
	Node* top;
}Stack;

//------------------------------Stack Interface API--------------------------------

//Build stack
Stack* buildStack();

//size of stack
int len(Stack* s);

//check stack is empty or not using enum type letter
int isEmptyStack(Stack* s);

//push element in stack
void push(int val, Stack* s);

//pop element in stack
void pop(Stack* s);

//give top value of stack
int top(Stack* s);

//-------------------------------Internal Methods-----------------------------------
Node* createNode(int val)
{
	Node* n = malloc(sizeof(Node));
	n->data = val;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

//------------------------------Method Implementation-------------------------------
Stack* buildStack()
{
	Stack* s = malloc(sizeof(Stack));
	s->size = 0;
	s->top = NULL;
	return s;
}

int len(Stack* s)
{
	return s->size;
}

int isEmptyStack(Stack* s)
{
	if(s->size != 0)
		return 0;
	return 1;
}

int top(Stack* s)
{
	if(s->size > 0)
		return s->top->data;
	return -1;
}

void push(int val, Stack* s)
{
	Node* n = createNode(val);
	if(s->size != 0)
	{
		Node* temp = s->top;
		temp->next = n;
		s->top = n;
		s->top->next = NULL;
		s->top->prev = temp;
	}
	else
		s->top = n;
	s->size = s->size + 1;
}

void pop(Stack* s)
{
	if(s->size > 1)
	{
		Node* temp = s->top;
		s->top = temp->prev;
		s->top->next = NULL;
		free(temp);
		s->size = s->size - 1;
	}
	else if(s->size == 1)
	{
		s->top = NULL;
		s->size = s->size - 1;
	}
}
