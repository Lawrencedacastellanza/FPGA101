#ifndef TESTMEM_HPP
#define TESTMEM_HPP

#include <iostream>
#include <stdlib.h>
#include "ap_int.h"
#include <cmath>

#define MBYTE 80
#define DATATYPE 64
#define DEPTH ((MBYTE*(1024*1024)*8)/64)

typedef ap_uint<DATATYPE> data_w;//(datawight)


void kernel(data_w*, int);
void write(data_w*, int );


#endif // TESTMEM_HPP
