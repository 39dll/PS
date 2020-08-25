#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
#include <functional>
#include <cstdlib>
using namespace std;
typedef tuple<long long, int, int > t; //가중치, 시작점, 도착점
typedef tuple<long long, long long, long long, int> tt;
int uf[100001];
int N, M;
tuple<long long, long long, long long, int> v[100001], v2[100001], v3[100001];
int in1, in2, in3;
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
bool compX(tt a, tt b) {
	return get<0>(a) < get<0>(b);
}
bool compY(tt a, tt b) {
	return get<1>(a) < get<1>(b);
}
bool compZ(tt a, tt b) {
	return get<2>(a) < get<2>(b);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> in1 >> in2 >> in3;
		v[i] = { in1, in2, in3 , i };
		v2[i] = { in1, in2, in3 , i };
		v3[i] = { in1, in2, in3 , i };
	}
	sort(v + 1, v + N + 1, compX);
	sort(v2 + 1, v2 + N + 1, compY);
	sort(v3 + 1, v3 + N + 1, compZ);
	for (int i = 1; i < N; i++) {
		pq.push({
			min({abs(get<0>(v[i]) - get<0>(v[i + 1])),
			abs(get<1>(v[i]) - get<1>(v[i + 1])),
			abs(get<2>(v[i]) - get<2>(v[i + 1]))}),
			get<3>(v[i]), get<3>(v[i + 1]) });
		pq.push({
			min({abs(get<0>(v2[i]) - get<0>(v2[i + 1])),
			abs(get<1>(v2[i]) - get<1>(v2[i + 1])),
			abs(get<2>(v2[i]) - get<2>(v2[i + 1]))}),
			get<3>(v2[i]), get<3>(v2[i + 1]) });
		pq.push({
			min({abs(get<0>(v3[i]) - get<0>(v3[i + 1])),
			abs(get<1>(v3[i]) - get<1>(v3[i + 1])),
			abs(get<2>(v3[i]) - get<2>(v3[i + 1]))}),
			get<3>(v3[i]), get<3>(v3[i + 1]) });
	}
	for (int i = 1; i <= N; i++) uf[i] = i;
	int cnt = 0;
	long long ans = 0;
	while (!pq.empty()) {
		if (cnt == N - 1) break;
		int st = get<1>(pq.top());
		int se = get<2>(pq.top());
		long long cost = get<0>(pq.top());
		pq.pop();
		if (find(st) == find(se)) continue;
		merge(st, se);
		cnt++; ans += cost;
	}
	cout << ans;
}