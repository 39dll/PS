#include <bits/stdc++.h>
using namespace std;
int main() {
	long long N;
	cin >> N;
	if ((N - 1) % 5 == 1 || (N - 1) % 5 == 4)cout << "CY";
	else cout << "SK";
}