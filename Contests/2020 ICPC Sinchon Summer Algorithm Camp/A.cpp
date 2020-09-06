#include <bits/stdc++.h>
using namespace std;
long long W0, I0, T;
long long D, I, A;
long long W, newI;
int myabs(int k) {
	return k >= 0 ? k : -k;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> W0 >> I0 >> T;
	cin >> D >> I >> A;
	W = W0 + (I - (I0 + A))*D;
	if (W <= 0)cout << "Danger Diet\n";
	else cout << W << ' ' << I0 << '\n';
	W = W0; newI = I0;
	for (int i = 0; i < D; i++) {
		int temp = I - (newI + A);
		W += temp;
		if (myabs(temp) > T) {
			newI += temp / 2 - (temp < 0 && temp % 2 != 0);
		}
		if (W <= 0 || newI <= 0)break;
	}
	if (W <= 0 || newI <= 0 || I0 < newI)cout << "Danger Diet";
	else{
		cout << W << ' ' << newI << ' ';
		if (I0 > newI)cout << "YOYO";
		else cout << "NO";
	}
}
