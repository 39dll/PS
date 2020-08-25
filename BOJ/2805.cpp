#include <iostream>
#include <algorithm>
using namespace std;
int N, M, a[1000001];
long long mx = 0;
void search(long long start, long long end) {
	long long p = 0, mid = (start + end) / 2;
	for (int i = 0; i < N; i++) {
		if(a[i] > mid) p += a[i] - mid;
	}
	if (p >= M) {
		if (mx < mid) mx = mid;
		if (end != mid) search(mid + 1, end);
	}
	else if (p < M) {
		if (start != mid) search(start, mid - 1);
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	search(0, 2000000001);
	cout << mx;
}