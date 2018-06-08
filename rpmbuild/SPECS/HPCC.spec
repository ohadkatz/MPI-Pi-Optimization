Name:           HPCC
Version:	.1        
Release:        1%{?dist}
Summary:        DGEMM Benchmark Test

License:       GPLv3+ 
URL:           https://github.com/ohadkatz/HPCC 
Source0:       HPCC.tar.gz

BuildRequires: mpich-3.2-devel  
Requires:      mpich-3.2 
ExclusiveArch: x86_64

%description
User input DGEMM Benchmark used to analyze GFLOP based on load. 

%prep
%setup -q

%build
cd /home/ohadkatz/HPCC
make arch=intel64_desktop 
mpirun -n 1 ./hpcc

%install


%files

%clean
echo All Done

