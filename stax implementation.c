#include <stdio.h>
#include <stdbool.h>
#define size 10
typedef struct
{
    // This is the structure to define the stack. Implement using an array.
    int arr[size]; 
    // define the top value
    int top;
}Stack;

void initialize (Stack *stack){
    stack->top=-1;
}

int isEmpty(Stack *stack){
    return stack->top==-1;
} 

int isFull(Stack *stack){
    // yaha pe size minus 1 isliye check ho rha hai kyunki agar stack me ek element hai to top 0th index ko refer karega, agar 2 hai to 1st index ko and so on... agar size number of elements hai to phir maximum index size - 1 honge isliye usko check kar rhe hai.
    return stack->top==(size-1);
}

int push(Stack *stack, int element){
    if (isFull(stack))
    {
        printf("Cannot push. Stack will overflow because it is full.");
        return 1;
    }
    else
    {
        stack->top++;
        stack->arr[stack->top]=element;
        // increment top and then add the element to the top of the structure.
        return 0;
    }
}

int pop(Stack *stack){
    if (isEmpty(stack))
    {
        printf("Cannot pop. Stack will underflow because it is empty.");
        return -1;
    }
    else
    {
        int value=stack->arr[stack->top];
        stack->top--;
        printf("Popped %d off the stack",value);
        return value;
        // pehle decrement kiya, taaki top of stack niche aa jaye, phir uski value return kardi. agar naya top element push kiya, to popped valu replace ho jayegi because list ke elements dynamic hai.
    }
}

void display(Stack *stack){
    if (isEmpty(stack))
    {
        printf("The stack is empty.");
    }
    else
    {   printf("printing the stack from the top to the bottom.\n");
        for (int i=stack->top;i>=0;i--)
        {
            printf("%d\n",stack->arr[i]);
        }
    }
}

void peek(Stack *stack){
    if (isEmpty(stack))
    {
        printf("The stack is empty.");
    }
    else{
        printf("The top value of the structure is %d",stack->arr[stack->top]);
    }
}
// peeking maane bina poore stack ko dekhe sirf top element ko access karna

int main()
{   
    Stack s1;
    initialize(&s1);
    push(&s1,1);
    push(&s1,2);
    push(&s1,3);
    peek(&s1);
    display(&s1);
    printf("Popped: %d",pop(&s1));
    peek(&s1);
    display(&s1);

}



