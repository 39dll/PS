#include <iostream>
#include <algorithm>
using namespace std;
int K, N, a[10001];
long long mx = 0;
void search(long long start, long long end) {
	long long p = 0, mid = (start + end) / 2;
	for (int i = 0; i < K; i++) {
		p += a[i] / mid;
	}
	if (p >= N) {
		if (mx < mid) mx = mid;
		if (end != mid) search(mid + 1, end);
	}
	else if (p < N) {
		if (start != mid) search(start, mid - 1);
	}
}
int main() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> a[i];
	}
	search(0, 21474836480000);
	cout << mx;
}