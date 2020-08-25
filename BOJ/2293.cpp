#include <iostream>
using namespace std;
int n, k, coin[101], ans[10001] = { 0, };
int main() {
	cin >> n >> k;
	ans[0] = 1;
	for (int i = 1; i <= n; i++) cin >> coin[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - coin[i] >= 0) ans[j] += ans[j - coin[i]];
		}
	}
	cout << ans[k];
}