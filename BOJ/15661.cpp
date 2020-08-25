#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int N, ab[21][21], team[21], mn = 2100000000, val1, val2;
void calc(int ind, int n1, int n2) {
	if (n1 == N || n2 == N) return;
	if (n1 + n2 == N) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (team[i] == team[j] && team[i] == 1) {
					val1 += ab[i][j];
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (team[i] == team[j] && team[i] == 2) {
					val2 += ab[i][j];
				}
			}
		}
		mn = min(mn, abs(val1 - val2));
		val1 = val2 = 0;
		return;
	}
	team[ind] = 1;
	calc(ind + 1, n1 + 1, n2);
	team[ind] = 0;
	team[ind] = 2;
	calc(ind + 1, n1, n2 + 1);
	team[ind] = 0;
}
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ab[i][j];
		}
	}
	calc(0, 0, 0);
	cout << mn;
}