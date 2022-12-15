University of British Columbia  

*Isabelle Andre*  

# Computer Architecture  
A series of labs on relevant and state of the art computer architecture topics using C++ and the ChampSim Simulator  

## Table of Content

1. [Lab 1 Instrumentation, Program Analysis, and Modeling](https://github.com/Abeilles14/Computer-Architecture/tree/main/Lab%201%20-%20Pintool#lab-1-instrumentation-program-analysis-and-modeling)
2. [Lab 2 High-Performing Cache Replacement Policies](https://github.com/Abeilles14/Computer-Architecture/tree/main/Lab%202%20-%20High-Performance%20Cache%20Replacement%20Policies#table-of-contents)
3. [Lab 3 Architectural Simulator and Code Optimization](https://github.com/Abeilles14/Computer-Architecture/tree/main/Lab%203%20-%20Deep-Diving%20into%20the%20Architectural%20Simulator%20and%20Code%20Optomization#table-of-contents)
4. [Lab 4 Branch Predictor Implementation](https://github.com/Abeilles14/Computer-Architecture/tree/main/Lab%204%20-%20Branch%20Predictor%20implementations#table-of-contents)

## Lab 1 Instrumentation, Program Analysis, and Modeling  
This project discusses program analysis using Pintool and writing efficient sorting algorithms. A Pintool was designed to count the number of instructions for various sorting algortihms such as Bubble sort. The number of memory and non-memory instructions were counted as well as the total execution time required to execute the algorithm. Another sorting algorithm was implemented to execute at 25x lower total instructions than Bubble Sort.  

## Lab 2 High-Performing Cache Replacement Policies  
This assignment consisted in implementing high-performance and industry-grade cache-replacement policies for the shared Last Level Cache (LLC). The ChampSim simulator is used to implement, execute, and test caching policies. More specifically, we focus on the implementation and surface-level performance analysis of 4 different caching policies: LIP, BIP, DIP, and pLRU. The performance of these algorithms are showcased using spec2006 integer benchmarks. Finally, we compare the performance of these caching policies using cumulative IPC, hit rate, miss latency, and their IPC geomean, as compared with LRU.

## Lab 3 Architectural Simulator and Code Optimization 
This assignment consisted in understanding the implementation of architectural simulators and how to generate traces for the simulator from applications. A naive matrix multiplication function was provided to be optimized in speedup and memory. In Part A, we explore the simulator’s pipelined architecture and implement a non-pipelined core by modifying the current out-of-order core implementation of ChampSim. In Part B and this report, we optimize the basic matrix multiplication implementation by achieving 30% speed-up using loop reordering and matrix transposition, and reducing the L1D cache miss-rate by 8x by using blocked matrix multiplication.

## Lab 4 Branch Predictor Implementation  
This assignment consisted in understanding the implementation of branch prediction policies using ChampSim. Two branch predictors were implemented. A 2-bit correlated branch predictor with a single bit of history was first created, followed by a hashed-gselect predictor with 5 bits of branch history. The hashing employs a XOR function to index the table. The performance of both branch predictors were compared against the hashed perceptron predictor across 5 different spec2006 workloads using geomean.