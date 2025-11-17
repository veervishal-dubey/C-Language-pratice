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
    while (current->next!=NULL)
    {
        current=current->next;
    }
    current->next=f2;
    return f1;
}

struct node * reverse(struct node *f)
{
    struct node * current, *sep;
    sep=f;
    sep->next=NULL;
    
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
    
    first=concatenate(first,second);
    printf("Concatenated List\n");
    display(first);
    
    return 0;
}
