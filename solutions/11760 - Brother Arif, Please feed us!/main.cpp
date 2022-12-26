#include <bits/stdc++.h>

using namespace std;

int main() {

	int r, c, n;
	int test_case = 0;
	while (cin >> r >> c >> n, n || r || c) {
		map<int, bool> x, y;
		for (int i = 0; i < n; i++) {
			int xx, yy;
			cin >> xx >> yy;
			x[xx] = true;
			y[yy] = true;
		}

		int bx, by;
		cin >> bx >> by;
		if ((!x[bx] && !y[by]) || (!x[min(r - 1, bx + 1)] && !y[by]) || (!x[max(0, bx - 1)] && !y[by]) || (!x[bx] && !y[min(c - 1, by + 1)]) || (!x[bx] && !y[max(0, by - 1)])) {
			cout << "Case " << ++test_case <<  ": Escaped again! More 2D grid problems!" << endl;
		} else {
			cout << "Case " << ++test_case << ": Party time! Let's find a restaurant!" << endl;
		}
	}

	return 0;
}