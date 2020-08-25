#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> p;
queue<p> q;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
char map[102][102];
bool visited[102][102];
int T, N, M, cnt;
void bfs(int x, int y) {
	q.push({ x,y });
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		if (visited[cx][cy])continue;
		visited[cx][cy] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				if(map[nx][ny]=='#')q.push({ nx,ny });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		cnt = 0;
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (visited[i][j] == 0 && map[i][j] == '#') {
					cnt++;
					bfs(i, j);
				}
			}
		}
		cout << cnt << '\n';
	}
}