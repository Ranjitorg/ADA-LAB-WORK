#include <iostream>
using namespace std;
int UE243116_knapsack(int weights[], int values[], int n, int capacity) {

 int dp[n + 1][capacity + 1];
 for (int i = 0; i <= n; i++) {
 for (int w = 0; w <= capacity; w++) {
 if (i == 0 || w == 0) {
 dp[i][w] = 0;
 } else if (weights[i - 1] <= w) {
 dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
 } else {
 dp[i][w] = dp[i - 1][w];
 }
 }
 }
 return dp[n][capacity];
}
int main() {
 int weights[] = {10, 20, 30};
 int values[] = {60, 100, 120};
 int capacity = 50;
 int n = sizeof(weights) / sizeof(weights[0]);
 cout << "Maximum Value: " << UE243116_knapsack(weights, values, n, capacity) << endl;
 return 0;
}
