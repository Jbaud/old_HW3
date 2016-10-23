#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <mpi.h>

int main()
{
    clock_t start, end;
    double timedif,time1;

    int i,j,k,n;
    int align=1;
    int sum=0.0;
    float Matrix[20][20];
    float Vector[20],c;
    int numberOfThreads = -1;


    // the first value of the file is the size of the Matrix 
    scanf("%d",&n);

    for(i=1; i<=n; i++){
        for(j=1; j<=(n+1); j++)
        {
            scanf("%f",&Matrix[i][j]);
        }
    }

    printf("Matrix:\n");

    for(i=1;i<=n;i++)
    {
        for (j = 1; j<=(n+1); j++)
        {
            printf("|%.2f|",Matrix[i][j]);

        }   
        printf("\n");
    }


    // O(n^3)

    for(j=1; j<=n; j++)  
    {
        for(i=j+1; i<=n; i++)
        {

            c=Matrix[i][j]/Matrix[j][j];
            for(k=1; k<=n+1; k++)
            {
                Matrix[i][k]=Matrix[i][k]-c*Matrix[j][k];
            }

        }
    }


    Vector[n]=Matrix[n][n+1]/Matrix[n][n];

    printf("Matrix:\n");
    for(i=1;i<=n;i++)
    {
        for (j = 1; j<=(n+1); j++)
        {
            printf("|%3.2f|",Matrix[i][j]);

        }   
        printf("\n");
    }

    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+Matrix[i][j]*Vector[j];
        }
        Vector[i]=(Matrix[i][n+1]-sum)/Matrix[i][i];
    }
    printf("\nSolutions: \n");
    for(i=1; i<=n; i++)
    {
        printf("%f\n",Vector[i]);
    }
    return 0;
}
