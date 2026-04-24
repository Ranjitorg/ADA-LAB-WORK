#include <iostream>
using namespace std;
const int inf = 30;
void printPath(int d[], int n, int src, int i){
 if(i==0){
 cout << i+1 <<" ";
 return;
 }
 printPath(d, n,src,d[i]);
 cout<<i+1<<" ";


}
void UW243116_BMG(int cost[][inf], int n, int src , int dest){
 int mcost[inf], d[inf];
 mcost[src]=0;
 for(int i = src+1; i <= dest; i++){
 mcost[i] = inf;
 }
 for(int j = src; j < dest; j++){
 for(int r = j+1; r < n; r++){
 if(cost[j][r]!=0 && (mcost[r] > (cost[j][r]+mcost[j]))){
 mcost[r] = cost[j][r]+mcost[j];
 d[r]=j;
 }
 }
 }

 cout<<"Minimum cost path : ";
 printPath(d,n,src,n-1);
 cout<<"\nminimum cost : "<<mcost[dest];

}
int main() {
 int cost[inf][inf]={
 {0, 2, 6, 4, 0, 0, 0},
 {0, 0, 0, 0, 0, 3, 0},
 {0,0,0,0,1,7,0},
 {0,0,0,0,5,0,0},
 {0,0,0,0,0,0,6},
 {0,0,0,0,0,0,8},
 {0,0,0,0,0,0,0}

 };
 UW243116_BMG(cost,7,0,6);
 return 0;

}
