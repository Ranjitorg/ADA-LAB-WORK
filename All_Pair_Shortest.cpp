#include <iostream>
using namespace std;
const int MaxSize = 100;
void UE243116_printShortPath(int S[][MaxSize], int i, int j, int A[][MaxSize], int cost[][MaxSize], bool
both=true){
 if(i ==j) return;
 else if(cost[i][j]!= MaxSize && both){
 cout<<"->"<<i+1<<"->"<<j+1;
 return;
 }
 else if(cost[i][j]!= MaxSize && !both){
 cout<<"->"<<j+1;
 return;
 }

 UE243116_printShortPath(S,i,S[i][j],A,cost);
 UE243116_printShortPath(S,S[i][j],j,A,cost,false);

}
void UE243116_ALLshortPaths(int cost[][MaxSize],int n){
 int A[MaxSize][MaxSize],S[MaxSize][MaxSize];
 for(int i = 0; i < n; i++){
 for(int j = 0; j < n; j++){
 A[i][j] = cost[i][j];
 S[i][j]=-1;
 }
 }


 for(int i =0; i < n; i++){
 for(int j = 0; j < n; j++){
 for(int k =0; k < n; k++){
 if(A[i][j] > A[i][k]+A[k][j]){
 A[i][j]= A[i][k]+A[k][j];
 S[i][j]=k;
 }
 }
 }
 }


 cout<<"\nGraph given : "<<endl;
 for(int i = 0; i < n; i++){
 for(int j =0; j < n; j++){
 cout<<cost[i][j]<<" ";
 }
 cout<<endl;
 }


 cout<<"\nShortest Path Matrix :-"<<endl;
 for(int i = 0; i < n; i++){
 for(int j =0; j < n; j++){
 cout<<A[i][j]<<" ";
 }
 cout<<endl;
 }

 cout<<"\nShortest Paths :-"<<endl;
 for(int i =0; i < n; i++){
 for(int j =0; j < n; j++){
 if(i!=j){
 cout<<"\n[ "<<i+1<<" , "<<j+1<<" ] : ";
 UE243116_printShortPath(S,i,j,A,cost);

 }

 }
 }
}
int main() {
 int cost[][MaxSize]={{0,4,11},{6,0,2},{3,MaxSize,0}};
 UE243116_ALLshortPaths(cost,3);
 return 0;
}
