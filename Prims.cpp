#include <iostream>
using namespace std;
const int max_size = 100;
const int inf = 10000;
void UE243116_prims(int cost[max_size][max_size], int n) {
 int near[max_size];
 int visited[max_size] = {0};
 int totalCost = 0;
 int sol[max_size][3];

 visited[0] = 1;
 for (int i = 0; i < n; i++) {
 if (i == 0) near[i] = -1;
 else near[i] = 0;
 }

 for (int i = 0; i < n - 1; i++) {
 int minCost = inf;
 int k = -1;

 for (int j = 0; j < n; j++) {
 if (!visited[j] && near[j] != -1 && cost[j][near[j]] < minCost) {
 minCost = cost[j][near[j]];
 k = j;
 }
 }
 if (k != -1) {
 sol[i][0] = k;
 sol[i][1] = near[k];
 sol[i][2] = minCost;
 totalCost += minCost;
 visited[k] = 1;
 for (int j = 0; j < n; j++) {
 if (!visited[j] && cost[j][k] < cost[j][near[j]]) {
 near[j] = k;
 }
 }
 }
 }

 for (int i = 0; i < n - 1; i++) {
 cout << sol[i][0] << " - " << sol[i][1] << " : " << sol[i][2] << endl;
 }
 cout << "Total cost : " << totalCost;
}
int main() {
 int arr[max_size][max_size] = {
 {inf, 4, 1, inf, inf},
 {4, inf, 2, 6, inf},
 {1, 2, inf, 3, 5},
 {inf, 6, 3, inf, 7},
 {inf, inf, 5, 7, inf}
 };
 UE243116_prims(arr, 5);
 return 0;
}