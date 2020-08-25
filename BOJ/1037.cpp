#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, mx = 0, mn = 1000000;
	cin >> N;
	int *a = new int[N + 1];
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	cout << mx * mn;
	return 0;
}