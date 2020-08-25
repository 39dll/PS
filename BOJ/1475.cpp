#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int cnt[10];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		cnt[s[i] - '0']++;
	}
	cnt[6] += cnt[9] + 1;
	cnt[6] /= 2;
	int mx = 0;
	for (int i = 0; i < 9; i++) {
		mx = max(mx, cnt[i]);
	}
	cout << mx;
}