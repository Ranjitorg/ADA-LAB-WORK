#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;
using namespace std::chrono;

int binarySearchRecursive243116(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] < target) {
        return binarySearchRecursive243116(arr, mid + 1, right, target);
    }
    return binarySearchRecursive243116(arr, left, mid - 1, target);
}


int main() {
    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int minN, maxN;
    cout << "Enter minimum number of elements: ";
    cin >> minN;
    cout << "Enter maximum number of elements: ";
    cin >> maxN;

    if (minN <= 0 || maxN <= 0) {
        cout << "Array sizes must be positive." << endl;
        return 1;
    }
    if (minN > maxN) {
        swap(minN, maxN);
    }

    srand(time(0)); 
    string filename = "d:\\Downloads\\Algorithim\\binary_search.txt";
    ofstream fout(filename);
    fout << "n time_ns" << endl;

    for (int n = minN; n <= maxN; n++) {
        cout << "\nArray size = " << n << endl;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }
        sort(arr.begin(), arr.end());

        cout << "Sorted array: ";
        for (int value : arr) {
            cout << value << " ";
        }
        cout << endl;

        auto start = high_resolution_clock::now();
        int result = binarySearchRecursive243116(arr.data(), 0, n - 1, target);
        auto end = high_resolution_clock::now();
        auto duration1 = duration_cast<nanoseconds>(end - start);

        if (result != -1) {
            cout << "Element found at index " << result << endl;
        } else {
            cout << "Element not found" << endl;
        }

        cout << "Time taken by Binary Search: " << duration1.count() << " nanoseconds" << endl;
        fout << n << " " << duration1.count() << endl;
    }

    return 0;
}