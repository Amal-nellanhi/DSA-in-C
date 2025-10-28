/* PROGRAM TO CONVERT INFIX EXPRESSION TO PREFIX EXPRESSION */
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# define SIZE 100
char stack [SIZE] , infix[SIZE], postfix[SIZE],prefix[SIZE];
int top = -1;
void push (char ch)
{
    if(top == SIZE-1)
        printf("Stack overflow!!");
    else
        stack[++top] = ch;
}

char pop()
{
    if(top == -1)
        return '\0';
    else
        return stack[top--];
}

char peek ()
{
     if(top == -1)
        return '\0';
    else
        return stack[top];
}

int isOperator(char ch)
{
    return (ch == '^' ||ch == '/' ||ch == '*' ||ch == '+' ||ch == '-');
}

int precedence(char ch)
{
    switch (ch)
    {
        case '^':
                return 3;
        case '/':
        case '*':
                return 2;
        case '+':
        case '-':
                return 1;
        default:
                return 0; 
    }
}
void reverse(char array[])
{
    char temp; int n = strlen(array);
    for(int i = 0 ; i < n/2 ; i ++)
    {
        temp = array[i];
        array[i] = array[n-i-1];
        array[n-i-1] = temp ;
    }

}

void swapParanthesis(char array[])
{
    for(int i = 0 ; array[i] != '\0'; i ++)
    {
        if(array[i] =='(')
        {
            array[i] =')';
        }
        else if(array[i] ==')')
        {
            array[i] ='(';
        }
    }
}
void infixToPostfix(char infix[] , char postfix[])
{
    int i , j = 0; char ch;
    for(i = 0 ; infix[i] != '\0' ; i ++)
    {
        ch = infix[i];
        if(isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            while(top != -1 && peek()!='(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else if(isOperator(ch))
        {
            while(top != -1 && precedence(peek()) > precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    while(top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

}

int main ()
{
    printf("Enter the infix expression : \n");
    fgets(infix,SIZE,stdin);
    reverse(infix);
    swapParanthesis(infix);
    infixToPostfix(infix , postfix);
    reverse(postfix);
    strcpy(prefix,postfix);
    printf("The prefix expression is : %s\n",prefix);
    return 0 ;
}