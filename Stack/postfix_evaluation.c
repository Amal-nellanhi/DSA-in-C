/* PROGRAM TO PERFORM POSTFIX EVALUATION */
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <math.h>
# define SIZE 100
double stack [SIZE] ; char postfix[SIZE];
int top = -1;
void push (double x)
{
    if(top >= SIZE-1)
    {
        printf("Stack overflow!!");
        exit(1);
    }
    else
        stack[++top] = x;
}

double pop()
{
   if(top == -1)
   {
    printf("Stack Underflow!!");
    exit(1);
   }
    return stack[top--];
}
double evaluate(char* postfix)
{
    for(int i = 0 ; postfix[i] != '\0' ; i++)
    {
        char ch = postfix[i];

        if(isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            int val2 = pop();
            int val1 = pop();
            switch(ch)
            {
                case '^':
                    push(pow(val1,val2));
                    break;
                case '/':
                    if(val2 == 0)
                    {
                        printf("Zero division error ,Exiting !!");
                        exit(0);
                    }
                    else
                    {
                        push(val1/val2);
                    }
                    break;
                case '+':
                    push(val1 + val2);
                    break;
                case '*':
                    push(val1 * val2);
                    break;
                case '-':
                    push(val1 - val2);
                    break;
            }
        }
    }
    return pop();
}

int main()
{
    printf("Enter the postfix expression : ");
    fgets(postfix,SIZE,stdin);
    postfix[strcspn(postfix,"\n") ] = 0;
    double result = evaluate(postfix);
    printf("The result is : %.2lf\n",result);
    return 0 ;
}
