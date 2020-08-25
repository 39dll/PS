#include <iostream>
using namespace std;
long long N, K, ans;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		ans += K;
		ans %= i;
	}
	cout << ans + 1;
}