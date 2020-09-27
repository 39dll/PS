#include <bits/stdc++.h>
using namespace std;
long long mod[10][4] = {
	{0,0,0,0},
	{1,1,1,1},
	{2,4,8,6},
	{3,9,7,1},
	{4,6,4,6},
	{5,5,5,5},
	{6,6,6,6},
	{7,9,3,1},
	{8,4,2,6},
	{9,1,9,1}
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long v0, m, t;
	cin >> v0 >> m >> t;
	m %= 10;
	t--;
	long long ch = t / 4;
	long long chvalx = (((v0*mod[m][0]) % 10) - ((v0*mod[m][2]) % 10));
	long long chvaly = (((v0*mod[m][3]) % 10) - ((v0*mod[m][1]) % 10));
	long long ansx = 0, ansy = 0;
	ansy += v0;
	ansx += chvalx * ch;
	ansy += chvaly * ch;
	if (t % 4 == 1) {
		ansx += (v0 * mod[m][0]) % 10;
	}
	if (t % 4 == 2) {
		ansx += (v0 * mod[m][0]) % 10;
		ansy -= (v0 * mod[m][1]) % 10;
	}
	if (t % 4 == 3) {
		ansx += (v0 * mod[m][0]) % 10;
		ansy -= (v0 * mod[m][1]) % 10;
		ansx -= (v0 * mod[m][2]) % 10;
	}
	cout << ansx << ' ' << ansy << '\n';
}
