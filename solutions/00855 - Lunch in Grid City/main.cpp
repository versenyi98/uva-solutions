#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases = 0;
	cin >> test_cases;

	while (test_cases--) {
		int n, m, f;
		cin >> n >> m >> f;

		vector<int> fx, fy;

		int x, y;
		while (f--) {
			cin >> x >> y;
			fx.push_back(x);
			fy.push_back(y);
		}

		sort(fx.begin(), fx.end());
		sort(fy.begin(), fy.end());
		int pos = (fx.size() - 1) / 2;
		cout << "(Street: " << fx[pos] << ", Avenue: " << fy[pos] << ")" << endl;
	}

	return 0;
}