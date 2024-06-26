#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *prev, *next;
};
struct node* start = NULL;

void traverse()
{
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node* temp;
    temp = start;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}

void insert(int data)
{
    struct node *temp, *trav;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->info = data;
    temp->next = NULL;
    trav = start;
    if (start == NULL)	start = temp;
    else 
	{
        while (trav->next != NULL)	trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
}

node* reverse(node *head)
{
	int data;
	struct node *temp,*t;
    temp = new node;
    temp = head;
	temp->prev=temp->next;
	temp->next= NULL;
	temp = temp->prev;
    while (temp->next != NULL)
	{
		t=temp->next;
		temp->next=temp->prev;
		temp->prev=t;
		
		temp = temp->prev;
	}
    temp->next = temp->prev;
    temp->prev = NULL;
    head=temp;
    return head;
}

int main()
{
	int size,i,n;
	printf("Enter number of elements : ");
	scanf("%d",&size);
	printf("Enter elements : ");
	for(i=0; i<size; i++)
	{
		scanf("%d",&n);
		insert(n);
	}
	start=reverse(start);
	printf("Reversed Doubly Linked list : ");
	traverse();
	return 0;
}
