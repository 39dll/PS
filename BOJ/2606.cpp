#include <iostream>
#include <queue>
using namespace std;
bool connected[101][101] = { { 0, }, }, visited[101] = { 0, };
int N, M, temp1, temp2, cnt = 0;
void dfs(int a) {
	visited[a] = 1; cnt++;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1 || connected[a][i] == 0) continue;
		dfs(i);
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> temp1 >> temp2;
		connected[temp1][temp2] = connected[temp2][temp1] = 1;
	}
	dfs(1);
	if (cnt >= 1) cout << cnt - 1;
	else cout << 0;
}