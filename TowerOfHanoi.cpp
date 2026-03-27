#include<iostream>
#include<chrono>
#include<stack>
using namespace std;
using namespace std::chrono;

void towerOfHanoi(int discs, stack<int> &src, stack<int> &helper, stack<int> &dest){
    if(discs == 0)  return;
    towerOfHanoi(discs-1, src, dest, helper);
    dest.push(src.top());
    src.pop();
    towerOfHanoi(discs-1, helper, src, dest);
}

int main(){
    int minDiscs = 2;
    int maxDiscs = 10;
    int interval = 2;
    int repetitions = 3;
    stack<int> src, helper, dest;
    long long timings[100000];
    for(int discs = minDiscs ; discs <= maxDiscs; discs += interval){
        long long totalTime = 0;

        for(int rep = 1; rep <= repetitions; rep++){
            while(!dest.empty()){
                dest.pop();
            }
            while(!src.empty()){
                src.pop();
            }
            while(!helper.empty()){
                helper.pop();
            }
            for(int d = discs; d >= 1; d--){
                src.push(d);
            }
            
            auto tStart = system_clock::now();
            towerOfHanoi(discs, src, helper, dest);
            auto tEnd = system_clock::now();
            totalTime += duration_cast<nanoseconds>(tEnd-tStart).count();
        }
        cout<<"Average duration for "<<discs<<" discs: "<<totalTime/repetitions<<" nanoseconds"<<endl;
    }
}