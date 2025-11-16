#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node * next;
};

struct node* insert_begin(struct node*f, int data);
struct node* insert_end(struct node*f, int data);
void display(struct node *f);

int main()
{
    // intialize the linked list.
    struct node *first;
    first=NULL;
    first=insert_end(first,6);
    first=insert_begin(first,7);
    first=insert_begin(first,1);
    first=insert_end(first,4);
    display(first);
}

struct node* insert_begin(struct node*f, int data)
{
    struct node * new;
    new=(struct node *)malloc(sizeof(struct node));
    new->next=f;
    new->info=data;
    f=new;
    return f;
}

struct node* insert_end(struct node *f, int data)
{
    struct node * current, * new;
    current=f;
    new=(struct node *)malloc(sizeof(struct node));
    new->info=data;
    new->next=NULL;
    if (f==NULL)
    {
        return new;
    }
    
    while (current->next != NULL)
    {
        current=current->next;
    }
    current->next=new;
    return f;
}

void display(struct node *f){
    struct node * current=f;
    if (f==NULL)
    {
        printf("Linked List is empty.");
    }
    else if (f->next==NULL)
    {
        printf("%d",f->info);
    }
    else
    {
        while (current!=NULL)
        {
            printf("%d -> ",current->info);
            current=current->next;
        }printf("NULL\n");
    }
}
