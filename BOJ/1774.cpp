#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;
typedef tuple<long double, int, int> t; //가중치, 시작점, 도착점
int uf[1001];
int N, M;
pair<long long, long long> vertex[1001];
int in1, in2;
priority_queue<t, vector<t>, greater<t> > pq;
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
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> in1 >> in2;
		vertex[i] = { in1, in2 };
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			pq.push({ sqrt((vertex[i].first - vertex[j].first) * (vertex[i].first - vertex[j].first) + (vertex[i].second - vertex[j].second) * (vertex[i].second - vertex[j].second)),i,j });
		}
	}
	for (int i = 1; i <= N; i++) uf[i] = i;
	for (int i = 1; i <= M; i++) {
		cin >> in1 >> in2;
		merge(in1, in2);
	}
	int cnt = 0;
	long double ans = 0;
	while (!pq.empty()) {
		if (cnt == N - M - 1) break;
		int st = get<1>(pq.top());
		int se = get<2>(pq.top());
		long double cost = get<0>(pq.top());
		pq.pop();
		if (find(st) == find(se)) continue;
		merge(st, se);
		cnt++; ans += cost;
	}
	cout.precision(2);
	cout << fixed << ans;
}