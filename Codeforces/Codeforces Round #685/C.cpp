#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T; while (T--) {
		int N, K; cin >> N >> K;
		string s1, s2;
		cin >> s1 >> s2;
		map<int, int> m1, m2;
		for (int i = 0; i < N; i++) {
			m1[s1[i] - 'a']++;
			m2[s2[i] - 'a']++;
		}
		bool pos = 1;
		for (int i = 0; i < 26; i++) {
			int left = m1[i] - m2[i];
			if (left < 0) {
				pos = 0;
				break;
			}
			if (left%K != 0) {
				pos = 0;
				break;
			}
			m1[i + 1] += left;
			if (i == 25) {
				if (left != 0)pos = 0;
			}
		}
		cout << (pos ? "Yes\n" : "No\n");
	}
}
