#ifndef BENCHMARKS_H
#define BENCHMARKS_H

/*---------------------------------------------------------------
Kaushik Kalyanaraman, kkalyana@eng.ucsd.edu
Priyanka Ganapathy, pganapat@eng.ucsd.edu

Essential benchmarking function prorotypes and constants declared
here for easy access
---------------------------------------------------------------*/

#include "headers.h"

longVar measure_timeOverhead();
longVar measure_loopOverhead();
void measure_procCallOverhead(vector<longVar> &result);
longVar measure_sysCallOverhead();
longVar measure_processOverhead();
longVar measure_threadOverhead();
longVar measure_threadContextSwitchOverhead();
longVar measure_processContextSwitchOverhead();
longVar measure_threadContextSwitchOverhead();

#define NUM_ITERATIONS 250000
#define NUM_THREAD_SWITCHES 500

#endif
