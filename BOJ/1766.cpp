#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int N, M, in1, in2;
int ind[32001];
vector<int> e[32001], ans;
priority_queue<int, vector<int>, greater<int> > q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> in1 >> in2;
		e[in1].push_back(in2);
		ind[in2]++;
	}
	for (int i = 1; i <= N; i++) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 0; i < N; i++) {
		if (q.empty()) {
			return 1; //cycle
		}
		int a = q.top();
		q.pop();
		ans.push_back(a);
		for (int j = 0; j < e[a].size(); j++) {
			ind[e[a][j]]--;
			if (ind[e[a][j]] == 0)q.push(e[a][j]);
		}
	}
	for (int i = 0; i < N; i++)cout << ans[i] << " ";
}