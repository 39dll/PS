#include <iostream>
#include <algorithm>
using namespace std;
long long N, fail, money, mx, mxind, cond[100001], prize[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> cond[i] >> prize[i];
	}
	for (int i = 1; i <= N; i++) {
		if (cond[i] >= money) {
			if (mx < prize[i]) {
				mx = prize[i];
				mxind = i;
			}
			money += prize[i];
			continue;
		}
		fail = i;
		break;
	}
	if (fail == 0) {
		cout << "Kkeo-eok";
		return 0;
	}
	int cnt = 0;
	money = 0;
	for (int i = 1; i <= N; i++) {
		if (i == fail)continue;
		if (cond[i] >= money) {
			money += prize[i];
			cnt++;
		}
	}
	if (cnt == N - 1) {
		cout << "Kkeo-eok";
		return 0;
	}
	money = 0;
	for (int i = 1; i <= N; i++) {
		if (i == mxind) continue;
		if (cond[i] >= money) {
			money += prize[i];
			continue;
		}
		cout << "Zzz";
		return 0;
	}
	cout << "Kkeo-eok";
}