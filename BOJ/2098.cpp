#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define INF 1000000007
using namespace std;
int N, ansbit;
int W[17][17];
int dp[17][131072];
string com;
void add(int &a, int x) {
	a |= (1 << x);
}
bool check(const int &a, int x) {
	return a & (1 << x);
}
int go(int node, int bit) {
	if (bit == ansbit) {
		if (W[node][0] == 0) return INF;
		else return W[node][0];
	}
	if (dp[node][bit] != -1) return dp[node][bit];
	dp[node][bit] = INF;
	for (int i = 0; i < N; i++) {
		if (W[node][i] == 0) continue;
		if ((bit & (1 << i)) == (1 << i)) continue;
		dp[node][bit] = min(dp[node][bit], W[node][i] + go(i, bit | 1 << i));
	}
	return dp[node][bit];
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}
	ansbit = (1 << N) - 1;
	memset(dp, -1, sizeof(dp));
	cout << go(0, 1);
}