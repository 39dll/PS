#include <iostream>
#include <algorithm>
using namespace std;
int m[501][501], mx, N, M;
void search(int x, int y) {
	if (x < N - 2) {
		mx = max(mx, m[x][y] + m[x + 1][y] + m[x + 2][y] + m[x + 3][y]);
	}
	if (y < M - 2) {
		mx = max(mx, m[x][y] + m[x][y + 1] + m[x][y + 2] + m[x][y + 3]);
	}
	if (x < N && y < M) {
		mx = max(mx, m[x][y] + m[x + 1][y] + m[x][y + 1] + m[x + 1][y + 1]);
	}
	if (x < N && y < M - 1) {
		mx = max(mx, m[x][y] + m[x][y + 1] + m[x][y + 2] + m[x + 1][y + 2]);
		mx = max(mx, m[x][y] + m[x + 1][y] + m[x + 1][y + 1] + m[x + 1][y + 2]);
		mx = max(mx, m[x][y] + m[x][y + 1] + m[x][y + 2] + m[x + 1][y]);
		mx = max(mx, m[x][y] + m[x][y + 1] + m[x + 1][y + 1] + m[x + 1][y + 2]);
		mx = max(mx, m[x][y] + m[x][y + 1] + m[x][y + 2] + m[x + 1][y + 1]);
		mx = max(mx, m[x + 1][y] + m[x + 1][y + 1] + m[x + 1][y + 2] + m[x][y + 2]);
		mx = max(mx, m[x + 1][y] + m[x + 1][y + 1] + m[x][y + 1] + m[x][y + 2]);
		mx = max(mx, m[x + 1][y] + m[x][y + 1] + m[x + 1][y + 1] + m[x + 1][y + 2]);
	}
	if (x < N - 1 && y < M) {
		mx = max(mx, m[x][y] + m[x + 1][y] + m[x + 2][y] + m[x][y + 1]);
		mx = max(mx, m[x][y] + m[x + 1][y] + m[x + 2][y] + m[x + 2][y + 1]);
		mx = max(mx, m[x][y] + m[x][y + 1] + m[x + 1][y + 1] + m[x + 2][y + 1]);
		mx = max(mx, m[x][y] + m[x + 1][y] + m[x + 1][y + 1] + m[x + 2][y + 1]);
		mx = max(mx, m[x][y] + m[x + 1][y] + m[x + 2][y] + m[x + 1][y + 1]);
		mx = max(mx, m[x + 2][y] + m[x][y + 1] + m[x + 1][y + 1] + m[x + 2][y + 1]);
		mx = max(mx, m[x][y + 1] + m[x + 1][y + 1] + m[x + 1][y] + m[x + 2][y]);
		mx = max(mx, m[x + 1][y] + m[x][y + 1] + m[x + 1][y + 1] + m[x + 2][y + 1]);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			search(i, j);
		}
	}
	cout << mx;
}