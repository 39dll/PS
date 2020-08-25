#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int T, N, K, W, in1, in2, ansind;
int ind[1001], cost[1001], fincost[1001];
queue<int> q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		vector<int> e[1001], ans;
		memset(fincost, 0, sizeof(fincost));
		memset(cost, 0, sizeof(cost));
		memset(ind, 0, sizeof(ind));
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> cost[i];
		}
		for (int i = 0; i < K; i++) {
			cin >> in1 >> in2;
			e[in1].push_back(in2);
			ind[in2]++;
		}
		cin >> W;
		for (int i = 1; i <= N; i++) {
			if (ind[i] == 0) {
				fincost[i] = cost[i];
				q.push(i);
			}
		}
		for (int i = 0; i < N; i++) {
			if (q.empty()) {
				return 1; //cycle
			}
			int a = q.front();
			q.pop();
			if (a == W)ansind = a;
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
		cout << fincost[ansind] << "\n";
	}
}