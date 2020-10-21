#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++)cin >> v[i];
		int mx = *max_element(v.begin(), v.end());
		int mxind = -1;
		for (int i = 0; i < N; i++) {
			if (i != N - 1) {
				if (v[i] == mx && v[i + 1] != mx) {
					mxind = i;
				}
			}
			if (i != 0) {
				if (v[i] == mx&&v[i - 1] != mx) {
					mxind = i;
				}
			}
		}
		if (mxind == -1)cout << "-1\n";
		else cout << mxind + 1 << '\n';
	}
}
