#include <iostream>
using namespace std;
void MinMax(int arr[], int l, int r, int &UE243116_min1, int &UE243116_max1){
 if(l==r){
 UE243116_min1 = arr[l];
 UE243116_max1 = arr[l];
 return;
 }
 if(l==r+1){
 if(arr[l] > arr[r]){
 UE243116_min1 = arr[r];
 UE243116_max1 = arr[l];

 }
 else{
 UE243116_min1 = arr[l];
 UE243116_max1 = arr[r];

 }
 }
 int mid = (l+r)/2;
 int LMin;
 int LMax;
 int RMin;
 int RMax;
 MinMax(arr,l,mid,LMin, LMax);
 MinMax(arr,mid+1,r,RMin, RMax);
 UE243116_min1 = min(LMin, RMin);
 UE243116_max1 = max(LMax, RMax);
}
int main() {
 int n;
 int arr[100];
 cout<<"Enter the size of array : ";
 cin>>n;
 cout<<"Enter the array : ";
 for(int i =0;i < n; i++){
 cin>>arr[i];
 }
 int UE243116_min1, UE243116_max1;
 MinMax(arr,0,n-1,UE243116_min1,UE243116_max1);
 cout<<"Minimum value : "<<UE243116_min1<<endl;
 cout<<"Maximum value : "<<UE243116_max1<<endl;
 return 0;
}