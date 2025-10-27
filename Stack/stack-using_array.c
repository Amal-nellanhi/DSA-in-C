/* PROGRAM TO IMPLEMENT STACK USING ARRAY */
# include <stdio.h>
# include <stdlib.h>
# define SIZE 5
int stack[SIZE], top = -1;

void push (int value)
{
    if(top == SIZE -1)
        printf("Stack Overflow !!\n");
    else
    {
        stack[++top] = value;
        printf("%d pushed into stack\n",value);
    }
}

void pop()
{
    if(top == -1)
        printf("Stack underflow !!\n");
    else
    {
        printf("%d popped from stack\n",stack[top--]);
    }
}
void display()
{
    if(top == -1)
        printf("The stack is empty !\n");
    else
    {
        printf("Stack contents from top to bottom \n");
        for(int i = top ; i >= 0 ; i --)
            printf("%d\n",stack[i]);
    }

}
int main ()
{
    int choice ,value;
    do
    {
        printf("\n____STACK MENU____\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice : \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                    printf("Enter the value to push :\n");
                    scanf("%d",&value);
                    push(value);
                    break;
            case 2:
                    pop();
                    break;
            case 3 :
                    display();
                    break;
            case 4:
                    printf("Exited the program 😭😭");
                    break;
        }
    }while(choice != 4);
    return 0;
}

