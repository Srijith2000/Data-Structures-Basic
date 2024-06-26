#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *prev, *next;
};
struct node* start = NULL;

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

int max()
{
	if (start == NULL) {
        printf("\nList is empty\n");
    }
    struct node* temp; int max= start->info;
    temp = start->next;
    while (temp != NULL) {
		if(temp->info >max) max=temp->info;
        temp = temp->next;
    }
    return max;
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
	printf("\nMaximum element : %d", max());
	return 0;
}
