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

### Prerequisites

Make sure you have the following software installed on your development machine:

- [Vivado](https://www.xilinx.com/products/design-tools/vivado.html) - for FPGA development.
- [Vitis HLS](https://www.xilinx.com/products/design-tools/vitis.html) - for high-level synthesis.
- [PYNQ-Z2 board](https://store.digilentinc.com/pynq-z2-python-productivity-for-zynq/) - for testing the design on the actual hardware.

### Installation

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/your-repository.git
   cd your-repository
