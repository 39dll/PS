#include <bits/stdc++.h>
using namespace std;
long long pow10[] = { 1,10,100,1000,10000,100000,1000000,10000000,
100000000, 1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,
1000000000000000,10000000000000000,100000000000000000, 1000000000000000000 };
bool isGood(long long n, int s) {
	string str = to_string(n);
	int temp = 0;
	for (int i = 0; i < str.length(); i++) {
		temp += str[i] - '0';
	}
	if (temp <= s)return 1;
	else return 0;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		long long n, s, ori;
		cin >> n >> s;
		ori = n;
		int iter = 0;
		while (1) {
			if (isGood(n, s) == 1)break;
			if ((n % pow10[iter + 1]) / pow10[iter] != 0) {
				n += (10 - (n % pow10[iter + 1]) / pow10[iter]) * pow10[iter];
			}
			iter++;
		}
		cout << n - ori << '\n';
	}
}
