#include<malloc.h>
//------------------------LinkedList Structure---------------------------------

typedef struct node Node;

typedef struct node{
	int data;
	Node* next;
}Node;

typedef struct list{
	unsigned int size;
	Node* head;
	Node* tail;
}List;

//---------------------------LinkedList Interface API ---------------------------------
//Build empty list
List* buildList();

//size of list
int len(List* l);

//check List is empty or not using enum type letter
int isEmptyList(List* l);

//inserting element at beginning of List
void insertBegin(int val, List* l);

//inserting element at End of List
void insertEnd(int val, List* l);

//inserting element at idx position of List
void insertAtPosition(int val, unsigned int idx, List* l);

//deleting head of list
void removeBegin(List* l);

//deleting tail of list
void removeEnd(List* l);

//deleting element at idx position of list
void removeAtPosition(unsigned int idx, List* l);

//search element in List return it's position if fount else return not found (use enum)
int searchList(int val, List* l);

//-----------------------Internal Methods--------------------------------------

//creating Node 
Node* createNode(int val);

Node* createNode(int val)
{
	Node* n = malloc(sizeof(Node));
	n->data = val;
	n->next = NULL;
	return n;
}

//----------------------Method Implementation-------------------------------------

List* buildList()
{
	List* l = malloc(sizeof(List));
	l->size = 0;
	l->head = NULL;
	l->tail = NULL;
	return l;
}

int len(List* l)
{
	return l->size;
}


int isEmptyList(List* l)
{
	if(l->size == 0)
		return 1;
	return 0;
}
		

void insertBegin(int val, List* l)
{
	Node* n = createNode(val);
	n->next = l->head;
	l->head = n;
	if(l->size == 0)
	{
		l->tail = n;
	}
	l->size = l->size + 1;
}

void insertEnd(int val, List* l)
{
	Node *n = createNode(val);
	if(l->size == 0)
	{
		l->tail = n;
		l->head = n;
	}
	else
	{
		l->tail->next = n;
		n->next = NULL;
		l->tail = n;
	}
	//printf("%d",l->size);
	l->size = l->size + 1;
}

void insertAtPosition(int val, unsigned int idx, List* l)
{
	if(idx > l->size)
	{
		return;
	}
	else if(idx == 0)
	{
		insertBegin(val, l);
	}
	else if(l->size == idx)
	{
		insertEnd(val, l);
	}
	else
	{
		Node* n = createNode(val);
		Node* temp = l->head;
		Node* nxtTemp = NULL;
		int i = 1;
		while(i < idx)
		{
			temp = temp->next;
			i++;
		}
		nxtTemp = temp->next;
		temp->next = n;
		n->next = nxtTemp;
		l->size = l->size + 1;
	}
}
	


void removeBegin(List* l)
{
	if(l->size < 1)
		return;
	else if(l->size == 1)
	{
		Node* temp = l->head;
		l->head = NULL;
		l->tail = NULL;
		free(temp);
		l->size = l->size - 1;	
	}
	else
	{
		Node* temp = l->head;
		l->head = l->head->next;
		free(temp);
		l->size = l->size - 1;	
	}
}

void removeEnd(List* l)
{
	if(l->size < 1)
		return;
	else if(l->size == 1)
	{
		Node* temp = l->head;
		l->head = NULL;
		l->tail = NULL;
		free(temp);
		l->size = l->size - 1;
	}
	else
	{
		Node* temp = l->head;
		int i = 2;
		while(i < l->size)
		{
			temp = temp->next;
			i++;
		}
		l->tail = temp;
		temp = temp->next;
		free(temp);
		l->size = l->size - 1;
	}
}

void removeAtPosition(unsigned int idx, List* l)
{
	if(idx >= l->size)
		return;
	else if(idx == 0)
	{
		removeBegin(l);
	}
	else if(idx == l->size-1)
	{
		removeEnd(l);
	}
	else
	{
		Node* prv = l->head;
		Node* nxt = l->head->next;
		int i = 1;
		while(i < idx)
		{
			prv = nxt;
			nxt = nxt->next;
			i++;
		}
		prv->next = nxt->next;
		free(nxt);
		l->size = l->size - 1;
	}
}

int searchList(int val, List* l)
{
	Node* temp = l->head;
	int x = 0;
	while(temp != NULL)
	{
		if(temp->data == val)
			x = 1;
		temp = temp->next;
	}
	return x;
}
