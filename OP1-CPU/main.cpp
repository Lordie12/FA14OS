#include "benchmarks.h"

/*---------------------------------------------------------------
Kaushik Kalyanaraman, kkalyana@eng.ucsd.edu
Priyanka Ganapathy, pganapat@eng.ucsd.edu

The primary driver program to test all benchmarks
---------------------------------------------------------------*/

int sample()
{
	/*-----------------------------------------------------------------
					     Overhead in measuring time
	-----------------------------------------------------------------*/
	longVar mesTimeOverhead = measure_timeOverhead();
	cout<<"Overhead of reading time, over "<<NUM_ITERATIONS<<" iterations:"<<mesTimeOverhead<<"ns"<<endl;

	/*-----------------------------------------------------------------
						     Overhead of a loop
	-----------------------------------------------------------------*/
	longVar mesLoopOverhead = measure_loopOverhead();
	cout<<"Overhead of a loop, over "<<NUM_ITERATIONS<<" iterations:"<<mesLoopOverhead<<"ns"<<endl;

	/*-----------------------------------------------------------------
	          Overhead in procedure calls of different lengths
	-----------------------------------------------------------------*/
	vector<longVar> procOverhead;
	int count = 0;
	measure_procCallOverhead(procOverhead);
	cout<<"Overhead for procedure calls, over "<<NUM_ITERATIONS<<" iterations: "<<endl;
	for (auto it: procOverhead)
		cout<<"Procedure with "<<count++<<" arguments: "<<it<<" ns"<<endl;

	/*-----------------------------------------------------------------
	          			 Overhead for system call
	-----------------------------------------------------------------*/
	longVar syscallOverhead = measure_sysCallOverhead();
	cout<<"Overhead for system call stat(), over "<<NUM_ITERATIONS<<" iteration: "<<syscallOverhead<<" ns"<<endl;

	/*-----------------------------------------------------------------
	          Overhead for a single process creation and run
	-----------------------------------------------------------------*/
	longVar processOverhead = measure_processOverhead();
	cout<<"Overhead for creating and running a single process is: "<<processOverhead<<" us"<<endl;

	/*-----------------------------------------------------------------
	          Overhead for a single thread creation and run
	-----------------------------------------------------------------*/
	longVar threadOverhead = measure_threadOverhead();
	cout<<"Overhead for creating and running a single thread is: "<<threadOverhead<<" ns"<<endl;

	/*-----------------------------------------------------------------
	               Overhead for process context switch
	-----------------------------------------------------------------*/
	longVar procContextSwitchOverhead = measure_processContextSwitchOverhead();
	cout<<"Overhead for proc context switch is: "<<procContextSwitchOverhead<<" ns"<<endl;

	/*-----------------------------------------------------------------
	               Overhead for thread context switch
	-----------------------------------------------------------------*/
	longVar threadContextSwitchOverhead = measure_threadContextSwitchOverhead();
	cout<<"Overhead for thread context switch is: "<<threadContextSwitchOverhead<<" ns"<<endl;

	return 0;
}

int main()
{
	/*-----------------------------------------------------------------
						Measuring memory latency
	-----------------------------------------------------------------*/
	measure_memLatency();

	// vector<longVar> totBWWrite = measure_memWriteBandwidth();
	// cout<<"DRAM write bandwidth: "<<*max_element(totBWWrite.begin(), totBWWrite.end())<<" GiB/s"<<endl;

	// vector<longVar> totBWRead = measure_memReadBandwidth();
	// cout<<"DRAM read bandwidth: "<<*max_element(totBWRead.begin(), totBWRead.end())<<" GiB/s"<<endl;

	cout<<"Average Page Fault Service Time: "<<measure_pageFaultTime()<<"ns"<<endl;
	return 0;
}