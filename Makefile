all: progress

progress: progress.o
	mpicc  -o progress progress.o
progress.o: progress.c
	mpicc -c progress.c
clean:
	rm -f  progress.o 
run:
	mpirun -np 4 ./progress