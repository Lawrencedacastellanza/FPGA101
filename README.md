# Analyzing FPGA Off-Chip Memory Bandwidth

**Author:** Lorenzo Rocco Didò  
**Date:** March 3, 2023

---

## Abstract

This project aims to calculate the FPGA off-chip memory bandwidth. In this specific case, I choose an SoC, the Pynq-Z2. I carried out tests on three cases that differ in the size of the burst (64-bit, 128-bit, and 256-bit). For each case, I write in memory a different number of bytes to observe if the velocity depends on the dimension of the file. The FPGA reached a higher writing velocity with a 256-bit burst size, and the velocity stabilized after a certain number of bytes.

---

## Introduction

This project represents my first interaction with the world of FPGA. I followed the roadmap below:

1. Creating .cpp and .hpp files in Vitis HLS representing respectively the C++ implementation and the header of the accelerated hardware design.
2. Creating the testbench, which implements a golden model, and running c-simulation, c-synthesis, co-simulation.
3. Exporting the RTL file and importing the created IP on a Pynq-Z2 Vivado project.
4. Using the generated bitstream to write the host file on the Jupiter notebook hosted by the Pynq-Z2.

---

## Description

### Vitis HLS

To implement the accelerated hardware design of the memory benchmark, I used only a function `write` called by the kernel function `kernel`. The kernel function has two input variables:

- `int data_n`: represents the number of data that has to be written.
- `data_w* mem`: which is a `data_w` (an `ap_uint<DataType>` pointer that changes based on the burst size) array allocated from the CPU.

The write function is pipelined using `#pragma HLS PIPELINE II=1`.

For the `data_n` input variable, I chose a `s_axilite` because the data is accessed by the kernel through register interfaces and accessed by software as register reads/writes (for example, it is used to control the kernel through XRT S_AXILITE Control Register Map). The scalar can be thought of as programming constants or parameters. I create an `m_axi` (AXI4 memory-mapped) interface for the pointer to the array (`mem` input variable) because this interface provides allow kernels to read and write data to global memory (DDR, HBM, PLRAM). I can send the same number of Mbytes regardless of the type of data modifying the depth parameter of the interface following this formula:

\[ \text{Depth} = \frac{(MByte \times 1024 \times 1024 \times 8)}{\text{dataType}} \]

To control the `m_axi` interface and for the control register, I had to add two other `s_axilite` interfaces.

The TestBench creates an array in the same way as done from the function `write` and prints if they are written the same.

### Vivado

In Vivado, I created the block design importing the kernel IP and the Zynq processor. After running connection automation and block automation, I exported the bitstream (file.xsa).

![Block Design](Vivado.png)

### Pynq Z2 Host

To write the host file, I had to link the Pynq with my computer and open the hosted Jupyter notebook. I had to create a folder with two files: the .xsa that represents the bitstream and a Python one. I chose to do the benchmark on three different bitstreams, one for each different burst size (I'm referring to the datatype used in the HLS file).

I structured the code with three loops:

1. The first one switches at every iteration the bitstream file the host is referring to. Creates three different overlay objects and allocates a different dimension of the buffer used from the FPGA to write in the data: `buf_data = allocate(int(max_data \times datatype/64), np.uint64)`.
2. The second one does twenty tests for each bitstream. In each test, the host will change the number of data that the FPGA has to write in memory (`data_n` parameter).
3. The third one makes one hundred subtests to create an average time.

The address of the memory, where all the input variables of the HLS kernel function have to be saved, can be seen in the `hw.h` file which can be found in the Vivado project folder.

This is the code that I used to count the time using the time library of Python:

```python
# Time counting code
import time
# ...
