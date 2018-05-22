# MPI-Pi-Optimization
Finding pi using MPI methods in two ways in order to demonstrate how to achieve faster performance with HPC/Clusters
mpipic.c will use scalar arithmetic wheras mpioptimizedpi.c uses floating point arithmetic with vectors in order to achieve significantly faster speeds.

## Included
Makefile: compile mpipi.c and mpioptimizedpi.c 

Batch Script: Used to run on HPC compute nodes instead of head nodes when testing efficiency

pi: sample binary file

## Preliminary Installation
To start working with code, you msut first have both intel and intel-mpi downloaded on your path.
With these, we can use the mpiicc compiler to run our code!

Also include batch script which works with Slurm Workload Manager in order to configure specific core usages on computer clusters.
     Included in this binary is where you can configure the partition, number of nodes, time needed and constraints.
     Leaving any of these blanks will reset the values to default.
     
                  #SBATCH --partion= _____
                  
                  #SBATCH --time=______ 
                  
                  #SBATCH --nodes=_____
                  
                  #SBATCH --ntasks-per-node= _____ 
                  
                  #SBATCH --constraint=______ 
## To Run Code
Remove Binary file (pi)
Must have both intel AND intel-MPI paths included to begin.
To run first run:

          -mpiicc -o NAME_OF_BINARY mpipi.c

This will compile our code 
Next, you have two options to run the code:
          
          1.) mpirun -np #of_cores_you_want_to_use ./BINARY_FILE
          2.) ./BINARY_FILE
          NOTE: IF USING SLURM YOU CAN USE
            -sbatch batch.sh
          
      
