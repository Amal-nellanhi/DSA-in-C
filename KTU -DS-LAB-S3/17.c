/* The CSE dept is organizing a tech fest with so many exciting events. By participating 
in an event, you can claim for activity points as stipulated by KTU. Each event i gives 
you A[i] activity points where A is an array. If you are not allowed to participate in more 
than k events, what’s the max number of points that you can earn?*/

//_________________________________________________________________________________________________________________________________________________________

#include <stdio.h>

// Bubble sort for sorting array in descending order
void sortArray(int n, int arr[]) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int maxActivity(int arr[], int k) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n, k;
    printf("Enter the total number of events: \n");
    scanf("%d", &n);

    int A[n];
    printf("Enter the activity points for events\n");
    for (int i = 0; i < n; i++) {
        printf("Event %d Activity points: ", i + 1);
        scanf("%d", &A[i]);
    }

    sortArray(n, A); // Sorts array in descending order

    printf("Enter the maximum number of events one can participate: \n");
    scanf("%d", &k);

    if (k > n) {
        k = n; 
    }

    int max = maxActivity(A, k);
    printf("Maximum possible activity points for %d events will be: %d\n", k, max);

    return 0;
}