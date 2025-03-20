#include<bits/stdc++.h>
using namespace std;

class Disjoint{
  vector<int> parent, size;

 public:
  Disjoint(int n){
	parent.resize(n+1);
	size.resize(n+1, 1);
	for(int i=0;i<=n;++i) parent[i] = i;
  }

  int findUpar(int node){
	if(node == parent[node]) return node;
	return parent[node] = findUpar(parent[node]);
  }

  void unionBySize(int u, int v){
	int ulp_u = findUpar(u);
	int ulp_v = findUpar(v);
	if(ulp_u == ulp_v) return;
	if(size[ulp_u] < size[ulp_v]){
	  parent[ulp_u] = ulp_v;
	  size[ulp_v] += size[ulp_u];
	}
	else{
	  parent[ulp_v] = ulp_u;
	  size[ulp_u] += size[ulp_v];
	}
  }
};

int graph[50][50];

void algo(){
  Disjoint ds(40);
  int totalGraphWeight=0;
  vector<pair<int, pair<int, int>>> sortedArray;

  int n; cin >> n;

  for(int i=1;i<=n;++i){
	for(int j=1;j<=n;++j){
	  cin >> graph[i][j];
	  totalGraphWeight += graph[i][j];
	}
  }
  
  totalGraphWeight /= 2; // cause we have double counted...

  for(int i=1;i<=n;++i){
	for(int j=1;j<=n;++j){
	  if(i == j) continue;
	  if(graph[i][j] == 0) continue;
	  sortedArray.push_back({graph[i][j], {i, j}});
	}
  }

  int minimalWeight = 0;

  sort(sortedArray.begin(), sortedArray.end());
  int ithElement = 0;

  while(ithElement < sortedArray.size()){
	int u = sortedArray[ithElement].second.first;
	int v = sortedArray[ithElement].second.second;
	if((ds.findUpar(u) != ds.findUpar(v))){
	  int weight = sortedArray[ithElement].first;
	  minimalWeight += weight;
	  ds.unionBySize(u, v);
	}
	ithElement++;
  }

  cout << totalGraphWeight-minimalWeight << "\n";
}

int main(){
  algo();
  return 0;
}
