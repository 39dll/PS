#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {

		int N; cin >> N;
		vector<string> v;
		for (int i = 0; i < N; i++) {
			string str; cin >> str;
			v.push_back(str);
		}
		int cnt[6] = { 0 };
		auto t1 = v, t2 = v, t3 = v, t4 = v, t5 = v, t6 = v;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ((i + j) % 3 == 0) {
					if (t1[i][j] == 'X') {
						t1[i][j] = 'O';
						cnt[0]++;
					}
				}
				if ((i + j) % 3 == 1) {
					if (t2[i][j] == 'X') {
						t2[i][j] = 'O';
						cnt[1]++;
					}
				}
				if ((i + j) % 3 == 2) {
					if (t3[i][j] == 'X') {
						t3[i][j] = 'O';
						cnt[2]++;
					}
				}
				if (i >= j) {
					if ((i - j) % 3 == 0) {
						if (t4[i][j] == 'X') {
							t4[i][j] = 'O';
							cnt[3]++;
						}
					}
					if ((i - j) % 3 == 1) {
						if (t5[i][j] == 'X') {
							t5[i][j] = 'O';
							cnt[4]++;
						}
					}
					if ((i - j) % 3 == 2) {
						if (t6[i][j] == 'X') {
							t6[i][j] = 'O';
							cnt[5]++;
						}
					}
				}
				else {
					if ((j - i) % 3 == 0) {
						if (t4[i][j] == 'X') {
							t4[i][j] = 'O';
							cnt[3]++;
						}
					}
					if ((j - i) % 3 == 2) {
						if (t5[i][j] == 'X') {
							t5[i][j] = 'O';
							cnt[4]++;
						}
					}
					if ((j - i) % 3 == 1) {
						if (t6[i][j] == 'X') {
							t6[i][j] = 'O';
							cnt[5]++;
						}
					}
				}
			}
		}

		int ind = min_element(cnt, cnt + 6) - cnt;

		if (ind == 0) {
			for (int i = 0; i < N; i++) {
				cout << t1[i] << '\n';
			}
		}
		if (ind == 1) {
			for (int i = 0; i < N; i++) {
				cout << t2[i] << '\n';
			}
		}
		if (ind == 2) {
			for (int i = 0; i < N; i++) {
				cout << t3[i] << '\n';
			}
		}
		if (ind == 3) {
			for (int i = 0; i < N; i++) {
				cout << t4[i] << '\n';
			}
		}
		if (ind == 4) {
			for (int i = 0; i < N; i++) {
				cout << t5[i] << '\n';
			}
		}
		if (ind == 5) {
			for (int i = 0; i < N; i++) {
				cout << t6[i] << '\n';
			}
		}
	}
}
