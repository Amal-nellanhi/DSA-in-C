# include <stdio.h>
# include <stdlib.h>
# define SIZE 100

char stack[SIZE], arr[SIZE];
int top = -1;

void push(char item){
    if(top == SIZE -1){
        printf("Stack Overflow !! Cannot push\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = item;
}

void pop(){
    if(top == -1){
        printf("Stack underflow !!\n");
        exit(EXIT_FAILURE);
    }
    top--;
}

int isEmpty(){
    return (top == -1);
}

char peek(){
    return stack[top];
}

char matching_pair(char item){
    if(item == ')') return '(';
    if(item == ']') return '[';
    if(item == '}') return '{';
    return '\0';
}

void checkParantheses(){
    top = -1;  // reset stack

    for(int i = 0 ; arr[i] != '\0' ; i++){
        if(arr[i] == '(' || arr[i] == '[' || arr[i] == '{'){
            push(arr[i]);
        }
        else if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}'){
            if(isEmpty() || matching_pair(arr[i]) != peek()){
                printf("UNBALANCED\n");
                return;
            }
            pop();
        }
    }

    if(isEmpty())
        printf("BALANCED\n");
    else
        printf("UNBALANCED\n");
}

int main(){
    printf("Enter the parentheses expression:\n");
    fgets(arr, SIZE, stdin);
    checkParantheses();
    return 0;
}