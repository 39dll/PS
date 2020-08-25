#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <functional>
using namespace std;
typedef tuple<int, int, int> t; //가중치, 시작점, 도착점
int uf[1001];
int N, M, in1, in2, in3;
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
	for (int i = 0; i < M; i++) {
		cin >> in1 >> in2 >> in3;
		pq.push({ in3,in1,in2 });
	}
	for (int i = 1; i <= N; i++) uf[i] = i;
	int cnt = 0, ans = 0;
	while (!pq.empty()) {
		if (cnt == N - 1) break;
		int st = get<1>(pq.top());
		int se = get<2>(pq.top());
		int cost = get<0>(pq.top());
		pq.pop();
		if (find(st) == find(se)) continue;
		merge(st, se);
		cnt++; ans += cost;
	}
	cout << ans;
}