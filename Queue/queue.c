/* PROGRAM TO IMPLEMENT A QUEUE USING ARRAY*/
# include <stdio.h>
# define SIZE 100
int queue[SIZE],front = -1, rear = -1;
void enqueue(int value)
{
    if(rear == SIZE -1)
    {
        printf("Queue is full !!");
        return;
    }
    if(front == -1)
        front = 0;
    queue[++rear] = value;
    printf("%d inserted into queue",value);
}
void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is empty !!");
        return;
    }
    printf("%d deleted from queue",queue[front++]);
}
void display()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is empty !!");
        return;
    }
    for(int i = front ; i<= rear ; i++)
    {
        printf("%d  ",queue[i]);
    }
    printf("\n");
}

int main() { 
    int choice, value; 
    do { 
        printf("\nQueue Operations:\n"); 
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
        case 1: 
            printf("Enter value to insert: "); 
            scanf("%d", &value); 
            enqueue(value); 
            break; 
        case 2: 
            dequeue(); 
            break; 
        case 3: 
            display(); 
            break; 
        case 4: 
            printf("Exiting program.\n"); 
            break; 
        default: 
            printf("Invalid choice. Try again.\n"); 
        } 
    } while (choice != 4);  
 
    return 0; 
} 
 
