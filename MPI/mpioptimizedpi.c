#include "mpi.h"
#include <math.h>
#include <time.h>
#include <stdio.h>


/*
*
* MPI PI COMPARE FUNCTIONS
* Author: Ohad Katz
* Date: 5/23/18
* 
*/

double ScalarPiCalc(int N) {
    int myid, i, numprocs;
    
    double ScalTime, mypi, pi , h , sum , x;
    clock_t ScalStart= clock();
    /*Determine Size of Group */
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    /*Determine Rank of Calling Process */
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    h= 1.0/ (double) N;
    sum = 0.0;
    printf("Scalar Pi Calc\n");
    /*INCREMENTS BY NUMBER OF PROCESSES EACH TIME*/
    /*CALCULATE INTEGRAL*/
    for (i=myid+1; i<=N; i+=numprocs){
        x= h* ((double)i+.5);
        sum += 4.0/(1.0+ x*x);
    }
    mypi= h * sum;
    /*Reduces values into single value, pi*/
    MPI_REDUCE(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (myid==0){
        ScalTime= ((double) (clock()-ScalStart)/CLOCKS_PER_SEC);

        printf("Scalar pi is approx. %.16f , Error is %.16f\n", pi, fabs(pi-PI25DT));
        printf("Time to run Scalar Pi Calculation= %f\n", ScalTime);

    }
    return pi;
}


double VectorPiCalc(int N) {
    int myid, i, numprocs;
    double PI25DT= 3.141592653589793238462643;
    double VecTime, mypi, pi , h , sum , x;
    clock_t VecStart= clock();
    /*Determine Size of Group */
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    /*Determine Rank of Calling Process */
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    h= 1.0/ (double) N;
    sum = 0.0;
    printf("Vector Pi Calc\n");
    /*INCREMENTS BY ONE EACH TIME*/
    for (i=0; i<N; i++){
        printf("in vector pi for loop\n");
        x= h* ((double)i+.5);
        sum += 4.0/(1.0+ x*x);
    }
    mypi= h * sum;

    /*Reduces values into single value, pi*/
    MPI_REDUCE(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (myid==0){
        VecTime = ((double) (clock()-VecStart)/CLOCKS_PER_SEC);
        printf("Vector Pi Calculation is approx. %.16f , Error is %.16f\n", pi, fabs(pi-PI25DT));
        printf("Time to Run Vector Pi Calculation=%f\n", VecTime);
    }
    return pi;
}


int main(int argc, char *argv[])
{
    int Npoints,Nrepeat, myid, i,numprocs;
    double cpu_time;
    printf("Please select # of Repetitions followed by # of Points:");
    scanf("%d%d", &Nrepeat, &Npoints);
    MPI_Init(&argc, &argv);

    for (i=0 ; i <= Nrepeat+1; i++)
    {
        printf("Iteration #%d\n",i);
        ScalarPiCalc(Npoints);
        VectorPiCalc(Npoints);
    }
    MPI_Finalize();
    return 0;
}

