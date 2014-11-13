#ifndef HEADERS_H
#define HEADERS_H

/*---------------------------------------------------------------
Kaushik Kalyanaraman, kkalyana@eng.ucsd.edu
Priyanka Ganapathy, pganapat@eng.ucsd.edu

Essential header files for all programs
---------------------------------------------------------------*/

/*-----------------
Header files
-----------------*/
#include <vector>
#include <string>
#include <math.h>
#include <fcntl.h>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <algorithm>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unordered_map>
#include <mach/mach_time.h>

/*-----------------
Typedefs
-----------------*/
typedef long double longVar;

/*-----------------
Namespace import
-----------------*/
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::vector;
using std::string;
using std::fstream;
using std::to_string;
using std::max_element;
using std::unordered_map;

#endif