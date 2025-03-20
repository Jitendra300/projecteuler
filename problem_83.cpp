#include<bits/stdc++.h>
using namespace std;

#define nl "\n"

int ans = INT_MAX;

const int SAFE_SIZE = 85;
const int SAFE_SIZE_ADJ = 6500;
int SIZE;
int grid[SAFE_SIZE][SAFE_SIZE];
int dist[SAFE_SIZE_ADJ];
bool visited[SAFE_SIZE_ADJ];
vector<pair<int, int>> adj[SAFE_SIZE_ADJ];


void dijkstar(int node, int weight){
  dist[node] = weight;
  priority_queue<pair<int, int>> q;
  q.push({weight, node});
  while(!q.empty()){
	int a = q.top().second; q.pop();
	if(visited[a]) continue;
	visited[a] = true;
	for(auto u: adj[a]){
	  int b = u.first, w = u.second;
	  if(dist[a]+w < dist[b]){
		dist[b] = dist[a] + w;
		q.push({-dist[b], b});
	  }
	}
  }
}

void Graph_Idea(){
  cin >> SIZE;
  // taking in input from file...; and putting in grid;
  for(int i=0;i<SIZE;++i){
	for(int j=0;j<SIZE;++j){
	  cin >> grid[i][j];
	}
  }

  // making one adj list i.e a graph
  for(int i=0;i<SIZE;++i){
	for(int j=0;j<SIZE;++j){
	  if(i*SIZE+j - SIZE >= 0 && i-1 >= 0) adj[i*SIZE + j].push_back({(i*SIZE+j - SIZE), grid[i-1][j]});
	  if(i*SIZE+j + SIZE <= SIZE*SIZE - 1 && i+1 <SIZE) adj[i*SIZE + j].push_back({(i*SIZE+j + SIZE), grid[i+1][j]});
	  if(i*SIZE+j+1 <= i*SIZE + (SIZE-1) && j+1 < SIZE) adj[i*SIZE + j].push_back({(i*SIZE+j + 1), grid[i][j+1]});
	  if(i*SIZE+j-1 >= 0 && j-1 >= 0) adj[i*SIZE + j].push_back({(i*SIZE+j - 1), grid[i][j-1]});
	}
  }

  for(int i=0;i<SAFE_SIZE_ADJ;++i){
	visited[i] = false;
	dist[i] = INT_MAX;
  }
  
  dijkstar(0, grid[0][0]);
  
  cout <<  dist[SIZE*(SIZE-1) + SIZE-1] << nl;
}

int main(){
  Graph_Idea();
  return 0;
}
