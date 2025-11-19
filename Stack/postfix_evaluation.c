/* PROGRAM TO PERFORM POSTFIX EVALUATION */
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <math.h>
# include <string.h>
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
    char* token = strtok(postfix," ");
    while(token != NULL)
    {
        if(isdigit(token[0]) || (token[0]== '-' && isdigit(token[1])))
            push(atof(token));
        else if (strlen(token) == 1)
        {
            double val2 = pop();
            double val1 = pop();
            switch(token[0])
            {
                case '^':
                    push(pow(val1,val2));
                    break;
                case '/':
                    if(val2 == 0)
                    {
                        printf("Zero division error ,Exiting !!");
                        exit(1);
                    }
                    else
                    {
                        push(val1/val2);
                    }
                    break;
                 case '%':
                    if(val2 == 0)
                    {
                        printf("Zero division error ,Exiting !!");
                        exit(1);
                    }
                    else
                    {
                        int a = (int)val1;
                        int b = (int)val2;
                        push(a%b);
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
                default:
                    printf("Invalid operator , exiting !");
                    exit(1);
            }
        }
        else
        {
            printf("Invalid token,Exiting!!");
            exit(1);
        }
        token = strtok(NULL," ");
        }
        double result = pop();
        if(top != -1)
        {
            printf("Invalid expression !!");
            exit(1);
        }

        return result;

}

int main()
{
    printf("Enter the postfix expression : ");
    fgets(postfix,SIZE,stdin);
    postfix[strcspn(postfix,"\n") ] = '\0';
    double result = evaluate(postfix);
    printf("The result is : %.2lf\n",result);
    return 0 ;
}
