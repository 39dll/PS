#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
int N;
string str;
int o[1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while (T--) {
		memset(o, -1, sizeof(o));
		cin >> N >> str;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (str[i + j] == '0') {
					if (o[i] == -1)o[i] = 0;
					if (o[i] == 1)(o[i] = 2);
				}
				if (str[i + j] == '1') {
					if (str[i + j] == '1') {
						if (o[i] == -1)o[i] = 1;
						if (o[i] == 0)o[i] = 2;
					}
				}
			}
		}
		string ans = "";
		for (int i = 0; i < N * 2; i++) {
			if (o[i] == 0)ans += '0';
			if (o[i] == 1)ans += '1';
			if (o[i] == 2)ans += '0';
		}
		cout << ans << '\n';
	}
}
