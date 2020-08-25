#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[1000005], K, mn, cnt, ind1, ind2 = -1;
int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	while (cnt != K) {
		ind1++;
		if (arr[ind1] == 1) {
			if (ind2 == -1) {
				ind2 = ind1;
			}
			cnt++;
		}
		if (ind1 > N) {
			cout << "-1\n";
			return 0;
		}
	}
	mn = ind1 - ind2 + 1;
	for (; ind1 <= N;) {
		ind1++;
		while (arr[ind1] != 1) {
			ind1++;
			if (ind1 > N) {
				cout << mn;
				return 0;
			}
		}
		ind2++;
		while (arr[ind2] != 1) {
			ind2++;
		}
		mn = min(mn, ind1 - ind2 + 1);
	}
	cout << cnt;
}