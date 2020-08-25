#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	char S[1000001]; int d[26] = { 0, }, max = 0;
	cin >> S;
	for (int i = 0; S[i] != NULL; i++) {
		if (S[i] >= 'a' && S[i] <= 'z') {
			d[S[i] - 'a']++;
		}
		else {
			d[S[i] - 'A']++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (d[max] < d[i]) {
			max = i;
		}
	}
	sort(d, d + 26);
	if (d[25] == d[24]) cout << "?" ;
	else cout << char(max + 'A');
}