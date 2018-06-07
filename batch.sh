#!/bin/bash
#SBATCH --partition=debug
#SBATCH --time=00:15:00
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=2
#SBATCH --constraint=IB

srun hostname
module load intel-mpi
export I_MPI_PMI_LIBRARY=/usr/lib64/libpmi.so
echo $SLURM_NPROCS
time srun -n $SLURM_NPROCS ./MPITEST


