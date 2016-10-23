#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char  *argv[])
{
	int my_rank,p;
	int i,j;
	int n_size;

	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	printf("this is my rank and this is my p : %d %d \n",my_rank,p);

	if (my_rank == 0)
	{
		//10 lignes 11 colonnes
		double** mat=malloc(10*sizeof(double*)); 
		for(i=0;i<10;++i)
		mat[i]=malloc(11*sizeof(double));

		FILE *file;
		file=fopen("test.txt", "r");

		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 11; j++) 
			{
				
				if (!fscanf(file, "%lf", &mat[i][j])) 
					break;
	
				printf("%lf",mat[i][j]); 
			}
			printf("\n");
		}
		fclose(file);
	}
	MPI_Finalize();
}
