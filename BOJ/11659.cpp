#include <iostream>
using namespace std;
int N, M, a[100001], sum[100001] = { 0 }, in1, in2;
int main() {
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	while (M--) {
		cin >> in1 >> in2;
		cout << sum[in2] - sum[in1 - 1] << "\n";
	}
}