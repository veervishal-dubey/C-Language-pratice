#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct{
    char arr[10];
    int top;
}Stack;

int push(Stack *stack, char element){
    if (stack->top>=9)
    {
        printf("Stack overflow");
        return -1;
    }
    else
    {
        stack->top++;
        stack->arr[stack->top]=element;
        return 0;
    }
}
char pop(Stack *stack){
    if (stack->top==-1)
    {
        printf("Stack underflow");
        return '\0';
    }
    else
    {
    char element=stack->arr[stack->top];
    stack->top--;
    printf("Popped element %c from stack\n",element);
    return element;
    }
}
//stack precedence'
int stackprec(char symbol){
    switch (symbol){

        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        case '#': return -1;
        default: return 8;
    }
}

//input precedence
int inputprec(char symbol){
    switch(symbol){

        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 10;
        default: return 7;
    }
}
//the basic idea here is that isalnum() helps to ask and stabalize the slid pieces (the characters) while the stack is used to rearrange them.
int main(){
    Stack s1;
    s1.top=-1;
    push(&s1,'#');
    char original[100]="A^B^C+D-E*F/G";
    char post[100];
    int i=0,j=0;
    char symbol;
    while (original[i]!='\0')
    {
        symbol=original[i];
        if (isalnum(symbol)) 
            //we used isalnum() function to identify the alphanumeric digits in the expressions, as they dont really need re-arranging, they are the building blocks for a postfix expression.
            {
                post[j++]=symbol; //we directly append the symbols to the postfix because the operands themselves are not re-arranged, it is the micro expressions inside that rearrange in a postfix.
            }
            else if(symbol==')')
            {
                while (s1.arr[s1.top]!='(')
                {
                    post[j++]=pop(&s1);
                }pop(&s1);
            }
        else{
            while (stackprec(s1.arr[s1.top])>inputprec(symbol))
        {
            post[j++]=pop(&s1);
        }
        push(&s1,symbol);
        }i++;
    }
    while (s1.arr[s1.top]!='#')
    {
        post[j++]=pop(&s1);
    }
    post[j]='\0';
    printf("The postfix is %s: ",post);
    return 0;
}
