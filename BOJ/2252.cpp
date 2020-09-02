#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M;
	int indegree[32001] = { 0 };
	vector<int> edge[32001];
	queue<int> q;
	vector<int> res;

	cin >> N >> M;

	//Make edges, set indegrees
	for (int i = 1; i <= M; i++) {
		int in1, in2;
		cin >> in1 >> in2;
		indegree[in2]++;
		edge[in1].push_back(in2);
	}

	//Start Topological Sort
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)q.push(i);
	}

	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			cout << "Cannot Sort\n";
			return 0;
		}
		int cur = q.front();
		q.pop();
		res.push_back(cur);
		for (int next : edge[cur]) {
			if (--indegree[next] == 0)q.push(next);
		}
	}

	//Print
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
}