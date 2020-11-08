#include <bits/stdc++.h>
using namespace std;

string change(long long n) {
	long long a = 3LL * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3;
	string cur = "";
	while (1) {
		if (n >= a && a != 0) {
			cur.push_back(n / a + '0');
			n %= a;
		}
		else {
			if (cur != "") {
				cur.push_back('0');
			}
		}
		if (a < 1) break;
		a /= 3;
	}
	return cur;
}

int solution(int n) {
	string s = change(n);
	int ans = 0;
	int now = 1;
	for (int i = 0; i < s.length(); i++) {
		ans += now * (s[i] - '0');
		now *= 3;
	}
	return ans;
}
