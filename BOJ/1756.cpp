#include <iostream>
#include <algorithm>
using namespace std;
int D, N;
int oven[300001];
int temp, ans;
int main() {
	cin >> D >> N;
	cin >> temp;
	oven[0] = temp;
	for (int i = 1; i < D; i++) {
		cin >> temp;
		if (temp > oven[i - 1]) oven[i] = oven[i - 1];
		else oven[i] = temp;
	}
	reverse(oven, oven + D);
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		ans = lower_bound(oven + ans, oven + D, temp) - oven;
		if (ans >= D) {
			cout << "0";
			return 0;
		}
		ans++;
	}
	cout << D + 1 - ans;
}