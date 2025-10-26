/* PROGRAM TO IMPLEMENT A BINARY TREE */
# include <stdio.h>
# include <stdlib.h>
typedef struct Node
{
    int data ;
    struct Node * left ;
    struct Node * right ;

}Node;

Node * createNode (int data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data ;
    newNode -> left = newNode -> right = NULL;
    return newNode; 
}
Node * createTree()
{
    int data ;
    printf("Enter the data (-1 for no value) : \n");
    scanf("%d",&data);
    if(data == -1)
    {
        return NULL;
    }
    Node * newNode = createNode(data);

    printf("Enter the left child of %d\n",data);
    newNode -> left = createTree();

    printf("Enter the right child of %d\n",data);
    newNode -> right = createTree();

    return newNode;
}

int findDepth(Node * node)
{
    if(node == NULL)
        return 0;
    int leftDepth = findDepth(node -> left);
    int rightDepth = findDepth(node -> right);
    if(leftDepth >= rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;

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

int main()
{
    Node * root = NULL; int depth ;

    printf("Create the binary tree \n");
    root = createTree();
    printf("\n");

     printf("The Inorder is : \n");
    inorder(root);
    printf("\n");
    printf("The Preorder is : \n");
    preorder(root);
    printf("\n");

    printf("The Postorder is : \n");
    postorder(root);

    printf("\n");
    depth = findDepth(root);
    printf("The depth is %d",depth);

    return 0 ;

}