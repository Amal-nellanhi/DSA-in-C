/* PROGRAM TO PERFORM SPARSE POLYNOMIAL ADDITION */
# include <stdio.h>
# include <stdlib.h>
# define SIZE 100

typedef struct Term{
    int coeff;
    int expo;
}Term;
Term terms [SIZE];
int avail = 0;

void readPoly(int * start , int * finish)
{
    int n , coeff , expo;
    printf("Enter the number of terms : \n");
    scanf("%d",&n);
    *start = avail;
    printf("Enter the terms in (coeff , expo)order : \n");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d%d",&coeff,&expo);
        if(avail >= SIZE)
        {
            printf("Term limit exceeeded!!\n");
            return;
        }
        terms[avail].coeff = coeff;
        terms[avail].expo = expo;
        avail++;
    }

    *finish = avail-1;
}
void displayPoly(int start , int finish)
{
    for(int i = start ; i<= finish ; i++)
    {
        if(i > start && terms[i].coeff !=0)
            printf(" + ");
        printf("%d X^ %d",terms[i].coeff , terms[i].expo);
    }
    printf("\n");
}

void addPoly(int startA,int finishA,int startB,int finishB,int *startD,int *finishD)
{
    int i = startA , j = startB;
    *startD = avail;
    while(i<=finishA && j <= finishB)
    {
        if(terms[i].expo == terms[j].expo)
        {
            int sum = terms[i].coeff + terms[j].coeff;
            if(sum != 0)
            {
                terms[avail].coeff = sum;
                terms[avail].expo = terms[i].expo;
                avail ++; 
            }
            i++;j++;
        }
        else if (terms[i].expo > terms[j].expo)
        {
            terms[avail] = terms[i];
            avail ++ ; i ++;
        }
         else
        {
            terms[avail] = terms[j];
            avail ++ ; j ++;
        }
    }
    while(i<= finishA)
    {
        terms[avail] = terms[i];
        avail++ ; i++;
    }
    while(j<= finishB)
    {
        terms[avail] = terms[j];
        avail++ ; j++;
    }
    *finishD = avail -1;
}


int main()
{
    int startA,finishA,startB,finishB,startD,finishD;
    printf("Enter the first polynomial : \n");
    readPoly(&startA , &finishA);

    printf("Enter the second polynomial : \n");
    readPoly(&startB , &finishB);

    addPoly(startA,finishA,startB,finishB,&startD,&finishD);

    printf("The first polynomial : \n");
    displayPoly(startA,finishA);

    printf("The second polynomial : \n");
    displayPoly(startB,finishB);

    printf("The sum is : \n");
    displayPoly(startD,finishD);

    return 0;
}