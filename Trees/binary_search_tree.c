/* PROGRAM TO IMPLEMENT A BST */
# include <stdio.h>
# include<stdlib.h>

typedef struct Node {
    int data ;
    struct Node * left , *right;
}Node;

Node * createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

Node* insertNode(Node *root , int value)
{
    if(root ==NULL)
    {
        return createNode(value);
    }
    else if(value < root -> data)
    {
        root ->left = insertNode(root->left , value);
    }
    else if (value > root -> data)
    {
        root -> right = insertNode(root ->right , value);
    }
    return root;
}

Node *findMin(Node * node)
{
    while(node && node -> left != NULL)
        node = node ->left;
    return node;
}
Node * deleteNode(Node* root , int value)
{
    if(root == NULL)
    {
        return root;
    }
    else if (value < root -> data)
    {
        root -> left = deleteNode(root->left , value);
    }
    else if (value > root -> data)
    {
        root -> right = deleteNode(root->right , value);
    }
    else
    {
        if(root ->left == NULL && root ->right ==NULL)
        {
            free(root);
            return NULL;
        }
        else if(root -> left ==NULL)
        {
            Node * temp = root ->right ;
            free(root);
            return temp;
        }
        else if(root -> right ==NULL)
        {
            Node * temp = root ->left ;
            free(root);
            return temp;
        }
        else
        {
            Node * temp = findMin( root-> right);
            root -> data = temp ->data;
            root ->right = deleteNode(root->right ,temp ->data);
        }
    }
    return root;
}

void inorder(Node * root)
{
    if(root)
    {
        inorder(root -> left);
        printf("%d  ",root -> data);
        inorder(root -> right);
    }
}
void preorder(Node * root)
{
    if(root)
    {
        printf("%d  ",root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void postorder(Node * root)
{
    if(root)
    {
        postorder(root -> left);
        postorder(root -> right);
        printf("%d  ",root -> data);
    }
}
int main() { 
    Node* root = NULL; 
    int choice, value; 
    do { 
        printf("\n\n--- Binary Search Tree Operations ---\n"); 
        printf("1. Insert\n"); 
        printf("2. Delete\n"); 
        printf("3. Inorder Traversal\n"); 
        printf("4. Preorder Traversal\n"); 
        printf("5. Postorder Traversal\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                printf("Enter value to insert: "); 
                scanf("%d", &value); 
                root = insertNode(root, value); 
                printf("%d inserted successfully.\n", value); 
                break; 
            case 2: 
                printf("Enter value to delete: "); 
                scanf("%d", &value); 
                root = deleteNode(root, value); 
                printf("%d deleted (if present).\n", value); 
                break; 
            case 3: 
                printf("Inorder Traversal: "); 
                inorder(root); 
                printf("\n"); 
                break; 
            case 4: 
                printf("Preorder Traversal: "); 
                preorder(root); 
                printf("\n"); 
                break; 
            case 5: 
                printf("Postorder Traversal: "); 
                postorder(root); 
                printf("\n"); 
                break; 
            case 6: 
                printf("Exiting program.\n"); 
                break; 
            default: 
                printf("Invalid choice! Try again.\n"); 
        } 
    } while (choice != 6); 
    return 0; 
}