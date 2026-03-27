#include<iostream>
using namespace std;
int UE243116_HornersRule(int arr[],int n,int x, int k=0){
 if(n==(k+1)){
 return arr[k];
 }
 return arr[k]+ x*UE243116_HornersRule(arr,n,x,k+1);
}
int main(){
 int n,x;
 int arr[100];
 cout<<"Enter the length of array : ";
 cin>>n;
 cout<<"Enter the list : ";
 for(int i = 0; i<n; i++){
 cin>>arr[i];

 }
 cout<<"Enter the value of x : ";
 cin>>x;

 cout<<"Output : "<<UE243116_HornersRule(arr,n,x)<<endl;
 return 0;
}