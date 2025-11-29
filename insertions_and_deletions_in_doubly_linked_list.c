#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

struct node* insert_begin(struct node*f, int data)
{
    struct node * new;
    new=(struct node *)malloc(sizeof(struct node));
    new->info=data;
    new->prev=NULL;
    if (f==NULL)
    {
        new->next=NULL;
        return new;
    } 
    else
    {
        new->next=f;
        f->prev=new;
        f=new;
        return f;
    }
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
    new->prev=current;
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
            printf("%d <-> ",current->info);
            current=current->next;
        }printf("NULL\n");
    }
}

struct node * delete_first(struct node *f)
{
    if (f==NULL)
    {
        printf("The list is empty.\n");
        return NULL;
    }

    else if (f->next==NULL)
    {
        free(f);
        return NULL;
    }

    else
    {
        struct node * delnode=f;
        f=f->next;
        f->prev=NULL;
        free(delnode);
        return f;
    }
}

struct node * delete_end(struct node *f)
{
    if (f==NULL)
    {
        printf("The list is empty.\n");
        return NULL;
    }
    else if (f->next==NULL)
    {
        free (f);
        return NULL;
    }
    else
    {
        struct node * current=f, *previous;
        while (current->next!=NULL)
        {
            previous=current;
            current=current->next;
        }
        previous->next=NULL;
        free(current);
        return f;
    }
}

int main()
{
    struct node *first=NULL;
    first=insert_begin(first,6);
    first=insert_end(first,1);
    first=insert_end(first,12);
    first=insert_begin(first,23);
    display(first);
    first=delete_end(first);
    first=delete_first(first);
    display(first);
    return 0;
}
