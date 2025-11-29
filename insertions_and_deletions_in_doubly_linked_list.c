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

struct node * insert_at_position(struct node * f , int data, int position)
{
    struct node * new, *current=f;
    new=(struct node *)malloc(sizeof(struct node));
    new->prev=NULL;
    new->next=NULL;
    new->info=data;
    if (position==1)
    {
        if (f==NULL)
        {
            f=new;
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

    else
    {
        for (int i=1;i<position-1 && current!=NULL;i++) //go to the (position -1)th node for zero indexed list.
        {
            current=current->next;
        }
        if (current==NULL)
        {
            printf("Did not insert at position %d as there are not enough nodes in the list.\n",position);
            free(new);
            return f;
        }
        else
        {
            new->next=current->next;
            new->prev=current;
            if (current->next!=NULL)
            {
                struct node * newnode=current->next;
                newnode->prev=new;
            }
            current->next=new;
            return f;
        }
    }
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
        printf("NULL <-> ");
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

struct node * delete_target(struct node * f, int target)
{
    struct node *current=f, *previous=NULL;
    if (f==NULL)
    {
        printf("The list is empty.\n");
        return NULL;
    }

    else if (f->info==target)
    {
        f=f->next;
        f->prev=NULL;
        free(current);
        return f;
    }

    else
    {
        while (current!=NULL && current->info!=target)
        {
            previous=current;
            current=current->next;
        }
        if (current==NULL)
        {
            printf("The target was not found in the list. No deletion occured.\n");
            return f;
        }

        else if (current->next==NULL)
        {
            previous->next=NULL;
            free(current);
            return f;
        }

        else
        {
            struct node *nextnode=current->next;
            previous->next=nextnode;
            nextnode->prev=previous;
            free(current);
            return f;            
        }

    }
}

int main()
{
    struct node *first=NULL;
    first=insert_begin(first,6);
    first=insert_end(first,1);
    first=insert_end(first,12);
    first=insert_begin(first,23);
    first=insert_at_position(first,99,3);
    display(first);
    first=delete_end(first);
    first=delete_first(first);
    first=delete_target(first,99);
    display(first);
    return 0;
}
