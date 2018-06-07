#include "mpi.h"
#include <math.h>
#include <time.h>
#include <stdio.h>


/*
 * *
 * * MPI PI COMPARE FUNCTIONS
 * * Author: Ohad Katz
 * * Date: 5/23/18
 * * 
 * */

double PI25DT= 3.141592653589793238462643;
double ScalarPiCalc(int N) {
    int myid, i, numprocs;
    
    double ScalTime, mypi, pi , h , sum , x;
    clock_t ScalStart;
    ScalStart = clock();
    /*Determine Size of Group */
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    /*Determine Rank of Calling Process */
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    h= 1.0/ (double) N;
    sum = 0.0;
    /*INCREMENTS BY NUMBER OF PROCESSES EACH TIME*/
    /*CALCULATE INTEGRAL*/
    for (i=myid+1; i<=N; i+=numprocs){
        x= h* ((double)i-.5);
        sum += 4.0/(1.0+ x*x);
    }
    mypi= h * sum;
    /*Reduces values into single value, pi*/
    MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (myid==0){
 	ScalTime= ((double) (clock()-ScalStart)/CLOCKS_PER_SEC);

	printf("----------Scalar Pi Calc---------- \n");
        printf("Scalar pi is approx. %.16f \n", pi);
	printf("Time to run Scalar is: %f seconds!\n", ScalTime);
    }
    return pi;
}


double VectorPiCalc(int N) {
    int myid, i, numprocs;
    double VecTime, mypi, pi , h , sum , x;
    clock_t VecStart;
    VecStart = clock();
   
    /*Determine Size of Group */
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    /*Determine Rank of Calling Process */
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    h= 1.0/ (double) N;
    sum = 0.0;
    /*INCREMENTS BY ONE EACH TIME*/
    for (i=0; i<N; i++){
        x= h* ((double)i+.5);
        sum += 4.0/(1.0+ x*x);
    }
    mypi=(h * sum)/numprocs; 

    /*Reduces values into single value, pi*/
    MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (myid==0){
	VecTime = ((double) (clock()-VecStart)/CLOCKS_PER_SEC);
        
        printf("----------Vector Pi Calc----------\n");
	printf("Vector Pi Calculation is approx. %.16f\n", pi);
		
	printf("time to run Vector is = %f seconds \n", VecTime);
    }
    return pi;
}


int main(int argc, char *argv[])
{
    
    int Npoints, Nrepeat, myid, i,numprocs;
    clock_t start;
    clock_t VecStart;
    double cpu_time;
  
    if(argc!=3){
        printf(" Usage: Please select # of Repetitions followed by # of Points:\n");
        return 1;
    }
    Nrepeat=atoi(argv[1]);
    Npoints=atoi(argv[2]);
    MPI_Init(&argc, &argv);


   // for (i=0 ; i <= Nrepeat; i++)
   // {	
//        printf("Iteration #%d\n",i+1);
        ScalarPiCalc(Npoints);
	VectorPiCalc(Npoints);
   // }

    MPI_Finalize();
    return 0;
}


