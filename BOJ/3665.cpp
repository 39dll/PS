#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, M;
		int indegree[501] = { 0 };
		bool edge[501][501] = { 0 };
		queue<int> q;
		vector<int> res;

		cin >> N;

		//Make edges, set indegrees
		int rank[501] = { 0 };
		for (int i = 1; i <= N; i++) {
			cin >> rank[i];
		}
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				indegree[rank[j]]++;
				edge[rank[i]][rank[j]] = 1;
			}
		}

		cin >> M;
		for (int i = 1; i <= M; i++) {
			int in1, in2;
			cin >> in1 >> in2;
			if (edge[in1][in2]) {
				edge[in1][in2] = 0;
				edge[in2][in1] = 1;
				indegree[in2]--; indegree[in1]++;
			}
			else {
				edge[in1][in2] = 1;
				edge[in2][in1] = 0;
				indegree[in1]--; indegree[in2]++;
			}
		}

		//Start Topological Sort
		bool imp = 0;
		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0)q.push(i);
		}

		for (int i = 1; i <= N; i++) {
			if (q.empty()) {
				cout << "IMPOSSIBLE\n";
				imp = 1;
				break;
			}
			int cur = q.front();
			q.pop();
			res.push_back(cur);
			for (int next = 1; next <= N; next++) {
				if (edge[cur][next] == 0 || next == cur)continue;
				if (--indegree[next] == 0)q.push(next);
			}
		}

		//Print
		if (imp == 0) {
			for (int i = 0; i < res.size(); i++) {
				cout << res[i] << ' ';
			}
			cout << '\n';
		}
	}
}