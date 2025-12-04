#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node * next;
};

struct node * insert_begin(struct node *head, int data)
{
    struct node * new;
    new=(struct node *)malloc(sizeof(struct node));
    if (new==NULL)
    {
        printf("Memory allocation failed");
        return head;
    }
    new->info=data;
    new->next=head;
    head=new;
    return head;
}

struct node * insert_end(struct node *head, int data)
{   struct node * new, *current=head;
    new=(struct node *)malloc(sizeof(struct node));
    if (new==NULL)
    {
        printf("Memory allocation failed");
        return head;
    }
    new->info=data;
    new->next=NULL;
    if (head==NULL)
    {
        head=new;
        return head;
    }
    else
    {
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=new;
        return head;
    }
}

struct node * insert_before_target(struct node *head, int data, int target)
{
    struct node * new, *current=head, *previous=NULL;
    
    
    if (head==NULL)
    {
        printf("The list is empty.\n");
        return head;
    }
    else if (head->info==target)
        return insert_begin(head,data);
    else
    {
        while (current!=NULL && current->info!=target)
        {
            previous=current;
            current=current->next;
        }
        if (current==NULL)
        {
            printf("The target was not found.\n");
        }
        else
        {   new=(struct node *)malloc(sizeof(struct node));
            if (new==NULL)
            {
                printf("Memory allocation failed");
                return head;
            }
            new->info=data;
            new->next=current;
            previous->next=new;
        }
        return head;
    }
}

struct node * insert_after_target(struct node *head, int data, int target)
{
    struct node *new, *current=head;
    if (head==NULL)
    {
        printf("The list is empty.");
        return head;
    }
    else if (head->info==target)
    {
        new=(struct node *)malloc(sizeof(struct node));
            if (new==NULL)
            {
                printf("Memory allocation failed.\n");
                return head;
            }
            new->info=data;
            new->next=head->next;
            head->next=new;
            return head;
    }
    else
    {
        while (current!=NULL && current->info!=target)
            current=current->next;
        if (current==NULL)
        {
            printf("The target does not exist in the list.\n");
            return head;
        }
        else
        {
            new=(struct node *)malloc(sizeof(struct node));
            if (new==NULL)
            {
                printf("Memory allocation failed.\n");
                return head;
            }
            new->info=data;
            new->next=current->next;
            current->next=new;
            return head;
        }
    }
}

struct node * insert_at_position(struct node *head, int data, int pos)
{
    struct node *new_node, *current = head;
    int i;

    new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return head;
    }
    new_node->info = data;

    if (pos == 1)
    {
        new_node->next = head;
        return new_node;
    }

    // Move to node at position (pos - 1)
    for (i = 1; i < pos - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Position out of range.\n");
        free(new_node);
        return head;
    }

    // Insert after current node
    new_node->next = current->next;
    current->next = new_node;

    return head;
}


struct node * delete_begin(struct node *head)
{   struct node * temp;
    if (head==NULL)
    {
        printf("The list is empty.\n");
        return head;
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
        return head;
    }
}

struct node * delete_end(struct node *head)
{
    struct node *current=head, *previous=NULL;
    if (head==NULL)
    {
        printf("The list is empty.\n");
        return head;
    }
    else if (head->next==NULL)
    {   
        head=head->next; //this points to null
        free(current);
        return head;
    }
    else
    {
        while (current->next!=NULL)
        {
            previous=current;
            current=current->next;
        }
        previous->next=NULL;
        free(current);
        return head;
    }
}

struct node * delete_target(struct node *head, int target)
{   struct node * current=head, *previous=NULL;
    if (head==NULL)
    {
        printf("The list is empty.\n");
        return head;
    }
    else if (head->info==target)
        return delete_begin(head);
    else
    {
        while (current!=NULL && current->info!=target)
        {
            previous=current;
            current=current->next;
        }
        if (current==NULL)
        {
            printf("The target was not found in the list.\n");
            return head;
        }
        else
        {
            previous->next=current->next;
            free(current);
            return head;
        }
    }
}

struct node * delete_at_position(struct node *head, int pos)
{
    struct node *current = head, *previous = NULL;
    int i;

    if (head == NULL)
    {
        printf("The list is empty.\n");
        return head;
    }

    // Delete at beginning (pos = 1)
    if (pos == 1)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Move to node at position (pos - 1)
    for (i = 1; i < pos - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    // Check if position is valid and next node exists
    if (current == NULL || current->next == NULL)
    {
        printf("Position out of range.\n");
        return head;
    }

    // Delete node at position pos
    struct node *temp = current->next;
    current->next = temp->next;
    free(temp);

    return head;
}

struct node * concatenate(struct node *head1, struct node * head2)
{
    if (head1==NULL)
        return head2;
    else
    {
        struct node *current=head1;
        while (current->next==NULL)
            current=current->next;
        current->next=head2;
        return head1;
    }
}

struct node * reverse (struct node *head)
{
    if (head==NULL || head->next==NULL)
        return head; //list is already reversed so return as it is.
    else
    {
        struct node * current=head, *previous=NULL, *nextnode;
        while (current!=NULL)
        {
            nextnode=current->next; //store the next node seperately
            current->next=previous; //point the current node to previous node
            previous=current; //increment previuous
            current=nextnode; //increment current
        }
        head=previous; //now the last node is 1st node
        return head;
    }
}

struct node * sort (struct node *head)
{
    if (head==NULL || head->next==NULL)
        return head; //list is already sorted to return as it is
    else
    {
        struct node * current=head, *previous=NULL, *nextnode, *sorted_head=NULL, *traversal_node;
        while (current!=NULL)
        {
            nextnode=current->next;
            if (sorted_head==NULL || current->info<sorted_head->info) //initial sort and sort the smallest element
            {
                current->next=sorted_head;
                sorted_head=current;
            }
            else
            {
                traversal_node=sorted_head;
                previous=NULL;
                while (traversal_node!=NULL && traversal_node->info<current->info)
                {
                    previous=traversal_node;
                    traversal_node=traversal_node->next;
                }
                if (traversal_node==NULL) //largest element. put it at the end
                {
                    previous->next=current;
                    current->next=NULL;
                }
                else
                {
                    previous->next=current;
                    current->next=traversal_node;
                }
            }
            current=nextnode;
        }
        return sorted_head;
    }
}
