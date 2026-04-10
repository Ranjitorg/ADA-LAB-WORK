#include <iostream>
using namespace std;
const int inf = 100;
int find(int a, int parent[]){
 if(a==parent[a]) return a;
 return find(parent[a], parent);
}
bool union_set(int u, int v, int parent[], int rank[]){
 int Pu = find(u,parent);
 int Pv = find(v,parent);
 if(Pu != Pv){
 if(rank[Pu] < rank[Pv]) parent[Pu]=Pv;
 else if(rank[Pu] > rank[Pv]) parent[Pv]=Pu;
 else{
 parent[Pu]=Pv;
 rank[Pv]++;
 }
 return true;
 }
 return false;
}
void UE243116_kruskal(int cost[][inf], int n){
 int count = 0, Tcost=0;
 int parent[inf], rank[inf];
 for(int i = 0; i < n; i++) parent[i]=i;
 for(int i = 0; i < n; i++) rank[i]=0;

 do{
 int minIdx,u,v, Minsize=inf;
 for(int i = 0; i < n; i++){
 for(int j = i; j < n; j++){
 if(Minsize > cost[i][j]){
 u = i;
 v = j;
 Minsize = cost[i][j];
 }
 }
 }
 if(union_set(u,v,parent,rank)){

 Tcost += cost[u][v];
 count++;
 cout<<u<<'\t'<<v<<'\t'<<'-'<<'\t'<<cost[u][v]<<endl;
 cost[u][v]=inf;
 }

 }while(count != n-1);
 cout<<"Total cost : "<<Tcost<<endl;
}
int main() {

 int arr[inf][inf] = {
 {inf, 2, inf, 6, inf},
 {2, inf, 3, 8, 5},
 {inf, 3, inf, inf, 7},
 {6, 8, inf, inf, 9},
 {inf, 5, 7, 9, inf}


 };
 UE243116_kruskal(arr,5);
 return 0;
}