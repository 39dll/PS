#include <iostream>
#include <algorithm>
using namespace std;
int N, M, B, h[501][501], maxh = 256, minh, ans, block;
long long sum, minsum = 20000000000;
char s[55];
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N >> M >> B;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> h[i][j];
			maxh = max(maxh, h[i][j]);
			minh = min(minh, h[i][j]);
		}
	}
	for (int i = minh; i <= maxh; i++) {
		sum = 0;
		block = 0;
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (h[j][k] == i) {
					continue;
				}
				if (h[j][k] < i) {
					sum += i - h[j][k];
					block -= i - h[j][k];
				}
				else {
					sum += (h[j][k] - i) * 2;
					block += h[j][k] - i;
				}
			}
		}
		if (block + B < 0) continue;
		if (sum <= minsum) {
			minsum = sum;
			ans = i;
		}
	}
	cout << minsum << " " << ans;
}