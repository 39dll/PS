#include <iostream>
#include <cmath>
using namespace std;
int min(int arg0, int arg1) { if (arg0 < arg1) return arg0; else return arg1; }
int main() {
	int M, N, count = 0, MIN, num[10002], arr[10002];
	for (int i = 1; i < 10001; i++) {
		if (i % 2 == 1) arr[i] = 1;
		else arr[i] = 0;
		num[10001] = 0;
	}
	arr[1] = 0; arr[2] = 1; MIN = 0;
	for (int i = 1; i < 10001; i++) {
		if (i % 2 == 1) {
			for (int j = 3; j <= sqrt(i); j++) {
				if (arr[j] == 1) {
					if (i%j == 0) {
						arr[i] = 0; break;
					}
				}
			}
		}
	}
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (arr[i] == 1) {
			num[i] = i;
			count += i;
			if (MIN == 0) MIN = i;
		}
	}
	if (count != 0) {
		cout << count << "\n" << MIN;
	}
	else cout << -1;
	return 0;
}