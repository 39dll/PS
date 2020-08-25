#include <iostream>
#include <algorithm>
using namespace std;
const long long INF = 4000000000;
int N, num[12], cal[4];
long long maxn = -INF, minn = INF, val;
void calc(int a, int b, int c, int d) {
	int sum = a + b + c + d, temp;
	if (sum == 0) {
		maxn = max(maxn, val);
		minn = min(minn, val);
		return;
	}
	temp = val;
	if (a > 0) {
		val += num[N - sum];
		calc(a - 1, b, c, d);
		val = temp;
	}
	if (b > 0) {
		val -= num[N - sum];
		calc(a, b - 1, c, d);
		val = temp;
	}
	if (c > 0) {
		val *= num[N - sum];
		calc(a, b, c - 1, d);
		val = temp;
	}
	if (d > 0) {
		val /= num[N - sum];
		calc(a, b, c, d - 1);
		val = temp;
	}
}
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	val = num[0];
	cin >> cal[0] >> cal[1] >> cal[2] >> cal[3];
	calc(cal[0], cal[1], cal[2], cal[3]);
	cout << maxn << "\n" << minn;
}