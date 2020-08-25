#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<double, double> > point;
double temp1, temp2, jbx, jby, sumx, sumy;
int main() {
	cout.precision(3);
	while (cin >> temp1) {
		point.clear(); jbx = jby = sumx = sumy = 0;
		cin >> temp2;
		point.push_back({ temp1, temp2 });
		for (int k = 0; k < 3; k++) {
			cin >> temp1 >> temp2;
			point.push_back({ temp1, temp2 });
			}
		sort(point.begin(), point.end());
		if (point[0] == point[1]) {
			jbx = point[0].first; jby = point[0].second;
			sumx = point[2].first + point[3].first;
			sumy = point[2].second + point[3].second;
		}
		else if (point[0] == point[2]) {
			jbx = point[0].first; jby = point[0].second;
			sumx = point[1].first + point[3].first;
			sumy = point[1].second + point[3].second;
		}
		else if (point[0] == point[3]) {
			jbx = point[0].first; jby = point[0].second;
			sumx = point[1].first + point[2].first;
			sumy = point[1].second + point[2].second;
		}
		else if (point[1] == point[2]) {
			jbx = point[1].first; jby = point[1].second;
			sumx = point[0].first + point[3].first;
			sumy = point[0].second + point[3].second;
		}
		else if (point[1] == point[3]) {
			jbx = point[1].first; jby = point[1].second;
			sumx = point[0].first + point[2].first;
			sumy = point[0].second + point[2].second;
		}
		else if (point[2] == point[3]) {
			jbx = point[2].first; jby = point[2].second;
			sumx = point[0].first + point[1].first;
			sumy = point[0].second + point[1].second;
		}
		cout << fixed << sumx - jbx << " " << sumy - jby << "\n";
	}
}