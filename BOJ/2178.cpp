#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
bool maze[102][102] = { { 0, }, }, visited[102][102] = { { 0, }, };
int dirx[4] = { 1, -1, 0, 0 }, diry[4] = { 0,0,1,-1 };
int N, M, cnt[102][102] = { { 0, }, };
char str[102];
queue<pair<int, int> > q;
void bfs(int x, int y) {
	visited[x][y] = 1;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (maze[nx + dirx[i]][ny + diry[i]] == 1 && visited[nx + dirx[i]][ny + diry[i]] == 0 && cnt[nx + dirx[i]][ny + diry[i]] == 0) {
				cnt[nx + dirx[i]][ny + diry[i]] = cnt[nx][ny] + 1;
				q.push(make_pair(nx + dirx[i], ny + diry[i]));
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++) {
			maze[i][j] = str[j - 1] - '0';
		}
	}
	bfs(1, 1);
	cout << cnt[N][M] + 1;
}