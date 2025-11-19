/* PROGRAM TO CONVERT INFIX EXPRESSION TO POSTFIX EXPRESSION */
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# define SIZE 100
char stack [SIZE] , infix[SIZE], postfix[SIZE];
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
    return (ch == '^' ||ch == '/' ||ch == '*' ||ch == '+' ||ch == '-'|| ch =='%');
}

int precedence(char ch)
{
    switch (ch)
    {
        case '^':
                return 3;
        case '/':
        case '*':
        case '%':
                return 2;
        case '+':
        case '-':
                return 1;
        default:
                return 0; 
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
            while(top != -1 && precedence(peek()) >= precedence(ch))
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
    scanf("%s",infix);
    infixToPostfix(infix , postfix);
    printf("The postfix expression is : %s\n",postfix);
    return 0 ;
}