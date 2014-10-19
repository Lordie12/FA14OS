#include "benchmarks.h"

/*---------------------------------------------------------------
Kaushik Kalyanaraman, kkalyana@eng.ucsd.edu
Priyanka Ganapathy, pganapat@eng.ucsd.edu

The primary driver program to test all benchmarks
---------------------------------------------------------------*/

int main()
{
	/*-----------------------------------------------------------------
					     Overhead in measuring time
	-----------------------------------------------------------------*/
	longVar mesTimeOverhead = measure_timeOverhead();
	cout<<"Overhead of reading time, over "<<NUM_ITERATIONS<<" iterations (ns):"<<mesTimeOverhead<<endl;

	/*-----------------------------------------------------------------
						     Overhead of a loop
	-----------------------------------------------------------------*/
	longVar mesLoopOverhead = measure_loopOverhead();
	cout<<"Overhead of a loop, over "<<NUM_ITERATIONS<<" iterations (ns):"<<mesLoopOverhead<<endl;

	/*-----------------------------------------------------------------
	          Overhead in procedure calls of different lengths
	-----------------------------------------------------------------*/
	vector<longVar> procOverhead;
	int count = 0;
	measure_procCallOverhead(procOverhead);
	cout<<"Overhead for procedure calls, over "<<NUM_ITERATIONS<<" iterations (ns): "<<endl;
	for (auto it: procOverhead)
		cout<<"Procedure with "<<count++<<" arguments: "<<it<<endl;

	/*-----------------------------------------------------------------
	          			 Overhead for system call
	-----------------------------------------------------------------*/
	longVar syscallOverhead = measure_sysCallOverhead();
	cout<<"Overhead for system call getpid(), over "<<1<<" iteration (ns): "<<syscallOverhead<<endl;

	/*-----------------------------------------------------------------
	          Overhead for a single process creation and run
	-----------------------------------------------------------------*/
	longVar processOverhead = measure_processOverhead();
	cout<<"Overhead for creating and running a single process is (ms): "<<processOverhead<<endl;

	/*-----------------------------------------------------------------
	          Overhead for a single thread creation and run
	-----------------------------------------------------------------*/
	longVar threadOverhead = measure_threadOverhead();
	cout<<"Overhead for creating and running a single thread is (ns): "<<threadOverhead<<endl;

}