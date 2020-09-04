#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		map<char, int> m;
		int cnt[10] = { 0 };
		string str;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			m[str[i]]++;
		}
		if (m['G'] != 0) {
			cnt[8] += m['G'];
			m['E'] -= m['G'];
			m['H'] -= m['G'];
			m['I'] -= m['G'];
			m['T'] -= m['G'];
			m['G'] = 0;
		}
		if (m['X'] != 0) {
			cnt[6] += m['X'];
			m['I'] -= m['X'];
			m['S'] -= m['X'];
			m['X'] = 0;
		}
		if (m['U'] != 0) {
			cnt[4] += m['U'];
			m['F'] -= m['U'];
			m['O'] -= m['U'];
			m['R'] -= m['U'];
			m['U'] = 0;
		}
		if (m['W'] != 0) {
			cnt[2] += m['W'];
			m['T'] -= m['W'];
			m['O'] -= m['W'];
			m['W'] = 0;
		}
		if (m['Z'] != 0) {
			cnt[0] += m['Z'];
			m['E'] -= m['Z'];
			m['R'] -= m['Z'];
			m['O'] -= m['Z'];
			m['Z'] = 0;
		}
		if (m['H'] != 0) {
			cnt[3] += m['H'];
			m['T'] -= m['H'];
			m['R'] -= m['H'];
			m['E'] -= m['H'] * 2;
			m['H'] = 0;
		}
		if (m['O'] != 0) {
			cnt[1] += m['O'];
			m['N'] -= m['O'];
			m['E'] -= m['O'];
			m['O'] = 0;
		}
		if (m['F'] != 0) {
			cnt[5] += m['F'];
			m['I'] -= m['F'];
			m['V'] -= m['F'];
			m['E'] -= m['F'];
			m['F'] = 0;
		}
		if (m['V'] != 0) {
			cnt[7] += m['V'];
			m['E'] -= m['V'] * 2;
			m['N'] -= m['V'];
			m['S'] -= m['V'];
			m['V'] = 0;
		}
		if (m['E'] != 0) {
			cnt[9] += m['E'];
			m['I'] -= m['E'];
			m['N'] -= m['E'] * 2;
			m['E'] = 0;
		}
		cout << "Case #" << t << ": ";
		for (int i = 0; i < 10; i++) {
			while (cnt[i] > 0) {
				cout << i;
				cnt[i]--;
			}
		}
		cout << '\n';
	}
}