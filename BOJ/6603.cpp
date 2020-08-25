#include <iostream>
#include <algorithm>
using namespace std;
int cnt, arr[13], ch[13];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> cnt;
	while (cnt != 0) {
		for (int i = 0; i < cnt; i++) {
			cin >> arr[i];
			ch[i] = 0;
		}
		for (int i = 0; i < 6; i++) {
			ch[i] = 1;
		}
		do {
			for (int i = 0; i < cnt; i++) {
				if (ch[i] == 1) cout << arr[i] << " ";
			}
			cout << '\n';
		} while (prev_permutation(ch, ch + cnt));
		cout << '\n';
		cin >> cnt;
	}
}