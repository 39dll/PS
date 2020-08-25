#include <iostream>
#include <cmath>
using namespace std;
const int lol = 1234567891;
long long hs, m = 1;
int n;
char s[55];
int main() {
	ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		hs += (s[i] - 'a' + 1) * m;
		hs %= lol;
		m *= 31;
		m %= lol;
	}
	cout << hs;
}