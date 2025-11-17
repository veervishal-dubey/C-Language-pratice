#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node * next;
};

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

struct node* concatenate(struct node *f1, struct node *f2){
    struct node * current=f1;
    if (f1==NULL)
        return f2;

    while (current->next!=NULL)
    {
        current=current->next;
    }
    current->next=f2;
    return f1;
}

struct node * reverse(struct node *f)
{
    struct node * current, *newfront;
    if (f==NULL)
    {
        printf("List is empty.");
        return f;
    }

    newfront=f;
    f=f->next;
    newfront->next=NULL;

    while (f!=NULL)
    {
        current=f;
        f=f->next;
        current->next=newfront;
        newfront=current;
    }
    return newfront;
}

struct node* sort(struct node *f) {
    if (f == NULL || f->next == NULL)
        return f;

    struct node *sorted = NULL;  
    struct node *current = f;

    while (current != NULL) {
        struct node *next = current->next;

       
        if (sorted == NULL || current->info < sorted->info) {
            current->next = sorted;
            sorted = current;
        } else {
            struct node *temp = sorted;
            while (temp->next != NULL && temp->next->info < current->info) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }

    return sorted;
}

int main(){
    struct node *first = NULL, *second=NULL;

    // Initial insertions
    first = insert_end(first, 6);
    first = insert_begin(first, 7);
    first = insert_begin(first, 1);
    first = insert_end(first, 4);

    printf("Initial list 1:\n");
    display(first);


    second = insert_end(second, 12);
    second = insert_begin(second, 14);
    second = insert_begin(second, 2);
    second = insert_end(second, 8);

    printf("Initial list 2:\n");
    display(second);

    printf("\n reversed list 2:\n");
    second=reverse(second);
    display(second);

    printf("\n sorted list 1:\n");
    first=sort(first);
    display(first);

    first=concatenate(first,second);
    printf("Concatenated List\n");
    display(first);

    return 0;
}
