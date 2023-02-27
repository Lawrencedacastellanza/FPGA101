#include "testmem.hpp"

void write (data_w *mem , int data_n){
	//writing 80Mbyte of data
	for (int i = 0; i < data_n; i++) {
		#pragma HLS pipeline II=1
		mem[i] = (data_w)i;
	}
}


void kernel(data_w *mem, int data_n) {
	const int datadepth =DEPTH;

	#pragma HLS INTERFACE mode=s_axilite port=return bundle=control

    #pragma HLS INTERFACE mode=m_axi port=mem depth=datadepth bundle=gmem offset=slave
	#pragma HLS INTERFACE mode=s_axilite port=mem bundle=control

	#pragma HLS INTERFACE mode=s_axilite port=data_n bundle=control

	write(mem,data_n);
}

