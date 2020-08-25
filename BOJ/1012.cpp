#include <iostream>
using namespace std;
bool cab[52][52] = { { 0, }, }, checked[52][52] = { { 0, }, }, suc = 0;
int T, M, N, K, cnt = 0, temp1, temp2;
void dfs(int x, int y) {
	if (checked[x][y]) return;
	checked[x][y] = 1;
	if (cab[x][y] == 0) return;
	suc = 1;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}
int main() {
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		while (K--) {
			cin >> temp1 >> temp2;
			cab[temp1 + 1][temp2 + 1] = 1;
		}
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				dfs(i, j);
				if (suc) cnt++;
				suc = 0;
			}
		}
		cout << cnt << "\n";
		cnt = 0;
		for (int i = 0; i <= 51; i++) {
			for (int j = 0; j <= 51; j++) {
				cab[i][j] = 0; checked[i][j] = 0;
			}
		}
	}
}