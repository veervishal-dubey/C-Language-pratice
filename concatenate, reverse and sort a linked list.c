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

struct node * reverse(struct node *f)
{   
    // is function me, hum list ke end tak traverse karte hai or pointer adjust karte hai, using three pointers: 
    // nextnode, jo ki agle linked node ko point kar rha hai, we use to store the next node. 
    // current jo ki current node hai, iska pointer hum iske previous wale node me daale rahe hai 
    // previous jo ki hum use kar rahe hai to track the previous node. 
    // in the end, previous ko current node ki jagah increment kardo, current ko nextnode ki jagah increment kar do, or next node ko current->next me increment kardo
    if (f==NULL || f->next==NULL)
        return f;
    else
    {
        struct node * previous=NULL, * current=f, *nextnode=NULL;
        while (current!=NULL)
        {
            nextnode=current->next; //yaha pe maine nextnode ko save kar liya hai, taaki increment me aasaani rahe
            current->next=previous; //current node ke next pointer ko pichle element pe point karwa dia.
            previous=current; // previous ko current me increment kar dia
            current=nextnode; // finally current ko agle pe increment kar dia.
        }
        struct node * newfront=previous;
        return newfront;
    }
}

struct node* sort(struct node* f) {
    // current is the node jisko insert kar rahe hai, traversal_node is used to walk through the list, previous is used to keep track of the previous traversed node
    // we insert current in between traversal_node and previous node. 
    if (f == NULL || f->next == NULL) {
        return f;
    }

    struct node *sorted_head = NULL;
    struct node *current = f;

    while (current != NULL) {
        struct node *nextnode = current->next;

        if (sorted_head == NULL || current->info < sorted_head->info) { //agar element kam hai, to phir insert at the start.
            current->next = sorted_head;
            sorted_head = current;
        } else {
            struct node *traversal_node = sorted_head;
            struct node *previous = NULL;

            while (traversal_node != NULL && traversal_node->info < current->info) { //traverse to find sahi position
                previous = traversal_node;
                traversal_node = traversal_node->next;
            }

            if (previous == NULL) { 
                // matlab koi bhi smaller element nahi mila. you insert at the start. 
                current->next = sorted_head;
                sorted_head = current;
            } else {
                // Insert between previous and traversal_node
                previous->next = current;
                current->next = traversal_node;
            }
        }

        current = nextnode;
    }

    return sorted_head;
}

struct node * concatenate(struct node * f1, struct node *f2)
{   if (f1==NULL)
        return f2;
    struct node * current=f1;
    while (current->next!=NULL)
        current=current->next;
    current->next=f2;
    return f1;
}

int main(){
    struct node *first = NULL, *second=NULL;

    // Initial insertions
    first = insert_end(first, 6);       // List: 6
    first = insert_begin(first, 7);     // List: 7 → 6
    first = insert_begin(first, 1);     // List: 1 → 7 → 6
    first = insert_end(first, 4);       // List: 1 → 7 → 6 → 4

    printf("Initial list:\n");
    
    display(first);
    

    first=reverse(first);

    display(first);

    first=sort(first);

    display(first);

    second=insert_end(second,12);
    second=insert_begin(second,14);
    second=insert_begin(second,2);
    second=insert_end(second,8);

    first=concatenate(first,second);

    display(first);

    return 0;
}
