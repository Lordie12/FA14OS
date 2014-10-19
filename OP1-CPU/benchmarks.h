#ifndef BENCHMARKS_H
#define BENCHMARKS_H

/*---------------------------------------------------------------
Kaushik Kalyanaraman, kkalyana@eng.ucsd.edu
Priyanka Ganapathy, pganapat@eng.ucsd.edu

Essential benchmarking unction prorotypes and constants declared
here for easy access
---------------------------------------------------------------*/

#include "headers.h"

longVar measure_timeOverhead();
longVar measure_loopOverhead();
void measure_procCallOverhead(vector<longVar> &result);
longVar measure_sysCallOverhead();
longVar measure_processOverhead();
longVar measure_threadOverhead();

#define NUM_ITERATIONS 250000

#endif
