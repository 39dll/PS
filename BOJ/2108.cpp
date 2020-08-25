#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int N, sum = 0, count = 0, max = 0, maxnum = 0, temp = -5000;
	cin >> N;
	int *a = new int[N];
	int b[8002] = { 0, };//-4000 ~ 4000의 원소 개수
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		sum += a[i];
		b[a[i] + 4000]++;
		if (b[a[i] + 4000] > max) max = b[a[i] + 4000];
	}
	sort(a, a + N);
	cout << round(sum / (double)N) << "\n";
	cout << a[N / 2] << "\n";
	for (int i = 0; i < 8001; i++) {
		if (b[i] == max) {
			if (temp == -5000) {
				temp = i - 4000;
			}
			else {
				maxnum = i - 4000; break;
			}
		}
		if (i == 8000) {
			maxnum = temp;
		}
	}
	cout << maxnum << "\n";
	cout << a[N - 1] - a[0] << "\n";
	return 0;
}