#include <iostream>
#include <map>
#include <cmath>
using namespace std;
map<long long, long long> dp;
long long N, P, Q;
long long get(long long ind) {
	if (ind == 0) return 1;
	if (dp[ind] != 0) return dp[ind];
	return dp[ind] = get(floor(1.0 * ind / P)) + get(floor(1.0 * ind / Q));
}
int main() {
	cin >> N >> P >> Q;
	cout << get(N);
}