#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <tuple>
#include <queue>
#include <string.h>
using namespace std;
typedef tuple<int, int, int> t; //가중치, x좌표, y좌표
priority_queue<t, vector<t>, greater<t> > pq;
int N, M, L, R, Px, Py, left, right;//left = 왼쪽 가중치 = 1, right = 오른쪽 가중치 = 10000
int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };
int c[1002][1002], cnt = 0;
bool map[1002][1002];
char input[1002];
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL);
	memset(c, -1, sizeof(c)); memset(map, 1, sizeof(map));
	cin >> N >> M >> L >> R;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		for (int j = 1; j <= M; j++) {
			if (input[j - 1] == '2') {
				map[i][j] = 0;
				pq.push({ 0,i,j });
			}
			else map[i][j] = input[j - 1] - '0';
		}
	}
	while (!pq.empty()) {
		int cost = get<0>(pq.top());
		int x = get<1>(pq.top());
		int y = get<2>(pq.top());
		pq.pop();
		if (c[x][y] != -1) continue;
		c[x][y] = cost;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int newcost = cost;
			if (i == 0) newcost += 10000;
			else if (i == 1) newcost += 1;
			if (map[nx][ny] != 1) {
				if (c[nx][ny] == -1)pq.push({ newcost, nx, ny });
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (c[i][j] == -1) continue;
			if (c[i][j] / 10000 <= R && c[i][j] % 10000 <= L) cnt++;
		}
	}
	cout << cnt;
}