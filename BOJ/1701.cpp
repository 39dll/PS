#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
	int mx = 0;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		auto pi = getPi(s.substr(i, len - i));
		mx = max(mx, *max_element(pi.begin(), pi.end()));
	}
	cout << mx;
}