# All_Sorts_Algorithm
(C++)

This small project compares four common sorting algorithms on the same random data so the results are fair. It generates a random array, copies that same array into four separate arrays, and then sorts each copy using a different algorithm. After each sort, it prints the sorted result and shows how long the sort took using C++ chrono.



- Algorithms included

- Bubble Sort (basic)

- Bubble Sort (optimized: smaller inner loop + early exit)

- Selection Sort

- Insertion Sort

Why I made this

I wanted a simple way to see how different sorting algorithms behave and why “small optimizations” (like skipping the sorted tail or stopping early when no swaps happen) can matter.



How to run:

1- Compile:

g++ main.cpp -o main

2- Run:

./main