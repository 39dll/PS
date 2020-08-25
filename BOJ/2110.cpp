#include <iostream>
#include <algorithm>
using namespace std;
int N, C, a[200001];
long long mx = 0;
void search(long long start, long long end) {
	long long p = 1, mid = (start + end) / 2, temp = 0;
	for (int i = 1; i < N; i++) {
		if (a[i] > a[temp] + mid) {
			p++;
			temp = i;
		}
	}
	if (p >= C) {
		if (mx < mid) mx = mid;
		if (end != mid) search(mid + 1, end);
	}
	else if (p < C) {
		if (start != mid) search(start, mid - 1);
	}
}
int main() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N);
	search(0, 1000000000);
	cout << mx + 1;
}