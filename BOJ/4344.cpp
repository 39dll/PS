#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int C, N, sum = 0, count = 0;
	double av, per;
	cin >> C;
	while (C--) {
		cin >> N;
		int *s = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> s[i];
			sum += s[i];
		}
		av = (double)sum / (double)N;
		for (int i = 0; i < N; i++) {
			if (s[i] > (double)av) count++;
		}
		per = (double)count * 100 / N;
		printf("%.3lf", per);
		cout << "%\n";
		av = 0;
		count = 0;
		sum = 0;
	}
	return 0;
}