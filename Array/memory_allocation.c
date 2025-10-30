/* PROGRAM TO IMPLEMENT FIRST, BEST AND WORST FIT */ 
#include <stdio.h> 
#define MAX 20 
// Function for First Fit 
void firstFit(int block[], int m, int process[], int n) { 
    int allocation[n]; 
    for (int i = 0; i < n; i++) allocation[i] = -1; 
 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            if (block[j] >= process[i]) { 
                allocation[i] = j; 
                block[j] -= process[i]; 
                break; 
            } 
        } 
    } 
    printf("\nFirst Fit Allocation:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("Process %d (Size %d) --> ", i + 1, process[i]); 
        if (allocation[i] != -1) 
            printf("Block %d\n", allocation[i] + 1); 
        else 
            printf("Not Allocated\n"); 
    } 
} 
// Function for Best Fit 
void bestFit(int block[], int m, int process[], int n) { 
    int allocation[n]; 
    for (int i = 0; i < n; i++) allocation[i] = -1; 
    for (int i = 0; i < n; i++) { 
        int bestIdx = -1; 
        for (int j = 0; j < m; j++) { 
            if (block[j] >= process[i]) { 
                if (bestIdx == -1 || block[j] < block[bestIdx]) { 
                    bestIdx = j; 
                } 
            } 
        } 
        if (bestIdx != -1) { 
            allocation[i] = bestIdx; 
            block[bestIdx] -= process[i]; 
        } 
    } 
    printf("\nBest Fit Allocation:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("Process %d (Size %d) --> ", i + 1, process[i]); 
        if (allocation[i] != -1) 
            printf("Block %d\n", allocation[i] + 1); 
        else 
            printf("Not Allocated\n"); 
    } 
} 
// Function for Worst Fit 
void worstFit(int block[], int m, int process[], int n) { 
    int allocation[n]; 
    for (int i = 0; i < n; i++) allocation[i] = -1; 
 
    for (int i = 0; i < n; i++) { 
        int worstIdx = -1; 
        for (int j = 0; j < m; j++) { 
            if (block[j] >= process[i]) { 
               if (worstIdx == -1 || block[j] > block[worstIdx]) 
                    worstIdx = j; 
            } 
        } 
        if (worstIdx != -1) { 
            allocation[i] = worstIdx; 
            block[worstIdx] -= process[i]; 
        } 
    } 
    printf("\nWorst Fit Allocation:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("Process %d (Size %d) --> ", i + 1, process[i]); 
        if (allocation[i] != -1) 
            printf("Block %d\n", allocation[i] + 1); 
        else 
            printf("Not Allocated\n"); 
    } 
} 
int main() { 
    int m, n; 
    int block[MAX], process[MAX]; 
    printf("Enter number of memory blocks: "); 
    scanf("%d", &m); 
    printf("Enter size of each block:\n"); 
    for (int i = 0; i < m; i++) { 
        printf("Block %d: ", i + 1); 
        scanf("%d", &block[i]); 
    } 
    printf("\nEnter number of processes: "); 
    scanf("%d", &n); 
    printf("Enter size of each process:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("Process %d: ", i + 1); 
        scanf("%d", &process[i]); 
    } 
    int block1[MAX], block2[MAX], block3[MAX]; 
    for (int i = 0; i < m; i++) { 
        block1[i] = block[i]; 
        block2[i] = block[i]; 
        block3[i] = block[i]; 
    } 
    firstFit(block1, m, process, n); 
    bestFit(block2, m, process, n); 
    worstFit(block3, m, process, n); 
    return 0; 
}