#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> t; //가중치, 시작점, 도착점
int uf[102];
priority_queue<t, vector<t>, greater<t> > pq;
int N, M, in[102][102], board[102][102], cnt;
bool visited[102][102];
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int find(int a) {
	if (uf[a] == a) return a;
	return uf[a] = find(uf[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) uf[b] = a;
}
void search(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;
	board[x][y] = cnt;
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (!visited[nx][ny] && in[nx][ny]) {
				visited[nx][ny] = 1;
				board[nx][ny] = cnt;
				q.push({ nx,ny });
			}
		}
	}
}
void makeEdge(int x, int y) {
	if (board[x][y] == 0)return;
	for (int i = 0; i < 4; i++) {
		int len = 1;
		while (1) {
			int nx = x + len * dx[i];
			int ny = y + len * dy[i];
			if (nx > N || nx <= 0 || ny > M || ny <= 0)break;
			if (board[nx][ny] == 0) {
				len++;
				continue;
			}
			if (board[nx][ny] == board[x][y])break;
			if (len == 2)break;
			pq.push({ len - 1,board[x][y],board[nx][ny] });
			break;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> in[i][j];
		}
	}
	cnt = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (in[i][j] && !visited[i][j]) {
				search(i, j);
				cnt++;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			makeEdge(i, j);
		}
	}

	for (int i = 1; i <= cnt; i++) uf[i] = i;
	int c = 0, ans = 0;
	while (!pq.empty()) {
		if (c == cnt - 1) break;
		int st = get<1>(pq.top());
		int se = get<2>(pq.top());
		int cost = get<0>(pq.top());
		pq.pop();
		if (find(st) == find(se)) continue;
		merge(st, se);
		c++; ans += cost;
	}
	if(c == cnt - 2)cout << ans;
	else cout << -1;
}