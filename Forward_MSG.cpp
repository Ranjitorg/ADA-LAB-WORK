#include <iostream>
using namespace std;
const int inf = 30;
void UE243116_FMG(int cost[][inf], int n, int src , int dest){
 int mcost[inf], d[inf];
 mcost[dest]=0;

 for(int j = dest-1; j >= src; j--){
 mcost[j]=inf;
 for(int r = j+1; r < n; r++){
 if(cost[j][r]!=0 && (mcost[j] > (cost[j][r]+mcost[r]))){
 mcost[j] = cost[j][r]+mcost[r];
 d[j]=r;
 }
 }
 }
 int i = src;
 cout<<"Minimum cost path : "<<i+1;
 do{
 i = d[i];
 cout<<"->"<<i+1;

 }while(i!=dest);
 cout<<"\nminimum cost : "<<mcost[src];

}
int main() {
 int cost[inf][inf]={
 {0, 2, 5, 7, 0, 0, 0},
 {0, 0, 0, 0, 0, 3, 0},
 {0,0,0,0,4,12,0},
 {0,0,0,0,8,0,0},
 {0,0,0,0,0,0,6},
 {0,0,0,0,0,0,11},
 {0,0,0,0,0,0,0}

 };
 UE243116_FMG(cost,7,0,6);
 return 0;
}
