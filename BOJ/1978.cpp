#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int N, count = 0, num[101], arr[1001];
	for (int i = 1; i < 1001; i++) {
		if (i % 2 == 1) arr[i] = 1;
		else arr[i] = 0;
	}
	arr[1] = 0; arr[2] = 1;
	for (int i = 1; i < 1001; i++) {
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
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		if (arr[num[i]] == 1) count++;
	}
	cout << count;
	return 0;
}