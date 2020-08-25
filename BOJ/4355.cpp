#include <iostream>
#include <map>
#include <cmath>
using namespace std;
long long N, k = 2, ans = 1, t;
map<long long, long long> m;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	while (N != 0) {
		ans = 1; k = 2; m.clear();
		if (N == 1) {
			cout << "1\n";
			cin >> N;
			continue;
		}
		while (k * k <= N) {
			if (N % k == 0) {
				m[k]++;
				N /= k;
			}
			else k++;
		}
		m[N]++;
		for (auto &i : m) {
			ans *= pow(i.first, i.second) - pow(i.first, i.second - 1);
		}
		cout << ans << "\n";
		cin >> N;
	}
}