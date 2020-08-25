#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int N, M, k;
int uf[10001];
int cost[10001];
map<int, int> m;
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
	cin >> N >> M >> k;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		uf[i] = i;
	}
	for (int i = 1; i <= M; i++) {
		int in1, in2;
		cin >> in1 >> in2;
		merge(in1, in2);
	}
	for (int i = 1; i <= N; i++) {
		if (m[find(i)] == 0) {
			m[find(i)] = cost[i];
		}
		m[find(i)] = min(m[find(i)], cost[i]);
	}
	int ans = 0;
	for (auto i : m) {
		ans += i.second;
	}
	if (ans <= k)cout << ans;
	else cout << "Oh no";
}