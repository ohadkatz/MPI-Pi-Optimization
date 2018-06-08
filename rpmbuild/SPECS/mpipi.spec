Name:           mpipi
Version: 	.1       
Release:        1%{?dist}
Summary: Pi Calculation with Intel MPI        

License: GPLv3+        
URL: https://github.com/ohadkatz/MPI-Pi-Optimization 
Source0: MPI-Pi-Optimization.tar.gz      

BuildRequires: mpich-3.2-devel  
Requires:mpich-3.2-devel
BuildArch:x86_64

%description
Intel MPI analysis of scalar and vectorized for loops through the calculation of Pi!

%prep



%build
#NEED TO CHANGE THIS TO GLOBAL MACRO
cd $SOURCE/home/ohadkatz/MPI-Pi-Optimization	
make clean
make
./mpipi 3 1231231232 
%files




