﻿#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> getPi(string p) {
	int m = (int)p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	int len;
	cin >> len >> s;
	auto pi = getPi(s);
	if (pi[len - 1] == 0)cout << len;
	else cout << len - pi[len - 1];
}