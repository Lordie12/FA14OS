#ifndef BENCHMARKS_H
#define BENCHMARKS_H

/*---------------------------------------------------------------
Kaushik Kalyanaraman, kkalyana@eng.ucsd.edu

Essential benchmarking function prorotypes and constants declared
here for easy access
---------------------------------------------------------------*/

#include "headers.h"

#define ARR_SIZE 			1024 * 1024 * 1024LL
#define NUM_LOADS 			100
#define CHUNK_SIZE	 		128 * 1024LL
#define ALLOC_SIZE			4096
#define ARR_WRITES 			10
#define NUM_SAMPLES 		10
#define NUM_ITERATIONS 		250000
#define NUM_BLOCK_READS		7500
#define NUM_THREAD_SWITCHES 500

/*----------------------
MACROS for the network
part of project
----------------------*/
#define PORT 			 5000
#define NStoS(X) 		 ((X * 0.000000001))
#define LOOPBACKIP 		 "127.0.0.1"
#define NUM_PACKETS		 250
#define PACKET_SIZE		 1472
#define CALCSIZEBYTES(X) (X * PACKET_SIZE)



/*-------------------------------------------------------------
Function prototypes for CPU operations, Part I of the OS 
systems measurement project
-------------------------------------------------------------*/
vector<longVar> measure_timeOverhead();
longVar measure_threadOverhead();
longVar measure_sysCallOverhead();
longVar measure_processOverhead();
longVar measure_threadContextSwitchOverhead();
longVar measure_threadContextSwitchOverhead();
longVar measure_processContextSwitchOverhead();
void    measure_procCallOverhead(vector<longVar> &result);
longVar measure_loopOverhead(uint iterations=NUM_ITERATIONS);
vector<longVar> measure_FileCacheSize(bool isCacheOn = false);
vector<longVar> measure_SeqFileReadTime();
vector<longVar> measure_RandFileReadTime();
vector<longVar> measure_FileContentionRead();

/*-------------------------------------------------------------
Function prototypes for Memory operations, Part II of the OS
systems measurement project
-------------------------------------------------------------*/
vector<vector<longVar>> measure_memLatency();
longVar 				measure_pageFaultTime();
vector<longVar> 		measure_memReadBandwidth();
vector<longVar> 		measure_memWriteBandwidth();

#endif
