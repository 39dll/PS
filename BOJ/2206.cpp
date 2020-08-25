#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int N, M;
bool visited[1002][1002][2] = { 0 }, map[1002][1002] = { 0 };
int cnt[1002][1002][2] = { 0 };
char input[1002], dirx[4] = { 1,-1,0,0 }, diry[4] = { 0,0,1,-1 };
int res = 0;
queue<tuple<int, int, bool> > q;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		for (int j = 1; j <= M; j++) {
			map[i][j] = input[j - 1] - '0';
		}
	}
	q.push(make_tuple(1, 1, 0));
	cnt[1][1][0] = 1;
	visited[1][1][0] = 1;
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		bool broken = get<2>(q.front());
		if (x == N && y == M) break;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dirx[i];
			int ny = y + diry[i];
			if (map[nx][ny] == 1 && !visited[nx][ny][1] && broken == 0) {
				q.push(make_tuple(nx, ny, 1));
				visited[nx][ny][1] = 1;
				cnt[nx][ny][1] = cnt[x][y][0] + 1;
			}
			for (int j = 0; j < 2; j++) {
				if (map[nx][ny] == 0 && !visited[nx][ny][j] && broken == j && nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
					q.push(make_tuple(nx, ny, j));
					visited[nx][ny][j] = 1;
					cnt[nx][ny][j] = cnt[x][y][j] + 1;
				}
			}
		}
	}
	res = max(cnt[N][M][0], cnt[N][M][1]);
	if (cnt[N][M][0] == 0 && cnt[N][M][1] == 0) {
		cout << "-1";
		return 0;
	}
	cout << res;
}