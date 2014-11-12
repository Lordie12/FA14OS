#ifndef BENCHMARKS_H
#define BENCHMARKS_H

/*---------------------------------------------------------------
Kaushik Kalyanaraman, kkalyana@eng.ucsd.edu
Priyanka Ganapathy, pganapat@eng.ucsd.edu

Essential benchmarking function prorotypes and constants declared
here for easy access
---------------------------------------------------------------*/

#include "headers.h"

#define NUM_ITERATIONS 250000
#define NUM_THREAD_SWITCHES 500
#define NUM_LOADS 100
#define NUM_SAMPLES 10
#define ARR_WRITES 10
#define ARR_SIZE 1024*1024*1024LL

/*-------------------------------------------------------------
Function prototypes for CPU operations, Part I of the OS 
systems measurement project
-------------------------------------------------------------*/
longVar measure_timeOverhead();
longVar measure_loopOverhead(uint iterations=NUM_ITERATIONS);
void measure_procCallOverhead(vector<longVar> &result);
longVar measure_sysCallOverhead();
longVar measure_processOverhead();
longVar measure_threadOverhead();
longVar measure_threadContextSwitchOverhead();
longVar measure_processContextSwitchOverhead();
longVar measure_threadContextSwitchOverhead();

/*-------------------------------------------------------------
Function prototypes for Memory operations, Part II of the OS
systems measurement project
-------------------------------------------------------------*/
vector<vector<longVar>> measure_memLatency();
vector<longVar> measure_memWriteBandwidth();
vector<longVar> measure_memReadBandwidth();

#endif
