/* PROGRAM TO FIND TRANSPOSE OF A SPARSE MATRIX */
# include <stdio.h>
# include <stdlib.h>
# define MAX 100
typedef struct Term{
    int row;
    int col;
    int val;
}Term;
Term mat[MAX] , trans[MAX];

void readMatrix(Term mat[] , int * size)
{
    printf("Enter the number of (rows , cols ,value) \n");
    scanf("%d%d%d",&mat[0].row ,&mat[0].col ,&mat[0].val);
    printf("Enter the non-zero elements(row,col,val) : \n");
    for(int i = 1 ; i <= mat[0].val ; i++)
    {
        scanf("%d%d%d",&mat[i].row,&mat[i].col,&mat[i].val);
    }
    *size = mat[0].val + 1;
}

void displayMatrix(Term mat[] ,int size)
{
printf("ROW  COL  VAL  \n");
for(int i = 0 ; i<size ; i++)
{
    printf("%d    %d   %d\n",mat[i].row,mat[i].col,mat[i].val);
}
}
void transpose(Term mat[], Term trans[])
{
    int k = 1;
    trans[0].row = mat[0].col;
    trans[0].col = mat[0].row;
    trans[0].val = mat[0].val;
    for(int i = 0 ; i < mat[0].col; i++)
    {
        for(int j = 1 ; j <= mat[0].val ; j++)
        {
            if(mat[j].col == i)
            {
                trans[k].row = mat[j].col;
                trans[k].col = mat[j].row;
                trans[k].val = mat[j].val;
                k++;
            }
        }
    }
}


int main()
{
    int size ;
    readMatrix(mat,&size);
    printf("The original matrix : \n");
    displayMatrix(mat ,size);

    transpose(mat,trans);

    printf("The transposed matrix : \n");
    displayMatrix(trans ,size);

    return 0;
}