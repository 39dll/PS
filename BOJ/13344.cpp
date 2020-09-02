#include <bits/stdc++.h>
using namespace std;
int uf[50001];
int find(int a) {
	if (a == uf[a]) return a;
	int k = find(uf[a]);
	return uf[a] = k;
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		uf[b] = a;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M;
	int indegree[50001] = { 0 };
	vector<int> edge[50001];
	queue<int> q;

	cin >> N >> M;

	//Make edges, set indegrees
	for (int i = 1; i <= N; i++) {
		uf[i] = i;
	}
	queue<pair<int, int>> com;
	for (int i = 1; i <= M; i++) {
		int in1, in3;
		char in2;
		cin >> in1 >> in2 >> in3;
		in1++; in3++;
		if (in2 == '=') {
			merge(in1, in3);
		}
		else {
			com.push({ in1, in3 });
		}
	}
	while (!com.empty()) {
		int num1 = com.front().first;
		int num2 = com.front().second;
		if (find(num1) == find(num2)) {
			cout << "inconsistent\n";
			return 0;
		}
		indegree[find(num2)]++;
		edge[find(num1)].push_back(find(num2));
		com.pop();
	}

	//Start Topological Sort
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)q.push(i);
	}

	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			cout << "inconsistent\n";
			return 0;
		}
		int cur = q.front();
		q.pop();
		for (int next : edge[cur]) {
			if (--indegree[next] == 0)q.push(next);
		}
	}

	//Print
	cout << "consistent\n";
}