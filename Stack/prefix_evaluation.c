/* PROGRAM TO PERFORM PREFIX EVALUATION */
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <math.h>
# include <string.h>
# define SIZE 100
double stack [SIZE] ; char prefix[SIZE];
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

void reverse(char * array)
{
    char temp; int n = strlen(array);
    for(int i = 0 ; i < n/2 ; i ++)
    {
        temp = array[i];
        array[i] = array[n-i-1];
        array[n-i-1] = temp ;
    }

}
double evaluate(char* prefix)
{
    char* token = strtok(prefix," ");
    while(token != NULL)
    {
        if(isdigit(token[0]) || (token[0]== '-' && isdigit(token[1])))
            push(atof(token));
        else if (strlen(token) == 1)
        {
            double val1 = pop();
            double val2 = pop();
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
    printf("Enter the prefix expression : ");
    fgets(prefix,SIZE,stdin);
    prefix[strcspn(prefix,"\n") ] = '\0';
    reverse(prefix);
    double result = evaluate(prefix);
    printf("The result is : %.2lf\n",result);
    return 0 ;
}
