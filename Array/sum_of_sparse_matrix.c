#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Term {
    int row;
    int col;
    int val;
} Term;

Term mat1[MAX], mat2[MAX], result[MAX];

void readMatrix(Term mat[], int *size) {
    printf("Enter the number of (rows, cols, value):\n");
    scanf("%d%d%d", &mat[0].row, &mat[0].col, &mat[0].val);
    printf("Enter the non-zero elements (row, col, val):\n");
    for (int i = 1; i <= mat[0].val; i++) {
        scanf("%d%d%d", &mat[i].row, &mat[i].col, &mat[i].val);
    }
    *size = mat[0].val + 1;
}

void displayMatrix(Term mat[], int size) {
    printf("ROW  COL  VAL\n");
    for (int i = 0; i < size; i++) {
        printf("%d    %d   %d\n", mat[i].row, mat[i].col, mat[i].val);
    }
}

void addMatrix(Term mat1[], Term mat2[], Term result[], int size1, int size2, int *sizeR) {
    if (mat1[0].row != mat2[0].row || mat1[0].col != mat2[0].col) {
        printf("Matrix dimensions do not match. Cannot add.\n");
        *sizeR = 0;
        return;
    }

    result[0].row = mat1[0].row;
    result[0].col = mat1[0].col;
    int i = 1, j = 1, k = 1;

    while (i < size1 && j < size2) {
        if (mat1[i].row == mat2[j].row && mat1[i].col == mat2[j].col) {
            int sum = mat1[i].val + mat2[j].val;
            if (sum != 0) {
                result[k].row = mat1[i].row;
                result[k].col = mat1[i].col;
                result[k].val = sum;
                k++;
            }
            i++; j++;
        } else if (mat1[i].row < mat2[j].row || 
                  (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
            result[k++] = mat1[i++];
        } else {
            result[k++] = mat2[j++];
        }
    }

    while (i < size1) result[k++] = mat1[i++];
    while (j < size2) result[k++] = mat2[j++];

    result[0].val = k - 1;
    *sizeR = k;
}

int main() {
    int size1, size2, sizeR;

    printf("Enter first matrix:\n");
    readMatrix(mat1, &size1);

    printf("Enter second matrix:\n");
    readMatrix(mat2, &size2);

    addMatrix(mat1, mat2, result, size1, size2, &sizeR);

    if (sizeR > 0) {
        printf("First matrix:\n");
        displayMatrix(mat1, size1);

        printf("Second matrix:\n");
        displayMatrix(mat2, size2);

        printf("Resultant matrix after addition:\n");
        displayMatrix(result, sizeR);
    }

    return 0;
}