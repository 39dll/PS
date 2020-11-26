#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) {

		int N; cin >> N;
		vector<int> v;
		int prior = 0;
		for (int i = 0; i < N; i++) {
			int in; cin >> in;
			if (prior != in) {
				v.push_back(in);
				prior = in;
			}
		}
		map<int, int> m;
		for (int i = 0; i < v.size(); i++) {
			m[v[i]]++;
		}
		int mn = 21000000;
		for (auto &i : m) {
			mn = min(mn, i.second - 1 + (i.first != v.front()) + (i.first != v.back()));
		}
		cout << mn << '\n';
	}
}
