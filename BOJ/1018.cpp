#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int N, M, min = 64, count1 = 0, count2 = 0, p = 0;
	cin >> N >> M;
	char a[50][51];
	for (int i= 0; i < N; i++) {
		scanf("%s", a[i]);
	}
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			for (int ii = i; ii < i + 8; ii++) {
				for (int jj = j; jj < j + 8; jj++) {
					if ((ii + jj) % 2 == 0) {
						if (a[ii][jj] == 'B') count1++;
						else count2++;
					}
					else {
						if (a[ii][jj] == 'B') count2++;
						else count1++;
					}
				}
			}
			if (count1 > count2) p = count2; else p = count1;
			if (p < min) min = p;
			count1 = 0; count2 = 0;
		}
	}
	cout << min;
	return 0;
}