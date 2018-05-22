#include "mpi.h"
#include <math.h>
#include <time.h>
#include <stdio.h>


double PiCalc(N) {
    int n= 10000000000;
    double PI25DT= 3.141592653589793238462643;
    double mypi, pi , h , sum , x;
    start= clock();
    MPI_Comm_size(MPI_COMM_WORLD, N);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    h= 1.0/ (double) n;
    sum = 0.0;
    for (i=myid+1; i<=N; i++){
        x= h* ((double)i-.5);
        sum += 4.0/(1.0+ x*x);
    }
    mypi= h * sum;
    MPI_REDUCE(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
}


int main(argc,argv, Npoints, Nrepeat){
    int arg;
    int *argv[];
    int Npoints;
    int Nrepeat;
    int arr[Npoints];
    MPI_init(&argc, &argv);
    
    for (i=0 ; i <= Nrepeat; i++){
        start= clock()
        double pi = PiCalc(Npoints);
        cpu_time= ((double) (clock()-start)/CLOCKS_PER_SEC);
        printf("At iteration: %d, we get pi = %f , with %d processes,  in %f time! ", i, pi, Npoints, cpu_time);
    }

    MPI_Finalize();
    return 0;
}
