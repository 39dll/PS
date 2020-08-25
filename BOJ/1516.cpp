#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, in1;
int ind[501], cost[501], fincost[501];
vector<int> e[501], ans;
queue<int> q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		cin >> in1;
		while (in1 != -1) {
			e[in1].push_back(i);
			ind[i]++;
			cin >> in1;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (ind[i] == 0) {
			fincost[i] = cost[i];
			q.push(i);
		}
	}
	for (int i = 0; i < N; i++) {
		if (q.empty()) {
			cout << "Error: Cycle";
			return 0;
		}
		int a = q.front();
		q.pop();
		ans.push_back(a);
		for (int j = 0; j < e[a].size(); j++) {
			ind[e[a][j]]--;
			if (ind[e[a][j]] == 0)q.push(e[a][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < e[ans[i]].size(); j++) {
			fincost[e[ans[i]][j]] = max(fincost[e[ans[i]][j]], fincost[ans[i]] + cost[e[ans[i]][j]]);
		}
	}
	for (int i = 1; i <= N; i++)cout << fincost[i] << "\n";
}