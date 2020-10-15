#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<int> v(2*N);
	for (int i = 0; i < 2 * N; i++)cin >> v[i];
	sort(v.begin(), v.end());
	int mn = 2100000000;
	for (int i = 0; i < N; i++) {
		mn = min(v[i] + v[2 * N - i - 1], mn);
	}
	cout << mn;
}
