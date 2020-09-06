#include <bits/stdc++.h>
using namespace std;
string c[100001];
int v[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> c[i] >> v[i];
	}
	for (int i = 1; i <= M; i++) {
		int in;
		cin >> in;
		auto it = lower_bound(v, v + N, in) - v;
		cout << c[it] << '\n';
	}
}
