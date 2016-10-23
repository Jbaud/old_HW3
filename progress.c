#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>


/*
We assume that the size n of the matrix % p == 0
*/

int main(int argc, char  *argv[])
{
	int my_rank,p;
	int i,j;
	// the size of the mattrix (without the vector)
	int n_size;

	MPI_Init(&argc, &argv);

	int row,columns;

	row = 4;
	columns =row+1;

	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	//printf("this is my rank and this is my p : %d %d \n",my_rank,p);

	if (my_rank == 0)
	{
		//10 lignes 11 colonnes
		double** mat=malloc(row*sizeof(double*)); 
		for(i=0;i<row;++i)
		mat[i]=malloc(columns*sizeof(double));

		int n_size= row;

		FILE *file;
		file=fopen("test4_4.txt", "r");

		for(i = 0; i < row; i++)
		{
			for(j = 0; j < columns; j++) 
			{
				
				if (!fscanf(file, "%lf", &mat[i][j])) 
					break;
	
				printf("%.1lf ",mat[i][j]); 
			}
			printf("\n");
		}
		fclose(file);

		// we assume n_size%p == 0
		int range = n_size/p;

	// now we want each other process to know the size of the columns
	MPI_Bcast (&n_size, 1, MPI_INT, 0, MPI_COMM_WORLD);

	printf("my rank is %d\n",n_size);
	printf("this is my rank and this is my size : %d %d \n",my_rank,n_size);

	}
	else{

	printf("this is my rank and this is my size : %d %d \n",my_rank,n_size);
	printf("my rank is %d \n",n_size);

	}

	MPI_Finalize();
	return 0;
}
