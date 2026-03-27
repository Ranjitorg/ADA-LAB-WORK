#include <iostream>
using namespace std;
void UE243116_nConsecutive(int arr[], int n){
 for( int i =0; i < n-1; i++){
 if((arr[i]&1) == (arr[i+1]&1)){
 cout<<arr[i]+1;
 return;
 }
 }
}
int main() {

 int n;
 int arr[100];
 cout<<"Enter the size of array : ";
 cin>>n;
 cout<<"Enter the array : ";
 for(int i = 0; i < n; i++){
 cin>>arr[i];
 }
 cout<<"Missing value : ";
 UE243116_nConsecutive(arr,5);
 return 0;
}