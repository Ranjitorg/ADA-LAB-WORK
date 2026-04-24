#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>

using namespace std::chrono;
using namespace std;

void insertionSort243116(int arr[], int n){
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;}
        arr[j + 1] = key;
    }
}

double timeInsertionSort(int n, int trials) {
    double totalTime = 0;
    
    for (int t = 0; t < trials; t++) {
        int* arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        
        auto start = high_resolution_clock::now();
        insertionSort243116(arr, n);
        auto stop = high_resolution_clock::now();
        
        auto duration = duration_cast<nanoseconds>(stop - start);
        totalTime += duration.count();
        
        delete[] arr;
    }
    
    return totalTime / trials / 1e6; // Convert to milliseconds
}

int main(){
    int trials = 5;
    ofstream fout("outputIS.txt");
    fout << "n,time_ms" << endl; // CSV header
    
    for (int n = 1000; n <= 50000; n += 5000) {
        double avgTime = timeInsertionSort(n, trials);
        fout << n << "," << avgTime << endl;
        cout << "n = " << n << ", time = " << avgTime << " ms" << endl;
    }
    
    fout.close();
    return 0;
}