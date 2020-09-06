#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> A[1001];
int ans[1001];
bool used[1001];
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int in;
		cin >> in;
		for (int j = 1; j <= in; j++) {
			int in2;
			cin >> in2;
			A[i].push_back(in2);
		}
	}
	for (int t = 0; t < N + 1; t++) {
		for (int i = 1; i <= N; i++) {
			if (A[i].size() == 1) {
				int k = A[i][0];
				if (used[i] == 0) {
					ans[i] = k;
					A[i].clear();
					used[i] = 1;
					for (int p = 1; p <= N; p++) {
						A[p].erase(remove(A[p].begin(), A[p].end(), k), A[p].end());
					}
				}
				else {
					cout << "-1";
					return 0;
				}
			}
		}
	}
	bool allused = 1;
	for (int i = 1; i <= N; i++) {
		if (used[i] == 0) {
			allused = 0;
			break;
		}
	}
	if (allused) {
		cout << "1\n";
		for (int i = 1; i <= N; i++) {
			cout << ans[i] << ' ';
		}
	}
	else {
		cout << -1;
	}
}
