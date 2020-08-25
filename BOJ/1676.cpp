#include <iostream>
#include <algorithm>
using namespace std; 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, mul2 = 0, mul5 = 0;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		int k = i;
		while (k % 2 == 0) {
			k /= 2;
			mul2++;
		}
		while (k % 5 == 0) {
			k /= 5;
			mul5++;
		}
	}
	cout << min(mul2, mul5);
	return 0;
}