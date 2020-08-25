#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
int M, N, H, res = 0, tom[102][102][102] = { 0 }, st[102][102][102] = { 0 };
int dx[6] = { 0, 0, 1, -1, 0, 0 }, dy[6] = { 1, -1, 0, 0, 0, 0 }, dz[6] = { 0, 0, 0, 0, 1, -1 };
queue<tuple<int, int, int> > q;
void bfs() {
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());
		q.pop();
		for (int i = 0; i <= 5; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx >= 1 && nx <= H && ny <= N && ny >= 1 && nz >= 1 && nz <= M) {
				if (st[nx][ny][nz] == 0 && tom[nx][ny][nz] == 0) {
					st[nx][ny][nz] = st[x][y][z] + 1;
					q.push(make_tuple(nx, ny, nz));
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				cin >> tom[i][j][k];
				if (tom[i][j][k] == 1) {
					st[i][j][k] = 1;
					q.push(make_tuple(i, j, k));
				}
			}
		}
	}
	bfs();
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				res = max(res, st[i][j][k]);
				if (tom[i][j][k] == 0 && st[i][j][k] == 0) {
					cout << "-1";
					return 0;
				}
			}
		}
	}
	cout << res - 1;
}
