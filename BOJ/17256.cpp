#include <iostream>
using namespace std;
struct Cake {
	int x, y, z;
};
void solve(Cake a, Cake c) {
	cout << c.x - a.z << " " << c.y / a.y << " " << c.z - a.x;
}
int main() {
	Cake cake1, cake2;
	cin >> cake1.x >> cake1.y >> cake1.z;
	cin >> cake2.x >> cake2.y >> cake2.z;
	solve(cake1, cake2);
}