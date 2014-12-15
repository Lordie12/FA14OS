FALL 2014 OS Project, A Microbenchmarking System
UCSD Department of Computer Science

Figures/ has the results, plots, csv files for all the graphs + tables generated
NetRes/ has results for some of the networking Experiments
OP1-CPU/ has all the basic implementations
  - benchmarks.cpp has all the implementations of the various functions except networking
  - benchmarks.h has various constants, function prototypes and a few helpful macros
  - benchmarks.s is the corresponding assembly file used for inspecting assembly
  - headers.h has all the necessary headers and imported namespace functions
  - main.cpp is the main driver program which calls into functions exported by benchmarks.cpp and by loopTCPServer and loopTCPClient
  - main.s is the assembly file of main.cpp for inspecting assembly
  - loopTCPServer and loopTCPClient are used to measure the network information
  - Makefile is the custom makefile used to compile, build and run
  - Files/ should contain a list of files used for sequential R/W and random R/W measurement
    - files.sh in this folder is used to generate the files
  - ThreadFiles/ should contain a list of 32 files of type *.dat of size 32M each
    - tFiles.sh is used to generate these ThreadFiles

Main.cpp calls into these script files using the system() command, hopefully this shouldn't be needed but can never hurt to be sure that these files exist before running the corresponding benchmarks
WIN-TM0LECOFHH7.txt is the spec sheet for the hardware configurataion (reported using CPU-Z on Windows)
