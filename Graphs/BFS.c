/* PROGRAM TO IMPLEMENT BFS */
/* PROGRAM TO IMPLEMENT BREADTH-FIRST SEARCH IN A GRAPH */ 
#include <stdio.h> 
#include <stdlib.h> 
#define SIZE 20 
typedef struct Node { 
    int data; 
    struct Node* next; 
} Node; 
 
Node* adjList[SIZE];  // Adjacency list 
int visited[SIZE];    // Visited array for BFS 
int queue[SIZE], front = 0, rear = -1; 
 
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
void enqueue(int value) { 
    queue[++rear] = value; 
} 
int dequeue() { 
    return queue[front++]; 
} 
void bfs(int start) { 
    printf("\nBFS traversal starting from vertex %d: ", start); 
    visited[start] = 1; 
    enqueue(start); 
    while (front <= rear) { 
        int current = dequeue(); 
        printf("%d ", current); 
 
        Node* temp = adjList[current]; 
        while (temp != NULL) { 
            int neighbor = temp->data; 
            if (!visited[neighbor]) { 
                visited[neighbor] = 1; 
                enqueue(neighbor); 
            } 
            temp = temp->next; 
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
    printf("\nEnter starting vertex for BFS: "); 
    scanf("%d", &start); 
    bfs(start); 
    return 0; 
}