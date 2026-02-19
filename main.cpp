#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;

// Basic bubble sort
void bubbleSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - 1; j++) {
if (arr[j] > arr[j + 1]) {
swap(arr[j], arr[j + 1]);
}
}
}
}

// Bubble sort with small optimizations
void bubbleSortV2(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
bool swapped = false;

for (int j = 0; j < n - 1 - i; j++) {
if (arr[j] > arr[j + 1]) {
swap(arr[j], arr[j + 1]);
swapped = true;
}
}

if (!swapped) break;
}
}

// Selection sort
void selectionSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
int minIndex = i;

for (int j = i + 1; j < n; j++) {
if (arr[j] < arr[minIndex]) {
minIndex = j;
}
}

swap(arr[i], arr[minIndex]);
}
}

// Insertion sort
void insertionSort(int arr[], int n) {
for (int i = 1; i < n; i++) {
int key = arr[i];
int j = i - 1;

while (j >= 0 && arr[j] > key) {
arr[j + 1] = arr[j];
j--;
}

arr[j + 1] = key;
}
}

// Helper to print arrays
void printArray(const int arr[], int n) {
for (int i = 0; i < n; i++) cout << arr[i] << " ";
cout << "\n";
}

// main
int main() {

const int size = 10;

int normalArr[size];
int a1[size], a2[size], a3[size], a4[size];

srand(time(nullptr));

cout << "Normal Array:\n";
for (int i = 0; i < size; i++) {
normalArr[i] = rand() % 100;
cout << normalArr[i] << " ";
}

cout << "\n\n";

// Copy original values
for (int i = 0; i < size; i++) {
a1[i] = normalArr[i];
a2[i] = normalArr[i];
a3[i] = normalArr[i];
a4[i] = normalArr[i];
}

// Time bubbleSort
auto start = chrono::high_resolution_clock::now();
bubbleSort(a1, size);
auto end = chrono::high_resolution_clock::now();
chrono::duration<double> elapsed = end - start;

cout << "Sorted Array by bubbleSort:\n";
printArray(a1, size);
cout << "Bubble Sort time: " << elapsed.count() << " seconds\n\n";

// Time bubbleSortV2
start = chrono::high_resolution_clock::now();
bubbleSortV2(a2, size);
end = chrono::high_resolution_clock::now();
elapsed = end - start;

cout << "Sorted Array by bubbleSortV2:\n";
printArray(a2, size);
cout << "Bubble Sort V2 time: " << elapsed.count() << " seconds\n\n";

// Time selectionSort
start = chrono::high_resolution_clock::now();
selectionSort(a3, size);
end = chrono::high_resolution_clock::now();
elapsed = end - start;

cout << "Sorted Array by selectionSort:\n";
printArray(a3, size);
cout << "Selection Sort time: " << elapsed.count() << " seconds\n\n";

// Time insertionSort
start = chrono::high_resolution_clock::now();
insertionSort(a4, size);
end = chrono::high_resolution_clock::now();
elapsed = end - start;

cout << "Sorted Array by insertionSort:\n";
printArray(a4, size);
cout << "Insertion Sort time: " << elapsed.count() << " seconds\n";

return 0;
}