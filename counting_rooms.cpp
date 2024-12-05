#include <bits/stdc++.h>
using namespace std;

// WE JUST HAVE TO FIND NUMBER OF CONNECTED COMPONENTS OF GRAPH HERE

int n, m, count_room = 0;

void dfs(int r, int c, vector<vector<char>> &maze, vector<vector<bool>> &visited)
{
	if(r < 0 || c < 0 || r >= n || c >= m || maze[r][c] == '#' || visited[r][c]) return;
	visited[r][c] = true;
	dfs(r-1, c, maze, visited);
	dfs(r+1, c, maze, visited);
	dfs(r, c-1, maze, visited);
	dfs(r, c+1, maze, visited);
}

int main()
{
	cin >> n >> m;
	vector<vector<char>> maze(n, vector<char>(m));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> maze[i][j];
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(maze[i][j] == '.' && !visited[i][j]) {
				count_room++;
				dfs(i, j, maze, visited);
			}
	cout << count_room;
	return 0;
}
