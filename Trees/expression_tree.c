#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 100

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node* createNode(char ch) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ch;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* stack[SIZE];
int top = -1;

void push(Node* node) {
    stack[++top] = node;
}

Node* pop() {
    if (top == -1) {
        printf("Stack underflow! Invalid expression.\n");
        exit(1);
    }
    return stack[top--];
}

int isOperator(char ch) {
    return (ch == '^' || ch == '/' || ch == '*' || ch == '+' || ch == '-');
}

Node* createTree(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isalnum(ch)) {
            push(createNode(ch));
        } else if (isOperator(ch)) {
            Node* newNode = createNode(ch);
            newNode->right = pop();
            newNode->left = pop();
            push(newNode);
        }
    }
    return pop();
}

void inorder(Node* root) {
    if (root) {
        if (isOperator(root->data)) printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if (isOperator(root->data)) printf(")");
    }
}

void preorder(Node* root) {
    if (root) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main() {
    char postfix[SIZE];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    Node* root = createTree(postfix);
    printf("The Inorder is:\n");
    inorder(root);
    printf("\n");
    printf("The Preorder is:\n");
    preorder(root);
    printf("\n");
    printf("The Postorder is:\n");
    postorder(root);
    return 0;
}