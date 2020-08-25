#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int M, N;
int dp[500][500];
int map[500][500];
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
int go(int x, int y) {
	if (x == 0 && y == 0) return 1;
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
			if (map[nx][ny] > map[x][y]) {
				dp[x][y] += go(nx, ny);
			}
		}
	}
	return dp[x][y];
}
int main() {
	cin >> M >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	cout << go(M - 1, N - 1);
}