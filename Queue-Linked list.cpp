#include<stdio.h>
#include<conio.h>
#include<process.h>

struct Node
{
   int data;
   struct Node *next;
};
struct Node *front = NULL,*rear = NULL;

void EnQueue(int);
void DeQueue();
void display();
void Front();
void QueueSize();
void retrieve();
void empty();
void full();

int main()
{
    int choice, value;
    printf("\n*** Queue Implementation using Linked List ***\n");
    while(1)
    {
        system("cls");
		printf("\n****** MENU ******\n");
        printf("1. Insert in Queue\n");
        printf("2. Delete From Queue\n");
        printf("3. Display Queue\n");
        printf("4. Front of the Queue\n");
        printf("5. Size of Queue\n");
        printf("6. Retieve last element\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
         case 1:
                printf("Insert the value you want to enter: ");
                scanf("%d", &value);
                EnQueue(value);
                break;
         case 2:
                DeQueue();
                break;
         case 3:
                display();
                break;
         case 4:
                Front();
                break;
         case 5:
                QueueSize();
                break;
         case 6:
         		retrieve();
         		break;
         case 7:
         		exit(1);
         		
         default:
                printf("\nInvalid Selection!!..Select valid number please!!\n");
        };
        getch();
    }
   return 0;
}
void EnQueue(int value)
{
    struct Node *newNode;
    newNode = new Node;
    newNode -> data = value;
    newNode -> next = NULL;
    
    if(newNode == NULL)
		full();
	else if(front == NULL)
        front = rear = newNode;
    else
    {
        rear -> next = newNode;
        rear = newNode;
    }
    printf("\n Data inserted in Queue!!!\n");
}

void DeQueue()
{
    if(front == NULL)
        printf("\n Queue is Empty!!!\n");
    else
    {
        struct Node *temp = front;
        front = front -> next;
        printf("\n Deleted element is: %d\n", temp->data);
        delete temp;
    }
}

void display()
{
    empty();
    if(front != NULL)
    {
        struct Node *temp = front;
        while(temp->next != NULL)
        {
            printf("%d --> ",temp->data);
            temp = temp -> next;
        }
        printf("%d \n", temp->data);
   }
}

void Front()
{
    empty();
    if(front != NULL)
        printf("\n Data at front of the queue is %d \n",front->data);
}

void QueueSize()
{
    empty();
    if(front != NULL)
    {
        int count=0;
        struct Node *temp = front;
        while(temp->next != NULL)
        {
            count++;
            temp = temp -> next;
        }
        printf("\n Size of the queue is %d \n",count+1);
    }
}

void retrieve()
{
    empty();
    if(front != NULL)
    {
        struct Node *temp = front;
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        printf(" Retrieved Last Element is %d \n", temp->data);
    }
}

void empty()
{
	 if(front == NULL)
        printf("\n Queue is Empty!!!\n");
}

void full()
{
    printf("\n Queue is full!!\n");
}
