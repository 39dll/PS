#include <iostream>
#include <algorithm>
using namespace std;
int ans, R, C;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
char map[22][22];
bool used[27];
void search(int x, int y, int cnt) {
	ans = max(ans, cnt);
	for (int q = 0; q < 4; q++) {
		int nx = x + dx[q];
		int ny = y + dy[q];
		if (nx >= 1 && nx <= R && ny >= 1 && ny <= C) {
			if (!used[map[nx][ny] - 'A']) {
				used[map[nx][ny] - 'A'] = 1;
				search(nx, ny, cnt + 1);
				used[map[nx][ny] - 'A'] = 0;
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
		}
	}
	used[map[1][1] - 'A'] = 1;
	search(1, 1, 1);
	cout << ans;
}