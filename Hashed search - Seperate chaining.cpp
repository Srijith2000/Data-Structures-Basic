#include <iostream>
#include <stdlib.h>
#define TABLE_SIZE 10
using namespace std;
struct node
{
int data;
struct node *next;
};
struct node *head[TABLE_SIZE]={NULL},*c;
void insert()
{
int i, key;
cout<<"Enter a value to insert : ";
cin>>key;
i=key % TABLE_SIZE;
struct node * newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=key;
newnode->next = NULL;
if(head[i] == NULL)
head[i] = newnode;
else
{
c=head[i];
while(c->next != NULL)
{
c=c->next;
}
c->next=newnode;
}
}
void search()
{
int key, index;
cout<<"\nEnter the element to be searched : ";
cin>>key;
index=key % TABLE_SIZE;
if(head[index] == NULL)
cout<<"\nSearch element not found\n";
else
{
for(c=head[index]; c!=NULL; c=c->next)
{

if(c->data == key)
{
cout<<"Search element found\n";
break;
}
}
if(c==NULL)
cout<<"\nSearch element not found\n";
}
}
void display()
{
int i;
for(i=0; i<TABLE_SIZE; i++)
{
cout<<"\nEntries at index "<<i<<" : ";
if(head[i] == NULL)
{
cout<<"No Hash Entry";
}
else
{
for(c=head[i];c!=NULL; c=c->next)
cout<<c->data<<"->";
}
}
}
main()
{
int opt, key, i;
while(1)
{
cout<<"1.Insert  2.Display   3.Search   4.Exit     Enter choice : ";
cin>>opt;
switch(opt)
{
case 1:
insert(); 
break;
case 2:
display(); cout<<"\n\n";
break;
case 3:
search();
break;
case 4:exit(0);
}
}
}
