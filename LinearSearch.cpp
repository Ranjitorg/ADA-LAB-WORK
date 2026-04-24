#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>

using namespace std;
using namespace std::chrono;

int UE243116_linearSearch(int arr[], int n, int key, int i) {
    if (i == n) return -1;
    if (arr[i] == key) return i;
    return UE243116_linearSearch(arr, n, key, i + 1);
}

double UE243116_timeLinearSearch(int n, int target, int trials) {
    int* arr = new int[n];
    double avg = 0.0;

    for (int t = 0; t < trials; ++t) {
        for (int j = 0; j < n; ++j) arr[j] = j;
        auto start = high_resolution_clock::now();
        int ans = UE243116_linearSearch(arr, n, target, 0);
        auto end = high_resolution_clock::now();
        avg += duration_cast<nanoseconds>(end - start).count() / 1e6; 
    }
    delete[] arr;
    return avg / trials;
}

int main() {
    int trials = 1000;
    ofstream fout("d:\\Downloads\\Algorithim\\LABS\\MAIN\\LS_output.txt");
    fout << "n,time_ms" << endl; 
    for (int n = 1000; n <= 22000; n += 2000) {
        int target = n - 1; // Last element
        double avgTime = UE243116_timeLinearSearch(n, target, trials);
        fout << n << "," << avgTime << endl;
    }
    fout.close();
}