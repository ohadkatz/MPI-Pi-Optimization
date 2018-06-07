ALL: pi
SHELL = /bin/sh
DIRS =
pi: mpipi.c
	mpicc -g -O3 -o mpipi mpipi.c -lm
profile.alog: pi.c
	mpicc -o pi.log -mpilog pi.c -lm
	mpirun -np 4 pi.log
	/bin/mv pi.log_prifile.log profile.alog
clean:
	/bin/rm -f pi.o pi.log
	#for dir in $(DIRS) ;  do \
	# (cd $$dir ; make clean) ; done
