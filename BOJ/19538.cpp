#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, in;
vector<int> con[200001];
bool rumor[200001];
int time[200001];
int adj[200001];
queue<int> q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> in;
		while (in != 0) {
			con[i].push_back(in);
			cin >> in;
		}
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> in;
		q.push(in);
		rumor[in] = 1;
	}
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i = 0; i < con[p].size(); i++) {
			int next = con[p][i];
			if (rumor[next]) continue;
			adj[next]++;
			if (adj[next] == (con[next].size() + 1) / 2) {
				time[next] = time[p] + 1;
				rumor[next] = 1;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (rumor[i] == 0) cout << "-1 ";
		else cout << time[i] << " ";
	}
}