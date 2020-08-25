#include <iostream>
#include <string>
using namespace std;
int N;
string str;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) str += "* ";
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0)cout << str << '\n';
		else cout << ' ' << str << '\n';
	}
}