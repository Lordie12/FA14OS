#include "benchmarks.h"

/*---------------------------------------------------------------
Kaushik Kalyanaraman, kkalyana@eng.ucsd.edu
Priyanka Ganapathy, pganapat@eng.ucsd.edu

Benchmarking code implemented
---------------------------------------------------------------*/

longVar measure_timeOverhead()
{
    longVar start;
    longVar end;
    longVar total = 0;
    static mach_timebase_info_data_t sTimebaseInfo;
    int i;

	mach_timebase_info(&sTimebaseInfo);

    for (i = 0; i < NUM_ITERATIONS; i++)
    {
    	start = mach_absolute_time();
    	end = mach_absolute_time();
     	total += end - start;
    }
    total /= NUM_ITERATIONS;
    total *= sTimebaseInfo.numer / sTimebaseInfo.denom;
    return total;
}

longVar measure_loopOverhead()
{
	longVar start;
	longVar end;
	longVar total = 0;
	static mach_timebase_info_data_t sTimebaseInfo;
	int i, j = 0;

	mach_timebase_info(&sTimebaseInfo);

	/*-------------------------------------------------------------
	A single loop running NUM_ITERATION times seems to be optimized
	by branch prediction and extensive loop unrolling
	-------------------------------------------------------------*/
	start = mach_absolute_time();
	for (j = 0; j < NUM_ITERATIONS; j++);
	end = mach_absolute_time();
	
	total = end - start;
	total /= NUM_ITERATIONS;
	total *= sTimebaseInfo.numer / sTimebaseInfo.denom;
	return total;
}

int p_0()
{ return 0; }

int p_1(int arg1)
{ return 0; }

int p_2(int arg1, int arg2)
{ return 0; }

int p_3(int arg1, int arg2, int arg3)
{ return 0; }

int p_4(int arg1, int arg2, int arg3, int arg4)
{ return 0; }

int p_5(int arg1, int arg2, int arg3, int arg4, int arg5)
{ return 0; }

int p_6(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
{ return 0; }

int p_7(int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7)
{ return 0; }

void measure_procCallOverhead(vector<longVar> &result)
{
	static mach_timebase_info_data_t sTimebaseInfo;
	longVar start = 0;
	longVar end = 0;
	longVar tot = 0;
	longVar loopOverhead = measure_loopOverhead();

	int arg1 = 1;
	int arg2 = 2;
	int arg3 = 3;
	int arg4 = 4;
	int arg5 = 5;
	int arg6 = 6;
	int arg7 = 7;
	int i = 0;

	mach_timebase_info(&sTimebaseInfo);

	for (i = 0; i < NUM_ITERATIONS; i++)
	{
		start = mach_absolute_time();
		p_0();
		end = mach_absolute_time();
		tot += end - start;
	}
	tot /= NUM_ITERATIONS;
	tot -= loopOverhead;
	tot *= sTimebaseInfo.numer / sTimebaseInfo.denom;
	result.push_back(tot);
	tot = 0;

	for (i = 0; i < NUM_ITERATIONS; i++)
	{
		start = mach_absolute_time();
		p_1(arg1);
		end = mach_absolute_time();
		tot += end - start;
	}
	tot /= NUM_ITERATIONS;
	tot -= loopOverhead;
	result.push_back(tot);
	tot = 0;

	for (i = 0; i < NUM_ITERATIONS; i++)
	{
		start = mach_absolute_time();
		p_2(arg1, arg2);
		end = mach_absolute_time();
		tot += end - start;
	}
	tot /= NUM_ITERATIONS;
	tot -= loopOverhead;
	tot *= sTimebaseInfo.numer / sTimebaseInfo.denom;
	result.push_back(tot);
	tot = 0;

	for (i = 0; i < NUM_ITERATIONS; i++)
	{
		start = mach_absolute_time();
		p_3(arg1, arg2, arg3);
		end = mach_absolute_time();
		tot += end - start;
	}
	tot /= NUM_ITERATIONS;
	tot -= loopOverhead;
	tot *= sTimebaseInfo.numer / sTimebaseInfo.denom;
	result.push_back(tot);
	tot = 0;

	for (i = 0; i < NUM_ITERATIONS; i++)
	{
		start = mach_absolute_time();
		p_4(arg1, arg2, arg3, arg4);
		end = mach_absolute_time();
		tot += end - start;
	}
	tot /= NUM_ITERATIONS;
	tot -= loopOverhead;
	tot *= sTimebaseInfo.numer / sTimebaseInfo.denom;
	result.push_back(tot);
	tot = 0;

	for (i = 0; i < NUM_ITERATIONS; i++)
	{
		start = mach_absolute_time();
		p_5(arg1, arg2, arg3, arg4, arg5);
		end = mach_absolute_time();
		tot += end - start;
	}
	tot /= NUM_ITERATIONS;
	tot -= loopOverhead;
	tot *= sTimebaseInfo.numer / sTimebaseInfo.denom;
	result.push_back(tot);
	tot = 0;

	for (i = 0; i < NUM_ITERATIONS; i++)
	{
		start = mach_absolute_time();
		p_6(arg1, arg2, arg3, arg4, arg5, arg6);
		end = mach_absolute_time();
		tot += end - start;
	}
	tot /= NUM_ITERATIONS;
	tot -= loopOverhead;
	tot *= sTimebaseInfo.numer / sTimebaseInfo.denom;
	result.push_back(tot);
	tot = 0;

	for (i = 0; i < NUM_ITERATIONS; i++)
	{
		start = mach_absolute_time();
		p_7(arg1, arg2, arg3, arg4, arg5, arg6, arg7);
		end = mach_absolute_time();
		tot += end - start;
	}
	tot /= NUM_ITERATIONS;
	tot -= loopOverhead;
	tot *= sTimebaseInfo.numer / sTimebaseInfo.denom;
	result.push_back(tot);
}

longVar measure_sysCallOverhead()
{
	static mach_timebase_info_data_t sTimebaseInfo;
	longVar loopOverhead = measure_loopOverhead();
	longVar start;
	longVar end;
	longVar tot;
	int i, j;

	mach_timebase_info(&sTimebaseInfo);

	start = mach_absolute_time();
	for (i = 0; i < 1; i++)
	{
		getpid();
	}
	end = mach_absolute_time();

	tot = (end - start) / 1;
	tot -= loopOverhead;
	return tot;
}

longVar measure_processOverhead()
{
	static mach_timebase_info_data_t sTimebaseInfo;
	longVar start = 0;
	longVar end = 0;
	longVar tot;
	pid_t pid;
	int status;

	mach_timebase_info(&sTimebaseInfo);

	start = mach_absolute_time();
	pid = fork();
	if (pid == 0)
	{
		//We are in the child process
		exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);
		end = mach_absolute_time();
	}
	tot = ((end - start) / 1000) * (sTimebaseInfo.numer / sTimebaseInfo.denom);
	return tot;
}

void* dummy_func(void* dummy_arg)
{ return 0; }

longVar measure_threadOverhead()
{
	static mach_timebase_info_data_t sTimebaseInfo;
	longVar start = 0;
	longVar end = 0;
	pthread_t thread;
	int iret1, iret2;

	mach_timebase_info(&sTimebaseInfo);

	start = mach_absolute_time();
	iret1 = pthread_create(&thread, NULL, dummy_func, (void *)&iret2);
	pthread_join(thread, NULL);
	end = mach_absolute_time();

	if (iret1)
	{
		cout<<"Error - pthread _create return code: "<<iret1<<endl;
		return 0;
	}
	return (end - start) * sTimebaseInfo.numer / sTimebaseInfo.denom;
}