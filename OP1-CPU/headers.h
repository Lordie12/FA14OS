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
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <numeric>
#include <signal.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <algorithm>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unordered_map>
#include <mach/mach_time.h>


/*-----------------
Typedefs
-----------------*/
typedef long double longVar;

/*-----------------
Namespace import
-----------------*/
using std::cin;
using std::ios;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using std::sqrt;
using std::vector;
using std::string;
using std::fstream;
using std::to_string;
using std::accumulate;
using std::max_element;
using std::inner_product;
using std::unordered_map;

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

#endif