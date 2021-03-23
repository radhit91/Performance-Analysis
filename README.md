# Performance-Analysis
Analysing performance based on hardware counters measured using perf tool

# Architecture Information
cat /proc/cpuinfo (output stored in image "cpu-info.png")

# Code Information
"matmul.cpp" does both matrix sum and matrix multiplication of two matrices using pointers. It uses one of them in "column major" form while initializing, computing matrxi sum and multiplication while the other is accessed in "row major" fashion. <br/>

"matmul-1.cpp" does both matrix sum and matrix multiplication of two matrices using pointers. It uses both of them in "column major" form while initializing, computing matrxi sum and multiplication.

# Compile Command
g++ -std=c++11 matmul.cpp -o matmul      // for "matmul.cpp" <br/>

g++ -std=c++11 matmul-1.cpp -o matmul-1  // for "matmul-1.cpp" <br/>


# Run Command (using perf)
// for "matmul.cpp" ; output stored in "perf-matmul.png" <br/>

sudo perf stat -e branches,branch-misses,bus-cycles,cache-misses,cache-references,cycles,instructions,ref-cycles,cs,cpu-clock,migrations,faults,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,L1-icache-load-misses,LLC-load-misses,LLC-loads,LLC-store-misses,LLC-stores,branch-load-misses,branch-loads,dTLB-load-misses,dTLB-loads,dTLB-store-misses,dTLB-stores,iTLB-load-misses,iTLB-loads,node-load-misses,node-loads,node-store-misses,node-stores ./matmul  <br/>


//for "matmul-1.cpp" ; output stored in "perf-matmul-1.png" <br/>

sudo perf stat -e branches,branch-misses,bus-cycles,cache-misses,cache-references,cycles,instructions,ref-cycles,cs,cpu-clock,migrations,faults,L1-dcache-load-misses,L1-dcache-loads,L1-dcache-stores,L1-icache-load-misses,LLC-load-misses,LLC-loads,LLC-store-misses,LLC-stores,branch-load-misses,branch-loads,dTLB-load-misses,dTLB-loads,dTLB-store-misses,dTLB-stores,iTLB-load-misses,iTLB-loads,node-load-misses,node-loads,node-store-misses,node-stores ./matmul-1 <br/>


# Memory Latency Checker (using mlc) 
modprobe msr // loading kernel driver for handling msr (model-specific registers) for switching off hardware prefetcher <br/>

sudo ./mlc // for measuring memory access latency and bandwidth for both loaded and non-loaded settings; output stored in image "mlc.png"


