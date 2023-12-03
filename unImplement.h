#include<malloc.h>

typedef struct node Node;

struct node{
	Node *prev;
	void* elt;
	Node *next;
};

typedef struct list List;

struct list{
	Node *first;
	Node *last;
	int size;
};

List* _buildEmptyList()
{
	List *newlist = malloc(sizeof(List));
	newlist->first = NULL;
	newlist->last = NULL;
	newlist->size = 0;
	return newlist;
}

Node* buildNode(void* x)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->elt = x;
	newNode->next = NULL;
	return newNode;
}

void insertFirst(void* x, List* l)
{
	Node* newNode = buildNode(x);
	if(l->size ==  0)
	{
		l->first = newNode;
		l->last = newNode;
	}
	else
	{
		newNode->next = l->first;
		l->first->prev = newNode;
		l->first = newNode;
	}

	l->size += 1;
}

void insertLast(void *x, List* l)
{
	Node* newNode = buildNode(x);
	if(l->size == 0)
	{
		l->first = newNode;
		l->last = newNode;
	}
	else
	{
		newNode->prev = l->last;
		l->last->next = newNode;
		l->last = newNode;
	}

	l->size += 1;
}

void deleteFirst(List* l)
{
	if(l->size != 0)
	{
		l->first = l->first->next;
		free(l->first->prev);
		l->first->prev = NULL;
		l->size -= 1;
	}
}
	
void deleteLast(List* l)
{
	if(l->size != 0)
	{
		l->last = l->last->prev;
		free(l->last->next);
		l->last->next = NULL;
		l->size -= 1;
	}
}

Node* first(List* l)
{
	if(l->size != 0)
		return l->first;
	return NULL;
}

Node* last(List* l)
{
	if(l->size != 0)
		return l->last;
	return NULL;
}		
