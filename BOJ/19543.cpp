#include <iostream>
#include <string>
using namespace std;
string str[26], mp;
int N, M, K;
int x, y, ptr1, ptr2;
long long cnt;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> str[i];
	}
	cin >> mp;
	ptr2 = M - 1;
	for (int i = M - 2; i >= 0; i--) {
		if (str[mp[N - 1] - 'A'][i] == 'U') {
			ptr1 = i + 1;
			break;
		}
		if (i == 0) {
			ptr1 = 0;
		}
	}
	cnt += ptr2 - ptr1 + 1;
	for (int i = N - 2; i >= 0; i--) {
		int prevptr1 = ptr1;
		char cur = mp[i] - 'A';
		while (str[cur][ptr2] != 'U') {
			if (ptr2 == -1) break;
			ptr2--;
		}
		if (ptr1 != 0) {
			while (str[cur][ptr1 - 1] != 'U') {
				if (ptr1 == 0) break;
				ptr1--;
			}
		}
		if (ptr2 < ptr1) break;
		if (prevptr1 > ptr2) break;
		cnt += ptr2 - ptr1 + 1;
	}
	cout << cnt;
}