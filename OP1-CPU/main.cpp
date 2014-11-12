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

void measure_mem()
{
	//L3 Cache
	const int stride = 16 * 1024LL;
	const int samples = 1000;
	uint64_t size = 2 * 1024LL * 1024LL;
	uint count = floor(size / stride);

	char *p = new char[size];
	register char temp;
	longVar start, end, total = 0.0;

	for(uint i = 0; i < size; i++)
	{
		p[i] = 'a';
	}

	for(uint sample = 0; sample < samples; sample++)
	{
		start = mach_absolute_time();
		for(uint i = 0; i < size - stride; i += stride)
		{
			temp = p[i];
		}
		end = mach_absolute_time();
		total += end - start;
	}

	cout<<total / (count * samples)<<endl;
}


void measure_mem1()
{
	//L1 Cache
	char p = 'a';
	longVar start, end;
	register char temp;

	start = mach_absolute_time();
	for(int i = 0; i < 100000; i++)
		temp = p;
	end = mach_absolute_time();

	cout<<(end-start) / 100000<<endl;
}

int main()
{
	/*-----------------------------------------------------------------
						Measuring memory latency
	-----------------------------------------------------------------*/
	measure_memLatency();
	// vector<vector<longVar>> result = measure_memLatency();
	// vector<string> strides {"8K", "16K", "64K", "512K", "2M", "16M", "64M"};
	// vector<int> arrSizes {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
	// 						21, 22, 23, 24, 25, 26, 27, 28};
	// // measure_mem();

	// cout<<left<<setw(8)<<"LogArr";
	// for (auto it: arrSizes)
	// 	cout<<left<<setw(8)<<it;

	// cout<<endl<<endl;
	// for (int i = 0; i < result.size(); i++)
	// {
	// 	cout<<left<<setw(8)<<strides[i];
	// 	for (auto it1: result[i])
	// 		cout<<left<<setw(8)<<it1;
	// 	cout<<endl;
	// }

	// vector<longVar> totBWWrite = measure_memWriteBandwidth();
	// cout<<"DRAM write bandwidth: "<<*max_element(totBWWrite.begin(), totBWWrite.end())<<" GiB/s"<<endl;

	// vector<longVar> totBWRead = measure_memReadBandwidth();
	// cout<<"DRAM read bandwidth: "<<*max_element(totBWRead.begin(), totBWRead.end())<<" GiB/s"<<endl;
	return 0;
}