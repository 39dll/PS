#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long N, M;
	cin >> N;
	M = 1;
	long long cnt = 1, cnt2 = 1;
	while (M < N + 1) {
		cnt *= M;
		cnt %= 1000000007;
		M++;
	}
	M = 0;
	while (M < N - 1) {
		cnt2 *= 2;
		cnt2 %= 1000000007;
		M++;
	}
	cout << (cnt - cnt2 + 1000000007) % 1000000007 << '\n';
}
