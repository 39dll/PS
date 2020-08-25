#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <map>
#include <cstring>
using namespace std;
int t, N;
string str;
vector<char> last;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> N;
		cin >> str;
		last.clear();
		bool good = 0, lastgood = 0;
		string ans = "";
		for (int i = 0; i < N; i++) {
			if (i != 0 && good == 0 && str[i] == str[i - 1]) goto lol;
			good = 0;
			for (int j = 0; j < last.size(); j++) {
				if ((str[i] - '0') ^ 1 == last[j] - '0') {
					last[j] ^= 1;
					good = 1;
					ans += to_string(j + 1);
					ans += ' ';
					break;
				}
			}
			if (good == 1) continue;
			lol:
			last.push_back(str[i]);
			ans += to_string(last.size());
			ans += ' ';
		}
		cout << last.size() << '\n';
		cout << ans << '\n';
	}
}
