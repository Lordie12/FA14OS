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

longVar measure_loopOverhead(uint iterations)
{
	longVar start;
	longVar end;
	longVar total = 0;
	static mach_timebase_info_data_t sTimebaseInfo;
	int i;

	mach_timebase_info(&sTimebaseInfo);

	/*-------------------------------------------------------------
	A single loop running NUM_ITERATION times seems to be optimized
	by branch prediction and extensive loop unrolling
	-------------------------------------------------------------*/
	start = mach_absolute_time();
	for (i = 0; i < iterations; i++);
	end = mach_absolute_time();
	
	total = end - start;
	total /= iterations;
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
	struct stat fileStat;
	int i;

	mach_timebase_info(&sTimebaseInfo);

	start = mach_absolute_time();
	for (i = 0; i < NUM_ITERATIONS; i++)
	{
		/*---------------------------------------------------------------------
		Why only one? There seems to be syscall caching of idempotent system
		calls, so every subsequent call to getpid() is a cache hit and not an 
		OS Trap, not sure how to get around this mess
		---------------------------------------------------------------------*/
		stat("/Users/Lanfear/Desktop/FA14OS/README.md", &fileStat);
	}
	end = mach_absolute_time();

	return (((end - start) / (float)(NUM_ITERATIONS)) * sTimebaseInfo.numer / sTimebaseInfo.denom)
		 - loopOverhead;
}

longVar measure_processOverhead()
{
	static mach_timebase_info_data_t sTimebaseInfo;
	longVar start = 0;
	longVar end = 0;
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
	return ((end - start) / 1000) * (sTimebaseInfo.numer / sTimebaseInfo.denom);
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

longVar measure_processContextSwitchOverhead()
{
	static mach_timebase_info_data_t sTimebaseInfo;
	longVar start;
	longVar end;
	longVar tot = 0;
	int fd[4];
	pipe(fd);
	pipe(&fd[2]);
	pid_t pid;

	mach_timebase_info(&sTimebaseInfo);	
	pid = fork();
	if (pid == 0)
	{
		int switchCount = 0;
		//Child executing here
		for (; switchCount < NUM_THREAD_SWITCHES; switchCount++)
		{
			start = mach_absolute_time();
			write(fd[1], &start, sizeof(start));
			read(fd[2], &end, sizeof(end));
			tot += mach_absolute_time() - end;
		}
		exit(0);
	}
	else
	{
		int switchCount = 0;
		//Parent executing here
		for(; switchCount < NUM_THREAD_SWITCHES; switchCount++)
		{
			read(fd[0], &start, sizeof(start));
			end = mach_absolute_time();
			tot += end - start;
			write(fd[3], &end, sizeof(end));
		}
		return (tot / NUM_THREAD_SWITCHES) * sTimebaseInfo.numer / sTimebaseInfo.denom;
	}
	return 0;
}

void* thread_dummy(void* dummy_arg)
{
	int switchCount;
	for (switchCount = 0; switchCount < NUM_THREAD_SWITCHES; switchCount++)
	{
		/*-----------------------------------------------------------------
		We keep switching between this new thread and the main thread using
		the scheduler yield function, but we context switch 2 * NUM_THREAD_
		SWITCHES TIMES and hence we divide by twice that value in return
		-----------------------------------------------------------------*/
		sched_yield();
	}
	return 0;
}

longVar measure_threadContextSwitchOverhead()
{
	static mach_timebase_info_data_t sTimebaseInfo;
	longVar start = 0;
	longVar end = 0;
	pthread_t thread;
	int iret = 0;
	int switchCount;

	mach_timebase_info(&sTimebaseInfo);
	/*----------------------------------------------------------------------
	We do not consider thread creation to be a part of the thread context 
	switch time and hence we start the timer after calling pthread_create 
	and not before
	----------------------------------------------------------------------*/
	pthread_create(&thread, NULL, thread_dummy, (void *)&iret);
	start = mach_absolute_time();
	for(switchCount = 0; switchCount < NUM_THREAD_SWITCHES; switchCount++)
	{
		sched_yield();
	}
	pthread_join(thread, NULL);
	end = mach_absolute_time();

	return ((end - start) / (2 * NUM_THREAD_SWITCHES)) * sTimebaseInfo.numer / sTimebaseInfo.denom;
}

vector<vector<longVar>> measure_memLatency()
{
	static mach_timebase_info_data_t sTimebaseInfo;
	/*-------------------------------------------------------
	The array sizes are in powers of 2
	-------------------------------------------------------*/
	vector<int> arrSizes = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
	/*-------------------------------------------------------
	The strides are in powers of 2
	-------------------------------------------------------*/
	vector<int> strides = {9, 10, 11, 13, 15, 16, 18, 19};
	vector<vector<longVar>> totResults;

	fstream f;
	f.open("/Users/Lanfear/Desktop/Output.txt", fstream::out | fstream::in);

	longVar start, end;
	int arrLen = 0;
	uint64_t stride;

	mach_timebase_info(&sTimebaseInfo);

	//Array sizes in powers of 2
	for (auto cstride: strides)
	{
		vector<longVar> currStrideResult;
		for (auto size: arrSizes)
		{
			arrLen = 1 << size;
			//Compute stride in terms of array index, re-scale by 8

			stride = 1 << cstride;

			uint64_t* arr = new uint64_t[arrLen];
			memset(arr, 0x00, arrLen * sizeof(uint64_t));
			unordered_map<int, bool> index;

			uint j = 0;
			for(uint64_t i = 0; i < stride * arrLen; i += stride)
			{
				if (index[(i + stride) % arrLen] == false)
				{
					/*---------------------------------------------------------
					Pointer chasing, create a list of pointers and reinterpret
					case it to the same type so that we can chase it later
					---------------------------------------------------------*/
					arr[j] = reinterpret_cast<uint64_t>(arr + (i + stride) % arrLen);
					j = (i + stride) % arrLen;
				}
				index[(i + stride) % arrLen] = true;
			}

			start = mach_absolute_time();
			for (uint sample = 0; sample < NUM_LOADS; sample++)
			{
				uint64_t *p = arr;
				for(int i = 0; i < arrLen; i++)
				{
					//Chase pointer
					p = reinterpret_cast<uint64_t*>(*p);
				}
			}
			end = mach_absolute_time();

			delete[] arr;
			string sSize = to_string((arrLen * 8) / 1024) + 'K';
			string sStride = to_string(stride/128) + 'K';
			cout<<left<<setw(4)<<"SIZE: "<<left<<setw(8)<<sSize;
			cout<<left<<setw(4)<<" STRIDE: "<<left<<setw(2)<<sStride;
			cout<<left<<setw(4)<<" TIME: "<<left<<setw(4)<<(end - start) / (float)(arrLen * NUM_LOADS)<<" ns"<<endl;

			f << (end - start) / (float)(arrLen * NUM_LOADS) << ',';
		}
		f << '\n';
	}
	f.close();
	return totResults;
}

inline double to_bw(size_t bytes, double ns) 
{ 
	/*------------------------------------------------
	Convert the number of bytes into GigaBytes, and 
	convert given nanosecond time into seconds
	------------------------------------------------*/
	return bytes / (pow(2, 30) * ns * pow(10, -9)); 
}

char myArray[ARR_SIZE] __attribute__ ((aligned (8)));

vector<longVar> measure_memWriteBandwidth()
{
	longVar start, end, timeInNS;
	vector<longVar> totals;
	longVar loopOverhead = measure_loopOverhead(ARR_WRITES);

  	for (uint i = 0; i < NUM_SAMPLES; i++) 
  	{
    	start = mach_absolute_time();
    	for (uint j = 0; j < ARR_WRITES; j++) 
    	{
    		/*--------------------------------------------------
			http://stackoverflow.com/questions/8425022/
			performance-of-x86-rep-instructions-on-modern-
			pipelined-superscalar-processors/8429084#8429084
			---------------------------------------------------*/
    		asm volatile("cld\n rep stosq" : : "a" (0), "c" (ARR_SIZE / 8), "D" (myArray));
    	}
    	end = mach_absolute_time();

    	timeInNS = end - start - loopOverhead;
    	totals.push_back(to_bw((ARR_SIZE * ARR_WRITES), timeInNS));
  	}
  	//Return an array of bandwidth measures, easy to compute mean, STDDEV
	return totals;
}

vector<longVar> measure_memReadBandwidth()
{
	longVar start, end, timeInNS;
	vector<longVar> totals;
	longVar loopOverhead = measure_loopOverhead(ARR_WRITES);
  	for (uint i = 0; i < NUM_SAMPLES; i++) 
  	{
    	start = mach_absolute_time();
    	for (uint j = 0; j < ARR_WRITES; j++) 
    	{
    		asm volatile("cld\n rep lodsq" : : "S" (myArray), "c" (ARR_SIZE / 8) : "%eax");
    	}
    	end = mach_absolute_time();

    	timeInNS = end - start - loopOverhead;
    	totals.push_back(to_bw((ARR_SIZE * ARR_WRITES), timeInNS) * 2.5);
  	}
  	//Return an array of bandwidth measures, easy to compute mean, STDDEV
	return totals;
}

longVar measure_pageFaultTime()
{
	const char* fileURL = "/Users/Lanfear/Desktop/FA14OS/References/MemSystems.pdf";
	const uint pagesize = getpagesize();
	const uint chunkSize = CHUNK_SIZE;
	uint offset = 0, numChunks, numChunkPages;
	register char temp;

	struct stat statBuf;
	int fd = open(fileURL, O_RDONLY);
	void* memMapFile;
	longVar start, end, total = 0.0, PFT;

	//Do not cache contents of the file in main memory
	fcntl(fd, F_NOCACHE, 1);
	stat(fileURL, &statBuf);

	const uint fileSize = statBuf.st_size;
	
	numChunks = floor(fileSize / chunkSize);
	numChunkPages = floor(chunkSize / pagesize);

	while (offset <= fileSize - CHUNK_SIZE)
	{
		//Lets mmap the filedesc fd with the offset
		memMapFile = mmap(0, chunkSize, PROT_READ, MAP_PRIVATE, fd, offset);
		if (memMapFile == MAP_FAILED)
			return -1;
               
		offset += chunkSize;

		start = mach_absolute_time();
		for(uint i = 0; i <= chunkSize - pagesize; i += pagesize)
		{
			temp = *(reinterpret_cast<char *>(memMapFile) + i);
		}
		end = mach_absolute_time();
		total += end - start;

		munmap(memMapFile, chunkSize);
	}

	PFT = total / (float)(numChunkPages * numChunks);
	return PFT;
}