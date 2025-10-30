/* PROGRAM TO IMPLEMENT DEPTH-FIRST SEARCH IN A GRAPH */ 
#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 20 
typedef struct Node { 
    int data; 
    struct Node* next; 
} Node; 
 
Node* adjList[SIZE];  // Adjacency list 
int visited[SIZE];    // Visited array 
int stack[SIZE]; 
int top = -1; 
void push(int value) { 
    stack[++top] = value; 
} 
int pop() { 
    return stack[top--]; 
} 
int isEmpty() { 
    return top == -1; 
} 
// Function to add edge (undirected) 
void addEdge(int u, int v) { 
    Node* newNode = malloc(sizeof(Node)); 
    newNode->data = v; 
    newNode->next = adjList[u]; 
    adjList[u] = newNode; 
    newNode = malloc(sizeof(Node)); 
    newNode->data = u; 
    newNode->next = adjList[v]; 
    adjList[v] = newNode; 
} 
void printGraph(int vertices) { 
    for (int i = 0; i < vertices; i++) { 
        Node* temp = adjList[i]; 
        printf("Vertex %d:", i); 
        while (temp != NULL) { 
            printf(" -> %d", temp->data); 
            temp = temp->next; 
        } 
        printf("\n"); 
    } 
} 
void dfs(int start) { 
    printf("\nDFS traversal starting from vertex %d: ", start); 
    push(start); 
 
    while (!isEmpty()) { 
        int current = pop(); 
 
        if (!visited[current]) { 
            visited[current] = 1; 
            printf("%d ", current); 
 
            Node* temp = adjList[current]; 
            while (temp != NULL) { 
                int neighbor = temp->data; 
                if (!visited[neighbor]) { 
                    push(neighbor); 
                } 
                temp = temp->next; 
            } 
        } 
    } 
    printf("\n"); 
} 
int main() { 
    int vertices, edges, u, v, start; 
 
    printf("Enter number of vertices: "); 
    scanf("%d", &vertices); 
 
    printf("Enter number of edges: "); 
    scanf("%d", &edges); 
 
    for (int i = 0; i < edges; i++) { 
        printf("Enter edge (u v): "); 
        scanf("%d %d", &u, &v); 
        addEdge(u, v); 
    } 
 
    printf("\nAdjacency List:\n"); 
    printGraph(vertices); 
 
    printf("\nEnter starting vertex for DFS: "); 
    scanf("%d", &start); 
 
    dfs(start); 
 
    return 0; 
} 
