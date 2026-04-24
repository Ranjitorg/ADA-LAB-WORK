#include<iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

void power(int a, int b){
    int pow = 1;
    int base = a;
    while(b > 0){
        if(b % 2 == 1){
            pow *= base;
        }
        base *= base;
        b /= 2;
    }
    cout<<"result : "<<pow<<endl;
}

double powerRecursive(double x, int n) {
    if (n == 0) return 1.0;
    if (n < 0) return 1.0 / powerRecursive(x, -n);
    double half = powerRecursive(x, n / 2);
    if (n % 2 == 0) {
        return half * half;
    } else {
        return x * half * half;
    }
}

int main(){
    int a;
    cout<<"Base : ";
    cin>>a;
    
    int testValues[] = {1000, 5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000};
    
    for(int b : testValues){
        cout << "\n=== Testing with power: " << b << " ===" << endl;
        
        // Iterative power
        auto start1 = high_resolution_clock::now();
        power(a, b);
        auto end1 = high_resolution_clock::now();
        auto duration1 = duration_cast<nanoseconds>(end1 - start1);
        cout << "Time taken by Power Iterative: " << duration1.count() << " nanoseconds" << endl;
        
        // Recursive power
        auto start2 = high_resolution_clock::now();
        double result = powerRecursive(a, b);
        auto end2 = high_resolution_clock::now();
        auto duration2 = duration_cast<nanoseconds>(end2 - start2);
        cout << "result : " << result << endl;
        cout << "Time taken by Power Recursive: " << duration2.count() << " nanoseconds" << endl;
    }
    
    return 0;
}