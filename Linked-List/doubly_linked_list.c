/* PROGRAM TO IMPLEMENT DOUBLY LINKED LIST */
# include <stdio.h>
# include <stdlib.h>
typedef struct Node{
    int data;
    struct Node * left ;
    struct Node * right;
}Node;
Node * head = NULL;

Node * createNode (int value){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}
void insertAtBeginning(int value){
    Node * newNode = createNode(value);
    if(head == NULL){
        head = newNode;
    }
    else{
        newNode -> right = head;
        head -> left = newNode;
        head = newNode;
    }
    printf("%d inserted successfully!\n",value);
}
void insertAtEnd(int value){
    Node * newNode = createNode(value);
    if(head == NULL){
        head = newNode;
    }
    else{
        Node * temp = head;
        while(temp -> right != NULL){
            temp = temp -> right;
        }
        newNode -> left = temp;
        temp -> right = newNode;
    }
    printf("%d inserted successfully!\n",value);
}
void insertAtPosition(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position !!\n");
        return;
    }
    if (head == NULL) {
        if (pos == 1) {
            head = createNode(value);
            printf("%d inserted successfully\n", value);
        } else {
            printf("Invalid position !! List is empty.\n");
        }
        return;
    }
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }
    int i = 1;
    Node *temp = head;
    while (i < pos - 1 && temp->right != NULL) {
        temp = temp->right;
        i++;
    }
    if (temp->right == NULL) {
        insertAtEnd(value);
        return;
    }
    Node *newNode = createNode(value);
    newNode->right = temp->right;
    temp->right->left = newNode;
    newNode->left = temp;
    temp->right = newNode;
    printf("%d inserted successfully\n", value);
}
void display(){
    if(head == NULL){
        printf("List is empty !!\n");
        return;
    }
    else{
        Node * temp = head;
        while(temp != NULL){
            printf("%d <==> ",temp->data);
            temp = temp ->right;
        }
    }
    printf("NULL\n");
}
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty !!\n");
        return;
    }
    Node * temp = head;
    if (head->right == NULL) {
        head = NULL;
    } else {
        head = head->right;
        head->left = NULL;
    }
    free(temp);
    printf("Deleted successfully !!\n");
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty !!\n");
        return;
    }
    if (head->right == NULL) {
        free(head);
        head = NULL;
    } else {
        Node * temp = head;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        temp->left->right = NULL;
        free(temp);
    }
    printf("Deleted successfully !!\n");
}

void deleteFromPosition(int pos) {
    if (pos < 1) {
        printf("Invalid position !!\n");
        return;
    }
    if (head == NULL) {
        printf("List is empty !!\n");
        return;
    }
    if (pos == 1) {
        deleteFromBeginning();
        return;
    }
    int i = 1;
    Node * temp = head;
    while (i < pos - 1 && temp->right != NULL) {
        temp = temp->right;
        i++;
    }
    if (temp->right == NULL) {
        printf("Position out of range !!\n");
        return;
    }
    Node * ptr = temp->right;
    if (ptr->right == NULL) { 
        temp->right = NULL;
    } else {
        ptr->right->left = temp;
        temp->right = ptr->right;
    }
    free(ptr);
    printf("Deleted successfully !!\n");
}
void displayReverse(){
    if(head == NULL){
        printf("List is empty !!\n");
        return;
    }
    Node * temp = head;
        while(temp -> right != NULL){
            temp = temp -> right;
        }
        while(temp != NULL){
            printf("%d <==> ",temp->data);
            temp = temp ->left;
        }
    
    printf("NULL\n");
}
int main(){
    int choice,value,pos;
    do{
        printf("\n_________LIST OPERATIONS MENU_________\n");
        printf("1.Insert at Beginning\n");
        printf("2.Insert at End\n");
        printf("3.Insert at Position\n");
        printf("4.Delete from Beginning\n");
        printf("5.Delete from End\n");
        printf("6.Delete from Position\n");
        printf("7.Display\n");
        printf("8.Display Reverse\n");
        printf("9.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to insert : \n");
                scanf("%d",&value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter the value to insert : \n");
                scanf("%d",&value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter the value to insert : \n");
                scanf("%d",&value);
                printf("Enter the position :\n");
                scanf("%d",&pos);
                insertAtPosition(value,pos);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter the position :\n");
                scanf("%d",&pos);
                deleteFromPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                displayReverse();
                break;
            case 9:
                printf("Exited the Program !!!\n");
                break;
            default :
                printf("Invalid Choice !!!\n");
        }
    }while(choice != 9);
    return 0;
}

