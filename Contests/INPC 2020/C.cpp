#include<bits/stdc++.h>
using namespace std;
unsigned long long a[68];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	unsigned long long N;
	cin >> N;
	for (int i = 0; i < 67; i++)a[i] = 1;
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 65; j++) {
			a[j] *= 2;
			if (i == j) {
				a[j]--;
			}
		}
	}
	for (int i = 0; i < 65; i++) {
		if (a[i] == N) {
			cout << i + 1;
			return 0;
		}
	}
}
