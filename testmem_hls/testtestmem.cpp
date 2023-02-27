
#include "testmem.hpp"


int main (int argc,char* argv[]){
	int dati =150;
	data_w mem[dati];
	data_w goldmem[dati];
	kernel(mem, dati);
	for (int i = 0; i < dati; i++) {
		goldmem[i] = (data_w)i;
	}
	//compare the result
	int c=1;
	for (int i=0;i<dati;i++){
		if(goldmem[i]!=mem[i])
			c=0;
	}
	if(c==0)
		std::cout<<"test failed"<< std::endl;
	else std::cout<<"test passed"<<std::endl;

	return 0;
}
