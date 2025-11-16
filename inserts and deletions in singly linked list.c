#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node * next;
};

struct node* insert_begin(struct node*f, int data);
struct node* insert_end(struct node*f, int data);
void display(struct node *f);
struct node* insert_before(struct node*f, int data, int target);
struct node* insert_after(struct node*f, int data, int target);
struct node* delete_begin(struct node *f);
struct node* delete_end(struct node *f);
struct node* delete_target(struct node *f, int target);

int main(){
    struct node *first = NULL;

    // Initial insertions
    first = insert_end(first, 6);       // List: 6
    first = insert_begin(first, 7);     // List: 7 → 6
    first = insert_begin(first, 1);     // List: 1 → 7 → 6
    first = insert_end(first, 4);       // List: 1 → 7 → 6 → 4

    printf("Initial list:\n");
    display(first);

    // Insert before a middle node
    first = insert_before(first, 99, 6); // List: 1 → 7 → 99 → 6 → 4
    

    // Insert before head
    first = insert_before(first, 88, 1); // List: 88 → 1 → 7 → 99 → 6 → 4
  

    // Insert after a middle node
    first = insert_after(first, 55, 99); // List: 88 → 1 → 7 → 99 → 55 → 6 → 4
  

    // Insert after tail
    first = insert_after(first, 22, 4);  // List: 88 → 1 → 7 → 99 → 55 → 6 → 4 → 22
    

    // Insert before a non-existent value
    first = insert_before(first, 77, 100); // Should print "Element not found!"
    

    // Insert after a non-existent value
    first = insert_after(first, 66, 200); // Should print "Element not found!"
    
    display(first);
    
    first= delete_begin(first);
    
    first = delete_end(first);
    
    first = delete_target(first,55);
    
    display(first);

    return 0;
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

struct node* insert_before(struct node*f, int data, int target){
    if (f==NULL)
    {
        printf ("The list is empty.\n");
        return f;
    }
    else{
        struct node *previous, *current, *new;
        new=(struct node *)malloc(sizeof(struct node));
        new->info=data;
        current=f->next;
        previous=f;
        if (f->info==target)
        {
            new->next=f;
            f=new;
            return f;
        }
        while (current!=NULL && current->info!=target)
        {
            previous=previous->next;
            current=current->next;
        }
        if (current!=NULL)
        {
            previous->next=new;
            new->next=current;
            return f;
        }
        else{
            printf("Element not found!");
            return f;
        }
    }
}

struct node* insert_after(struct node*f, int data, int target){
    if (f==NULL)
    {
        printf("The linked list is empty.\n");
        return f;
    }
    else
    {
        struct node *new, *current=f;
        new=(struct node *)malloc(sizeof(struct node));
        new->info=data;
        while (current!=NULL&&current->info!=target)
        {
            current=current->next;
        }
        if (current!=NULL)
        {
            new->next=current->next;
            current->next=new;
            return f;
        }
        else
        {
            printf("Element not found.\n");
            return f;
        }
    }
    
}

struct node* delete_begin(struct node *f)
{
    if (f==NULL)
    {
        printf("The linked list is empty. Cannot delete.");
        return f;
    }
    struct node * temp=f;
    f=f->next;
    
    free(temp);
    return f;
}

struct node* delete_end(struct node *f)
{
    if (f==NULL)
    {
        printf("The linked list is empty.");
        return f;
    }
    else if(f->next==NULL)
    {
        free(f);
        return NULL;
    }
    struct node *current=f->next, *previous=f;
    while (current->next!=NULL)
    {
        previous=previous->next;
        current=current->next;
    }
    previous->next=NULL;
    free(current);
    return f;
}

struct node* delete_target(struct node *f, int target)
{
    if (f==NULL)
    {
        printf("The linked list is empty.");
        return f;
    }
    else if (f->info==target)
    {   struct node *current=f;
        f=f->next;
        free(current);
        return f;
    }
    struct node *current=f->next, *previous=f;
    while (current!=NULL && current->info!=target)
    {
        previous=previous->next;
        current=current->next;
    }
    if (current==NULL)
    {
        printf("Element not found in the list.");
        return f;
    }
    else
    {
        previous->next=current->next;
        free(current);
        return f;
    }
}
