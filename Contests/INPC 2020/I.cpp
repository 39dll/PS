#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef tuple<int, int, int> t;
bool visited[101][101], good;
int obs[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue<t> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int H, W, O, F, Xs, Ys, Xe, Ye;
		cin >> H >> W >> O >> F >> Xs >> Ys >> Xe >> Ye;
		memset(obs, 0, sizeof(obs));
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < O; i++) {
			int in1, in2, in3;
			cin >> in1 >> in2 >> in3;
			obs[in1][in2] = in3;
		}
		good = 0;
		while (!q.empty())q.pop();
		q.push({ Xs, Ys, F });
		while (!q.empty()) {
			int curX = get<0>(q.front());
			int curY = get<1>(q.front());
			int curF = get<2>(q.front());
			q.pop();
			if (curX == Xe && curY == Ye) {
				good = 1;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = curX + dx[i];
				int ny = curY + dy[i];
				int nf = curF;
				if (nx <= 0 || nx > H || ny <= 0 || ny > W)continue;
				if (visited[nx][ny])continue;
				if (obs[nx][ny] > nf + obs[curX][curY])continue;
				visited[nx][ny] = 1;
				q.push({ nx,ny,nf - 1 });
			}
		}
		if (good == 1) {
			cout << "잘했어!!\n";
		}
		else cout << "인성 문제있어??\n";
	}
}
