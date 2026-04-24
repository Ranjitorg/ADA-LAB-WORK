#include <iostream>
using namespace std;
const int INF = 100;
void UE243116_Dijkstra(int startNode, int endNode, int cost[][INF], int numNodes){
 int distance[INF];
 bool visited[INF];
 int parent[INF];
 for(int i = 0; i < numNodes; i++){
 distance[i] = INF;
 visited[i] = false;
 parent[i] = -1;
 }

 distance[startNode] = 0;

 for(int j = 0; j < numNodes; j++){
 int minNode = -1;
 int minDistance = INF;
 for(int i = 0; i < numNodes; i++){
 if(!visited[i] && distance[i] < minDistance){
 minDistance = distance[i];
 minNode = i;
 }
 }

 if(minNode == -1) break;

 int current = minNode;
 visited[current] = true;


 for(int i = 0; i < numNodes; i++){
 if(cost[current][i] != INF && !visited[i] && distance[i] > (cost[current][i] + distance[current])){

 distance[i] = cost[current][i] + distance[current];
 parent[i] = current;

 }
 }
 }


 cout << "Path: ";
 int current = endNode;
 if (distance[endNode] == INF) {
 cout << "No path" << endl;
 } else {
 while(current != -1){
 cout << current << " ";
 current = parent[current];
 }
 cout << "\nTotal cost: " << distance[endNode] << endl;
 }
}
int main() {

 int graphMatrix[INF][INF] = {
 {INF, 2,INF, 6, INF},
 {2, INF, 3, 8, 5},
 {INF, 3, INF, INF, 7},
 {6, 8, INF, INF, 9},
 {INF, 5, 7, 9, INF}


 };
 UE243116_Dijkstra(0,4,graphMatrix,5);
 return 0;
}
