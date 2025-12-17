
#include <stdio.h>
#include <ctype.h>

int top = -1;
int size=20;
int stack[20];
int bracket_stack[20];
void push(char arr[], char element)
{
	if (top< size-1)
	{
		top++;
		arr[top] = element;
	}
	else
	{
		printf("Stack Overflow condition. Cannot Push any element\n");
	}
 }
char pop(char arr[])
{
	if (top != -1)
	{
		char value = arr[top];
		top--;
		return value;
	}
	else
	{
		printf("Stack Underflow condition. Cannot Pop any element\n");
		return '\0';
	}
}

void display(char arr[])
{
	if (top == -1)
	{
		printf("The stack is empty.");
	}
	else
	{
		printf("The elements from the top are: \n");
		for (int i = top; i >= 0;i--)
		{
			printf("%c\n",arr[i]);
		}
	}
}
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

void infix2postfix(char infix[], char arr[])
{
    char postfix[20];
    char symbol;
    int i=0,j=0;

    while (infix[i]!='\0')
    {
        symbol=infix[i];
        if (isalnum(symbol))//using isalnum() to directly attach the character to the postfix expression. It is a solid piece, while the operators are working pieces.
        {
            postfix[j++]=symbol;//we directly attach to the postfix as the letters dont need re arrangement, it is the micro expressions that do.
        }
        //now we check for brackets and their grouping.
        else if(symbol=='(')//acts as a market to mark where the micro expression begins.
        {
            push(arr,symbol);//keeping pushing the elements to the stack to arrange the micro expression in the stack.
        }
        else if (symbol==')')//ends the micro-expression. Take the micro expression and move it into postifx into the correct order.
        {
            while (arr[top]!='(')
            {
                postfix[j++]=pop(arr);
            }
            pop(arr);
        }
        else{
            while (top!=-1 && stackprec(arr[top])>inputprec(symbol))
        {
            postfix[j++]=pop(arr);//if stackprecedence of the top is more than the input precedence, we pop it out and add it to the thing. We do this until the stack is empty or find an operator with lower precedence
        }
        push(arr,symbol);//after popping the higher precedence operators, we push the current input onto the stack.

        }
        i++;//move to the next character.
    }
    while (arr[top]!='#')
    {
        postfix[j++]=pop(arr);
    }
    postfix[j]='\0';
    printf("The postfix of %s is: %s",infix,postfix);
}

bool match_parenthesis(char symbol1, char symbol2)
{
    if (symbol1=='('&&symbol2==')')
        return true;
    else if (symbol1=='['&&symbol2==']')
        return true;
    else if (symbol1=='{'&&symbol2=='}')
        return true;
    else
        return false;
}

int main()
{
    push(stack,'#');
    char original[]="(A+B)*(C-D)/E";
    infix2postfix(original,stack);
}
