#include <iostream>
#include <vector>
using namespace std;
const int inf = 100;
int UE243116_salesmanProblem(vector<vector<int>> cost, vector<int> s, int pos, vector<int> &sol){
 if(s.size() == 0){
 return cost[pos-1][0];
 }
 vector<int> s1;
 for(int i : s){
 if( i != pos){
 s1.push_back(i);
 }
 }

 int ver;
 int MinCost = inf;
 for(int i : s){
 int x = cost[pos-1][i-1]+UE243116_salesmanProblem(cost,s1,i,sol);
 if(MinCost > x){
 MinCost = x;
 ver = i;
 }
 }


 return MinCost;
}
int main() {
 vector<vector<int>> cost = {{0, 10, 15,20},
 {5, 0, 9, 10},
 {6, 13, 0, 12},
 {8, 8, 9, 0}};
 vector<int> s = {1,2,3,4};
 vector<int> v;

 cout<<"Minimum cost : "<<UE243116_salesmanProblem(cost,s,1,v)<<endl;

 for(int i : v){

 cout<<i<<" ";
 }
 return 0;
}
