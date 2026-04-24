#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std::chrono;
using namespace std;

void merge(vector<int>& arr, int start, int mid, int end) { 
    vector<int> temp;
    int i = start;
    int j = mid + 1; 
    while (i <= mid && j <= end) { 
        if (arr[i] <= arr[j]) { 
            temp.push_back(arr[i]); 
            i++; } else {
            temp.push_back(arr[j]); 
            j++; }}
    while (i <= mid) { 
        temp.push_back(arr[i]);
        i++;}
    while (j <= end) { 
        temp.push_back(arr[j]);
        j++; }
    for (int k = start; k <= end; k++) { 
        arr[k] = temp[k - start]; } }

void mergeSort(vector<int>& arr, int start, int end) { 
    if (start < end) { 
        int mid = start + (end - start) / 2; 
        mergeSort(arr, start, mid); 
        mergeSort(arr, mid + 1, end); 
        merge(arr, start, mid, end); 
    }
}

double timeMergeSort(int n, int trials) {
    long long totalTime = 0;
    
    for (int iter = 0; iter < trials; iter++) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 10000;
        }
        
        auto start = high_resolution_clock::now();
        mergeSort(arr, 0, arr.size() - 1);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);
        
        totalTime += duration.count();
    }
    
    return totalTime / (trials * 1000000.0); // Convert nanoseconds to milliseconds
}

int main() {
    ofstream fout("outputMS.txt");
    fout << "n,time_ms" << endl; 
    
    int trials = 10;
    for (int n = 1000; n <= 20000; n += 1000) {
        double avgTime = timeMergeSort(n, trials);
        fout << n << "," << avgTime << endl;
        cout << "n = " << n << ", time = " << avgTime << " ms" << endl;
    }
    
    fout.close();
    
    return 0;
}
