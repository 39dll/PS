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
int main() { //s에서 p를 서치하고, 그 개수와 index를 반환한다.
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, in;
	cin >> N;
	string s(360000, 0), p(360000, 0);
	for (int i = 0; i < N; i++) {
		cin >> in;
		s[in] = 1;
	}
	for (int i = 0; i < N; i++) {
		cin >> in;
		p[in] = 1;
	}
	auto matched = kmp(s + s, p);
	if (!matched.size())cout << "im";
	cout << "possible";
}