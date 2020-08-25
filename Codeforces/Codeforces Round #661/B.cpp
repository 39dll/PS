#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;
int t, N;
int app[51], ora[51];
long long mn = 2100000000, mn2 = 2100000000;
long long cnt;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> N; mn = 2100000000;
		mn2 = 2100000000; cnt = 0;
		for (int i = 0; i < N; i++) {
			cin >> app[i];
			mn = min(mn, (long long)app[i]);
		}
		for (int i = 0; i < N; i++) {
			cin >> ora[i];
			mn2 = min(mn2, (long long)ora[i]);
		}
		for (int i = 0; i < N; i++) {
			cnt += max(app[i] - mn, ora[i] - mn2);
		}
		cout << cnt << "\n";
	}
}
