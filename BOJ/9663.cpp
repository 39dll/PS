#include <iostream>
#include <cmath>
int N, c = 0;
int a[16];
using namespace std;
bool notattacked(int i) {
	for (int j = 0; j < i; j++) {
		if (a[j] == a[i] || abs(a[i] - a[j]) == (i - j)) {
			return 0;
		}
	}
	return 1;
}
void go(int i) {
	if (i == N) {
		c++;
		return;
	}
	for (int j = 0; j < N; j++) {
		a[i] = j;
		if (notattacked(i)) {
			go(i + 1);
		}
	}
}
int main() {
	cin >> N;
	go(0);
	cout << c;
}