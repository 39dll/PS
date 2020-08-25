#include <iostream>
using namespace std;
int n, h[100001];
long long maxw = 0;
void calc(int start, int end) {
	int k = 1, ind = 0;
	long long m = 100000000000001, sigh = 0, w = 0;
	for (int i = start; i <= end; i++) {
		sigh += h[i];
		if (m > h[i]) { m = h[i]; ind = i; }
	}
	if (sigh <= maxw) return;
	if (ind != start) {
		for (int i = ind; i > start; i--) {
			if (h[i - 1] >= m) k++;
			else break;
		}
	}
	if (ind != end) {
		for (int i = ind; i < end; i++) {
			if (h[i + 1] >= h[ind]) k++;
			else break;
		}
	}
	w = k*m;
	if (k*m > maxw) maxw = k*m;
	if (ind > start) calc(start, ind - 1);
	if (ind < end) calc(ind + 1, end);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n) {
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		calc(0, n - 1);
		cout << maxw << "\n";
		maxw = 0;
		break;
		cin >> n;
	}
	return 0;
}