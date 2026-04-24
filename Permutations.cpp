#include <bits/stdc++.h>
#include<chrono>
using namespace std::chrono;
using namespace std;


void UE243116_Permutation(string s ,int idx){

    if(idx==s.length()-1){

       return;

    }

    for(int i=idx;i<s.length();i++){

         char temp=s[i];
         s[i]=s[idx];
         s[idx]=temp;

         UE243116_Permutation(s,idx+1);

         temp=s[i];
         s[i]=s[idx];
         s[idx]=temp;


    }


}
int main() {

    ofstream file("UE243116_Permutation.txt");

    file<<" n,time\n";


    for(int n=1;n<=10;n+=1){

        string s(n,'a');

        for(int i=0;i<n;i++){

            s[i]='a'+i;
        }

        int repeats=5;
        auto start =high_resolution_clock::now();

        for(int i=0;i<repeats;i++){
            UE243116_Permutation(s,0);
        }

        auto end = high_resolution_clock::now();

        auto time = duration_cast<nanoseconds>(end-start).count()/repeats;

        file<<n<<","<<time<<"\n";

        cout<<"Run for n ="<<n<<endl;


    }
    file.close();


    return 0;
}
