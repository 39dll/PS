#include <bits/stdc++.h>
using namespace std;
typedef tuple<long double, int, int> t; //가중치, 시작점, 도착점
int uf[501];
int N, S;
int find(int a) {
	if (uf[a] == a) return a;
	return uf[a] = find(uf[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) uf[b] = a;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		pair<int, int> loc[501];
		priority_queue<t, vector<t>, greater<t>> pq;
		cin >> S >> N;
		for (int i = 1; i <= N; i++) {
			int in1, in2;
			cin >> in1 >> in2;
			loc[i] = { in1,in2 };
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				long double dist = (loc[i].first - loc[j].first) * (loc[i].first - loc[j].first)
					+ (loc[i].second - loc[j].second) * (loc[i].second - loc[j].second);
				dist = sqrt(dist);
				pq.push({ dist,i,j });
			}
		}
		for (int i = 1; i <= N; i++) uf[i] = i; //Union-Find Initialization
		long double ans = 0;
		long long cnt = 0;
		long double last = 0;
		while (!pq.empty()) {
			if (cnt == N - S) break; //N - 1 connections are enough for a spanning tree
			int st = get<1>(pq.top());
			int se = get<2>(pq.top());
			long double cost = get<0>(pq.top());
			pq.pop();
			if (find(st) == find(se)) continue;
			merge(st, se);
			cnt++; ans += cost;
			last = cost;
		}
		cout.precision(2);
		cout << fixed << last << '\n';
	}
}