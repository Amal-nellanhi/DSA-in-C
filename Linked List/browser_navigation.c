/* PROGRAM TO PERFORM BROWSER NAVIGATION USING DOUBLY LINKED LIST */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char url [200];
    struct Node * prev ;
    struct Node * next ;
}Node;

Node * current = NULL;

Node *createNewNode( char *url){
    Node * newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode -> url , url);
    newNode -> prev = newNode -> next = NULL;
    return newNode; 
}

void visitPage(char *url)
{
    Node * newNode = createNewNode(url);
    if(current != NULL && current -> next != NULL)
    {
        Node * temp = current -> next;
        while(temp!= NULL)
        {
            Node * next = temp -> next;
            free(temp);
            temp = next;
        }
        current -> next = NULL;
    }
    if(current != NULL)
    {
        current -> next = newNode;
        newNode -> prev = current;
    }
    current = newNode;
    printf("Visited %s",url);
}
void goBack()
{
    if(current != NULL && current -> prev !=NULL)
    {
        current = current ->prev;
        printf("Moved back to %s\n",current -> url);
    }
    else
    {
        printf("No previous page !\n ");
    }
}
void goForward()
{
    if(current != NULL && current -> next !=NULL)
    {
        current = current ->next;
        printf("Moved forward to %s\n",current -> url);
    }
    else
    {
        printf("No forward page !\n ");
    }
}
void showCurrent()
{
    if(current != NULL)
    {
        printf("Current page is %s\n",current->url);
    }
    else
        printf("No current page !!\n");
}

void showHistory()
{
   if(current == NULL)
        printf("No history !!");
    
        Node * temp = current ;
        while (temp->prev!=NULL)
        {
            temp = temp -> prev;
        }
        printf("\nBrowsing history !\n");
        while(temp != NULL)
        {
            if(temp == current)
            {
                printf("[%s]\n",temp -> url);
            }
            else{
                printf("%s\n",temp -> url);
            }
            temp = temp -> next;
        }
    
}
int main ()
{
    char url [200];
    int choice ;
    do{
    printf("\n_____________BROWSER MENU____________\n");
    printf("1.Visit page\n");
    printf("2.Back\n");
    printf("3.Forward\n");
    printf("4.Show current page\n");
    printf("5.Show history\n");
    printf("6.Exit\n");
    printf("\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch (choice){
        case 1 :
                printf("Enter the url....\n");
                scanf("%s",url);
                visitPage(url);
                break;
        case 2 :
                goBack();
                break;
        case 3 :
                goForward();
                break;
        case 4 :
                showCurrent();
                break;
        case 5 :
                showHistory();
                break;
        case 6 :
                printf("Exited the Browser !!\n");
                break;
        default : 
                printf("Invalid choice ,enter from (1-6)\n");
                
    }
    

      }while(choice != 6);

      return 0;
}