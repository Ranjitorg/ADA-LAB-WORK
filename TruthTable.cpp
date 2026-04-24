#include<iostream>
using namespace std;

void truthTable(int numvarUE243116, string assignment = ""){
    if( numvarUE243116 == 0 ){
        cout << assignment << endl;
        return;
    }
    
    truthTable(numvarUE243116 - 1, assignment + 'T');
    truthTable(numvarUE243116 - 1, assignment + 'F');
}

int main(){
    for (int numvarUE243116 = 2; numvarUE243116 <= 5; ++numvarUE243116) {
        cout << "Truth table for " << numvarUE243116 << " variables:\n";
        truthTable(numvarUE243116);
        cout << endl;
    }
    return 0;
}