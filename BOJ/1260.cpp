#include <iostream>
#include <queue>
using namespace std;
bool graph[1001][1001] = { { 0, }, };
bool visited[1001] = { 0, };
int N, M, V, temp1, temp2;
void dfs(int V) {
	cout << V << " ";
	visited[V] = 1;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1 || graph[V][i] == 0) continue;
		dfs(i);
	}
}
void bfs(int V) {
	queue<int> q;
	q.push(V);
	visited[V] = 1;
	while (!q.empty()) {
		V = q.front();
		cout << V << " ";
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 1 || graph[V][i] == 0) continue;
			q.push(i);
			visited[i] = 1;
		}
	}
}
int main() {
	cin >> N >> M >> V;
	while (M--) {
		cin >> temp1 >> temp2;
		graph[temp1][temp2] = 1;
		graph[temp2][temp1] = 1;
	}
	dfs(V);
	cout << "\n";
	for (int i = 1; i <= N; i++) visited[i] = 0;
	bfs(V);
}