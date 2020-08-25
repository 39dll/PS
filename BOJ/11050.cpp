#include <iostream>
#include <algorithm>
using namespace std; 
long long nCr[1001][1001];
int N, K;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	nCr[0][0] = 1;
	cin >> N >> K;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) nCr[i][j] = 1;
			else nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
		}
	}
	cout << nCr[N][K];
	return 0;
}