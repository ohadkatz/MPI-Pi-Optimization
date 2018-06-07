Name:           MPIoptimization
Version:	.1        
Release:        1%{?dist}
Summary:        MPI pi vector vs scaled optimization

License:       GPLv3+ 
URL:           https://github.com/ohadkatz/MPI-Pi-Optimization 
Source0:       MPI-Pi-Optimization.tar.gz

BuildRequires: mpich-3.2-devel  
Requires:      mpich-3.2 
ExclusiveArch: x86_64
%description
MPI Pi Calculation analysis of static and vectorized for loops

%prep
%setup -q


%build
cd /home/ohadkatz/MPI-Pi-Optimization
make 
./mpicc 0 1131221


%install


%files

%clean
echo All Done

