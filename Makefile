ALL: pi
SHELL = /bin/sh
DIRS =
pi: MPIoptimizedpi.c
		mpicc -g -w -O3 -o mpipi  MPIoptimizedpi.c -lm
		mpicc -g -w -O3 -o PiBinary  MPIoptimizedpi.c -lm

profile.alog:  MPIoptimizedpi.c
	mpicc -w -o mpipi.log -mpilog  MPIoptimizedpi.c -lm
	mpirun -np 4 mpipi.log
	/bin/mv mpipi.log_prifile.log profile.alog
clean:
	/bin/rm -f mpipi.o mpipi.log
	#for dir in $(DIRS) ;  do \
	# (cd $$dir ; make clean) ; done
