#include <bits/stdc++.h>
using namespace std;
string in, ans;
int len;
char f[] = { 'a','a','a','e','e','e','e','i','i','i','i','i',
			'o','o','o','o','o','o','u','u','u','u','u','u','u','u' };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> in;
	len = in.length();
	for (int i = 0; i < len; i++) {
		ans += in[i];
		if (in[i] == 'a' || in[i] == 'e' || in[i] == 'i' || in[i] == 'o' || in[i] == 'u') {
			continue;
		}
		else {
			ans += f[in[i] - 'a'];
			if (in[i] == 'z') {
				ans += 'z'; continue;
			}
			else {
				char cur = in[i];
				cur++;
				if (cur == 'a' || cur == 'e' || cur == 'i' || cur == 'o' || cur == 'u')cur++;
				ans += cur;
			}
		}
	}
	cout << ans;
}