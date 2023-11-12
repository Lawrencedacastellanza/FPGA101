# Analyzing FPGA Off-Chip Memory Bandwidth

**Author:** Lorenzo Rocco Didò  

This project aims to calculate the FPGA off-chip memory bandwidth. In this specific case, I choose an SoC, the Pynq-Z2. I carried out tests on three cases that differ in the size of the burst (64-bit, 128-bit, and 256-bit). For each case, I write in memory a different number of bytes to observe if the velocity depends on the dimension of the file. The FPGA reached a higher writing velocity with a 256-bit burst size, and the velocity stabilized after a certain number of bytes.

## Overview

This project represents my first interaction with the world of FPGA. I followed the roadmap below:

1. Creating .cpp and .hpp files in Vitis HLS representing respectively the C++ implementation and the header of the accelerated hardware design.
2. Creating the testbench, which implements a golden model, and running c-simulation, c-synthesis, and co-simulation.
3. Exporting the RTL file and importing the created IP on a Pynq-Z2 Vivado project.
4. Using the generated bitstream to write the host file on the Jupiter notebook hosted by the Pynq-Z2.

---

## Getting Started

### Installation

 **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/your-repository.git
   cd your-repository
   ```
## Prerequisites
For testing the design on the actual hardware:
- **PYNQ-Z2 board**

If you want to modify the code and create your own version make sure you have the following software installed on your development machine:
- **Vivado** - for FPGA development.
- **Vitis HLS** - for high-level synthesis.

## Configuration

1. You have to connect the Pynq z2 to your computer and open the hosted Jupiter notebook. [PYNQ-Z2 Setup Guide](https://pynq.readthedocs.io/en/v2.3/getting_started/pynq_z2_setup.html)
2. Upload all the files contained in the pynqHost folder.
3. Run the code

if you want to modify the design and the program you must follow the points presented in the Overview section except that, instead of creating a new C++ file, you can import the testmem_hls folder into Vitis HSL.

## Result

The benchmark result shows that the bandwidth performance of the off-chip memory increases with a larger burst size. This is caused by the three-way handshake When using the same burst size, I noticed that the more data you write in memory, the more the writing velocity FPGA increases until it reaches a point where it stabilizes at about 1 Mbytes.
The Pynq z2 uses a **three-way handshake** memory allocation system that takes the same amount of time regardless of how large the payload is. With smaller data packets it carries less data by doing more handshake. 

### PYNQ-Z2 Write Speed obtained with my program
As you can see from the Line Chart below I have obtained nearly five times the datasheet-reported velocity of the Pynq (1050 Mbps).
My hypothesis is that the problem is caused by my program which, doesn't wait for confirmation (of the three-way handshake) thus, resulting in a much faster memory-saving time than the limits of Pynq.

![PYNQ-Z2 Write Speed](Graph.png)
<img src="Graph.png" width="700" height="500">






