#include <iostream>
using namespace std;
int len, cnt1, cnt2;
char in[100002];
int main() {
	cin >> len >> in;
	for (int i = 0; i < len; i++) {
		if (in[i] == '2')cnt1++;
		else cnt2++;
	}
	if (cnt1 == cnt2)cout << "yee";
	else if (cnt1 > cnt2)cout << "2";
	else cout << "e";
}