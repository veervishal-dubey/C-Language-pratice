#include <stdio.h>
#define size 5

int double_queue[size];
int front =-1, rear=-1;

int isEmpty()
{
    return (front==-1);
}

int isFull()
{
    return (front==(rear+1)%size);
}

void insert_rear(int x)
{
    if (isFull()) //check karo ki full hai ya nahi
    {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty())
        rear=front=0; //initialize kardo
    else if (rear==size-1)
        rear=0; //humne already check kar liya hai ki agar 0th index filled hai in isFull(). So we can just wrap around
    else
        rear++;
    double_queue[rear]=x;

}

void insert_front(int x)
{
    if (isFull())
    {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty())
        front=rear=0;
    else if (front==0)
        front=size-1; //humne already check kar liya hai ki agar size -1 th index filled hai in isFull(). So we can just wrap around
    else
        front--;
    double_queue[front]=x;
}

void delete_front()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }
    int value=double_queue[front];
    printf("Deleted %d from queue.\n",value);
    if (front==rear)
        front=rear=-1;
    else if (front==size-1)
        front = 0;
    else
        front++;
}

void delete_rear()
{
    if (isEmpty())
    {    printf("Queue is empty!\n");
        return;}
    
    int value=double_queue[rear];
    printf("Deleted %d from queue.\n",value);
    if (front==rear)
        front=rear=-1;
    else if (rear==0)
        rear=size-1;
    else
        rear--;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }
    
    else
    {
        int i=front;
        for (i;;i=(i+1)%size)
        {
            printf("%d ",double_queue[i]);
            if (i==rear)
                break;
        }
    }
}

int main()
{
    insert_front(10);
    insert_front(20);
    insert_rear(30);
    insert_rear(40);
    display();
    delete_front();
    delete_rear();
    display();
    return 0;
}
