#include <bits/stdc++.h>
using namespace std;

// This is a easy problem, we just have to find connected components and those are disjoint cites, we just have connnect a node from each 
// component with each other

void dfs(int s, vector<vector<int>> &nodes, vector<bool> &visited)
{
	if(visited[s]) return;
	visited[s] = true;
	for(auto u: nodes[s])
		dfs(u, nodes, visited);
}

int main()
{
	int n, m, k = 0, n1, n2;
	cin >> n >> m;
	vector<vector<int>> nodes(n+1);      // i have used adjacency list for graph representation
	vector<bool> visited(n+1, false);   
	vector<int> ans;                     // this list will contain a node from all connected components   

	for(int i = 0; i < m; ++i)
	{		
		cin >> n1 >> n2;
		nodes[n1].push_back(n2);
		nodes[n2].push_back(n1);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!visited[i]) {
			ans.push_back(i);
			k++;
			dfs(i, nodes, visited);
		}
	}

	cout << k-1 << "\n";
	for(int i = 1; i < ans.size(); ++i)
		cout << ans[i-1] << " " << ans[i] << "\n";

	return 0;
}
