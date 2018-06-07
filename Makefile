ALL: pi
SHELL = /bin/sh
DIRS =
pi: mpipi.c
<<<<<<< HEAD:Makefile
	mpicc -g -O3 -o mpipi mpipi.c -lm
=======
	mpicc -g -O3 -o PiBinary mpipi.c -lm
>>>>>>> f7ff80bb10067ec8a2e199eed39190ff9610102a:MPI/Makefile
profile.alog: pi.c
	mpicc -o mpipi.log -mpilog mpipi.c -lm
	mpirun -np 4 mpipi.log
	/bin/mv mpipi.log_prifile.log profile.alog
clean:
	/bin/rm -f mpipi.o mpipi.log
	#for dir in $(DIRS) ;  do \
	# (cd $$dir ; make clean) ; done
