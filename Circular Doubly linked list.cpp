#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
    struct node *prev;    
};
typedef struct node n;

n* create_node(int);
void add_node();
void insert_at_first();
void insert_at_end();
void insert_at_position();
void delete_at_first();
void delete_at_end();
void delete_node_position();
void update();
void search();
void display_from_beg();
void display_in_rev();
 
n *temp, *ptr, *prev;
n *first = NULL, *last = NULL;
int number = 0;
 
int main()
{
    int ch;
 
    printf("\nCircular Doubly linked list\n\n");
   printf("1. Insert at beginning \n2. Insert at end\n3. Insert at position\n"
            	"4. Delete node at position\n" 
            	"5. Update node value\n"
            	"6. Search element \n"
            	"7. Display list from beginning\n"
				"8. Display list from end \n9. exit \n"
				"10. Add node\n11. Delete at beginning"
				"\n12. Delete at end\n");
 
    while (1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1 :
            insert_at_first();
            break;
        case 2 :
            insert_at_end();
            break;
        case 3 :
            insert_at_position();
            break;
        case 4 :
            delete_node_position();
            break;
        case 5 :
            update();
            break;
        case 6 :
            search();
            break;
        case 7:
            display_from_beg();
            break;
        case 8:
            display_in_rev();
            break;
        case 9:
            exit(0);
        case 10:
            add_node();
            break;
        case 11:
        	delete_at_first();
        	break;
        case 12:
			delete_at_end();
			break;	
        default:
            printf("\n Invalid choice");                
        }
    }
    return 0;
}

n* create_node(int info)
{
    number++;
    temp = (n *)malloc(sizeof(n));
    temp->val = info;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void add_node()
{
    int info;
    printf(" Enter the value to add:");
    scanf("%d", &info);
    temp = create_node(info);
    if (first == last && first == NULL)
    {
        first = last = temp;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
        last->next = first;
        first->prev = last;
    }
}

void insert_at_first()
{
    int info;
    printf(" Enter the value to be inserted at first:");
    scanf("%d", &info);
    temp = create_node(info);
    if (first == last && first == NULL)
    {    
        printf(" Initially it is empty linked list later insertion is done");
        first = last = temp;
        first->next = last->next = NULL;
        first->prev = last->prev = NULL;
    }
    else
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
        first->prev = last;
        last->next = first;
        printf(" The value is inserted at beginning");
    }
}

void insert_at_end()
{
    int info;    
    printf(" Enter the value that has to be inserted at last:");
    scanf("%d", &info);
    temp = create_node(info);
    if (first == last && first == NULL)
    {
	    printf(" Initially the list is empty and inserted but at first");
        first = last = temp;
        first->next = last->next = NULL;    
        first->prev = last->prev = NULL;
    }
    else
    {
        last->next = temp;
        temp->prev = last;
        last = temp;
        first->prev = last;
        last->next = first;
    }
}

void insert_at_position()
{    
    int info, pos, len = 0, i;
    n* prevnode;
    printf(" Enter the value to insert:");
    scanf("%d", &info);
    printf(" Enter the position where to enter:");
    scanf("%d", &pos);
    temp = create_node(info);
    if (first == last && first == NULL)
    {
        if (pos == 1)
        {
            first = last = temp;
            first->next = last->next = NULL;    
            first->prev = last->prev = NULL;
        }
        else
           printf(" Empty linked list insert at that particular position");
    }
    else
    {
        if (number < pos)
            printf("\n node cant be inserted as position is exceeding the linked list length");
        else
        {
            for (ptr = first, i = 1;i <= number ; i++)
            {
                prevnode = ptr;
                ptr = ptr->next;
                if (i == pos-1)
                {
                    prevnode->next = temp;
                    temp->prev = prevnode;
                    temp->next = ptr;
                    ptr->prev = temp;
                    printf("\ninserted at position %d successfully", pos);
                    break;
                }
            }
        }
    }
}

void delete_node_position()
{    
    int pos, count = 0, i;
    n *temp, *prevnode;
    printf("\n enter the position to delete:");
    scanf("%d", &pos);
    if (first == last && first == NULL)
    printf("\n empty linked list you cant delete");
    else
    {
        if (number < pos)
        printf("\n node cant be deleted");
        else
        {
            for (ptr = first, i = 1;i <= number; i++)
            {
                prevnode = ptr;
                ptr = ptr->next;
                if (pos == 1)
                {   
                    number--;
                    last->next = prevnode->next;
                    ptr->prev = prevnode->prev;
                    first = ptr;
                    printf("%d is deleted", prevnode->val);
                    free(prevnode);
                    break;        
                }
                else if (i == pos - 1)
                {   
                    number--;
                    prevnode->next = ptr->next;
                    ptr->next->prev = prevnode;
                    printf("%d is deleted", ptr->val);
                    free(ptr);
                    break;
                }
            }
        }
	}
}
        
void delete_at_first()
{
    n *temp, *prevnode;
    if (first == last && first == NULL)
    printf("\n Empty linked list you cant delete");
    ptr = first;
    prevnode = ptr;
    ptr = ptr->next;
    number--;
    last->next = prevnode->next;
    ptr->prev = prevnode->prev;
    first = ptr;
    printf(" %d is deleted", prevnode->val);
    free(prevnode);
}

void delete_at_end()
{
	n *temp, *prevnode;
    if (first == last && first == NULL)
    printf("\n Empty linked list you cant delete");
    ptr = last;
    prevnode = ptr->prev; 
    number--;
    last->next = first->next;
    first->prev = prevnode->prev;
    last = prevnode;
    printf(" %d is deleted", ptr->val);
    free(ptr);
}

void update()
{    
    int oldval, newval, i, f = 0;
    printf("\n enter the value old value:");
    scanf("%d", &oldval);
    printf("\n enter the value new value:");
    scanf("%d", &newval);
    if (first == last && first == NULL)
        printf("\n list is empty no elements for updation");
    else
    {    
        for (ptr = first, i = 0;i < number; ptr = ptr->next,i++)
        {    
            if (ptr->val == oldval)
            {    
                ptr->val = newval;
                printf("value is updated to %d", ptr->val);
                f = 1;
            }    
        }
        if (f == 0)
            printf("\n no such old value to be get updated");
    }
}

void search()
{
    int count = 0, key, i, f = 0;
    printf("\n enter the value to be searched:");
    scanf("%d", &key);
    if (first == last && first == NULL)
        printf("\nlist is empty no elements in list to search");
    else
    {
        for (ptr = first,i = 0;i < number;i++,ptr = ptr->next)
        {
            count++;
            if (ptr->val == key)
            {
                printf("\n the value is found at position at %d", count);
                f = 1;
            }    
        }
        if (f == 0)
            printf("\n the value is not found in linked list");
    }
}

void display_from_beg()
{
    int i;
    if (first == last && first == NULL)
        printf(" list is empty no elements to print");
    else
    {    
        printf(" %d number of nodes are there", number);
        for (ptr = first, i = 0;i < number;i++,ptr = ptr->next)
            printf("\n %d", ptr->val);
    }
}

void display_in_rev()
{
    int i;        
    if (first == last && first == NULL)
        printf(" list is empty there are no elements");
    else
    {
        for (ptr = last, i = 0; i < number; i++, ptr = ptr->prev)
        {
            printf("\n %d", ptr->val);
        } 
    }
}

