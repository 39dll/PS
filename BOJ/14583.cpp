#include <iostream>
#include <cmath>
using namespace std;
double H, V;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	cin >> H >> V;
	double k = (H*V) / (sqrt(H*H + V*V) + H);
	double k2 = sqrt(k*k + H*H);
	cout << fixed << k2 / 2 << ' ';
	cout << fixed << (V - k)*H / k2;
}