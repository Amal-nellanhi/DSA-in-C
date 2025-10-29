/* PROGRAM TO COUNT THE NODES IN A LINKED LIST */
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data ;
    struct Node* link;
}Node;

Node* head = NULL;

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode ->data = value;
    newNode ->link = NULL;
    return newNode;
}

void insertAtBeginning(int value)
{
        Node*newNode = createNode(value);
        newNode -> link = head;
        head = newNode;
}

void insertAtEnd(int value)
{
        Node*newNode = createNode(value);
        Node*temp = head;
        if(head == NULL)
        {
                head = newNode;
                return;
        }
        while(temp ->link != NULL)
        {
                temp = temp-> link;
        }
        temp -> link = newNode;

}

void insertAtPosition(int value , int pos)
{
        if (pos < 1)
        {
                printf("Invalid position !!\n");
                return;
        }
        if (pos == 1)
        {
                insertAtBeginning(value);
                return;
        }
        Node*newNode = createNode(value);
        Node*temp = head;
        int i = 1;
        while(i< pos - 1 && temp != NULL)
        {
               temp = temp -> link;
               i++; 
        }
        if(temp == NULL)
        {
                printf("Position out of range !\n");
                return;
        }
        newNode -> link = temp -> link;
        temp -> link = newNode; 
}

void deleteAtBeginning()
{
        if(head == NULL)
        {
                printf("List is empty !\n");
                return;
        }
        Node* temp = head;
        head = temp -> link;
        free(temp);
}

void deleteAtEnd()
{
        if(head == NULL)
        {
                printf("List is empty !\n");
                return;
        }
        Node*temp = head;
        if(head -> link == NULL)
        {
                free(head);
                head = NULL;
                return;
        }
        while(temp -> link->link != NULL)
        {
                temp = temp -> link; 
        }
        free(temp -> link);
        temp -> link = NULL;
}

void deleteAtPosition(int pos)
{
        if(head == NULL || pos < 1)
        {
                printf("Invalid Operation\n");
                return;
        }
        if(pos == 1)
        {
                deleteAtBeginning();
        }

        int i = 1;
        Node* temp = head ;
        while(i < pos -1 && temp != NULL)
        {
                temp = temp -> link;
                i++;
        }

        Node* delete = temp -> link ;
        temp -> link = temp -> link -> link;
        free(delete);
        if(temp -> link  == NULL)
        {
                printf("Position out of range !\n");
                return;
        }

}
void display()
{       if(head ==NULL)
        {
                printf("The list is empty !");
        }
        Node* temp = head ;
        while(temp != NULL)
        {
               
                printf("%d  ->  ",temp -> data);
                 temp = temp -> link ;
        } 
        printf("NULL\n");
}
int countNode()
{
    int count = 0;
    if(head == NULL)
        return count;
    else if(head -> link == NULL)
        return 1;
    else
    {
        Node * temp = head;
        while(temp != NULL)
        {
            temp = temp -> link;
            count ++;
        }
        return count;
    }
    
}


int main ()
{
    int value , pos , choice;
    do
    {
        printf("\n___________LINKED LIST MENU____________\n");
        printf(" 1. Insert at beginning\n");
        printf(" 2. Insert at end\n");
        printf(" 3. Insert at position\n");
        printf(" 4. Delete at beginning\n");
        printf(" 5. Delete at end\n");
        printf(" 6. Delete at position\n");
        printf(" 7. Display\n");
        printf(" 8. Count the nodes\n");
        printf(" 9. Exit\n");
        printf("\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
            case 1 :
                    printf("Enter the value : ");
                    scanf("%d",&value);
                    insertAtBeginning(value);
                    break;
            case 2 :
                    printf("Enter the value : ");
                    scanf("%d",&value);
                    insertAtEnd(value);
                    break;
            case 3 :
                    printf("Enter the value : ");
                    scanf("%d",&value);
                    printf("\nEnter the position : ");
                    scanf("%d",&pos);
                    insertAtPosition(value,pos);
                    break;
            case 4 :
                    deleteAtBeginning();
                    break;
            case 5 :
                    deleteAtEnd();
                    break;
            case 6 :
                    printf("\nEnter the position : ");
                    scanf("%d",&pos);
                    deleteAtPosition(pos);
                    break;
            case 7 :
                    display();
                    break;
            case 8 :
                    int count = countNode();
                    printf("No of nodes is %d",count);
                    break;
            case 9 :
                    printf("Exited the program ....!! \n");
                    break;
            default : 
                    printf("Enter a valid choice (1-8)\n");
            
        }

    } while(choice!= 9);
}


