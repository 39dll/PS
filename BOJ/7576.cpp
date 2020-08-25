#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
int M, N, res = 0, tom[1002][1002] = { 0 }, st[1002][1002] = { 0 };
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
queue<pair<int, int> > q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i <= 3; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && nx <= N && ny <= M && ny >= 1) {
				if (st[nx][ny] == 0 && tom[nx][ny] == 0) {
					st[nx][ny] = st[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> tom[i][j];
			if (tom[i][j] == 1) {
				st[i][j] = 1;
				q.push(make_pair(i, j));
			}
		}
	}
	bfs();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			res = max(res, st[i][j]);
			if (tom[i][j] == 0 && st[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}
	cout << res - 1;
}
