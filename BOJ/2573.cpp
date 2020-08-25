#include <iostream>
#include <cstring>
using namespace std;
int N, M, gla[301][301], upd[301][301];
bool visited[301][301];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
void search(int x, int y) {
	if (visited[x][y]) return;
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && gla[nx][ny] && !visited[nx][ny]) {
			search(nx, ny);
		}
	}
}
bool check() {
	memset(visited, 0, sizeof(visited));
	bool flag = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (gla[i][j] && !visited[i][j]) {
				if (flag == 1) return 1;
				search(i, j);
				flag = 1;
			}
		}
	}
	return 0;
}
void update() {
	memset(upd, 0, sizeof(upd));
	for (int i = 2; i < N; i++) {
		for (int j = 2; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				if (gla[i + dx[k]][j + dy[k]] == 0)upd[i][j]++;
			}
		}
	}
	for (int i = 2; i < N; i++) {
		for (int j = 2; j < M; j++) {
			if (gla[i][j] != 0) {
				gla[i][j] -= upd[i][j];
				if (gla[i][j] < 0)gla[i][j] = 0;
			}
		}
	}
}
int sum() {
	int a = 0;
	for (int i = 2; i < N; i++) {
		for (int j = 2; j < M; j++) {
			a += gla[i][j];
		}
	}
	return a;
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> gla[i][j];
		}
	}
	for (int i = 0; i < 1000000; i++) {
		if (check()) {
			cout << i;
			return 0;
		}
		update();
		if (sum() == 0) {
			cout << 0;
			return 0;
		}
	}
	cout << 0;
}