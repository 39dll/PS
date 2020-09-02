#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
string in;
int T;
int cnt[27];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	cin.ignore();
	for(int t=1;t<=T;t++) {
		cout << "Case " << t << ": ";
		getline(cin, in);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < in.length(); i++) {
			if(in[i] >= 'A' && in[i] <='Z')cnt[in[i] - 'A']++;
			if (in[i] >= 'a' && in[i] <= 'z')cnt[in[i] - 'a']++;
		}
		int cnt2 = 0;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] >= 3)cnt2++;
		}
		if (cnt2 == 26) {
			cout << "Triple pangram!!!\n";
			continue;
		}
		cnt2 = 0;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] >= 2)cnt2++;
		}
		if (cnt2 == 26) {
			cout << "Double pangram!!\n";
			continue;
		}
		cnt2 = 0;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] >= 1)cnt2++;
		}
		if (cnt2 == 26) {
			cout << "Pangram!\n";
			continue;
		}
		cout << "Not a pangram\n";
	}
}