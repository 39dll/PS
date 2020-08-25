#include <iostream>
#include <algorithm>
using namespace std;
long long N, k;
long long mx = 0;
void search(long long start, long long end) {
	long long p = 0, mid = (start + end) / 2;
	if (start > end) return;
	for (int i = 1; i <= N; i++) {
		p += min(mid / i, (long long)N);
	}
	if (p >= k) {
		mx = mid;
		if (start != mid) search(start, mid-1);
	}
	else if (p < k) {
		if (end != mid) search(mid+1, end);
	}
}
int main() {
	cin >> N >> k;
	if (k == 1) {
		cout << 1;
		return 0;
	}
	search(1, N * N);
	cout << mx;
}