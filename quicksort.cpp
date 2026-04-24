#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1; 
    for (int j = low; j < high; j++) { 
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); 
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) { 
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


int main() {
    ofstream fout("outputQS.txt");
    fout << "n,time_ms" << endl; 
    
    int trials = 10;
    for (int n = 1000; n <= 20000; n += 1000) {
        long long totalTime = 0;
        
        for (int iter = 0; iter < trials; iter++) {
            vector<int> arr(n);
            for (int i = 0; i < n; i++) {
                arr[i] = rand() % 10000;
            }
            
            auto start = high_resolution_clock::now();
            quickSort(arr, 0, arr.size() - 1);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            
            totalTime += duration.count();
        }
        
        double averageTimeMs = (totalTime / trials) / 1e6;
        fout << n << "," << averageTimeMs << endl;
        cout << "n: " << n << ", Average Time: " << averageTimeMs << " ms" << endl;
    }
    
    fout.close();
    return 0;
}
