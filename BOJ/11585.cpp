#include <iostream>
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
vector<int> kmp(string s, string p) {
	vector<int> ans;
	auto pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}
int gcd(int a, int b) {
	while (b != 0) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s, s2;
	int len;
	cin >> len;
	for (int i = 0; i < len; i++) {
		char c;
		cin >> c;
		s.push_back(c);
	}
	for (int i = 0; i < len; i++) {
		char c;
		cin >> c;
		s2.push_back(c);
	}
	s += s;
	auto matched = kmp(s.substr(0, len * 2 - 1), s2);
	int g = gcd(matched.size(),len);
	cout << matched.size() / g << '/' << len / g;
}