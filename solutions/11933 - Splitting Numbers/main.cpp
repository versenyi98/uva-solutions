#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	while (cin >> n, n) {
		int res1 = 0;
		int res2 = 0;
		int cc = 0;

		for (int i = 0; i < 32; i++) {
			if (n & (1 << i)) {
				cc++;
			} else {
				continue;
			}

			if (cc & 1) {
				res1 |= (n & (1 << i));
			} else {
				res2 |= (n & (1 << i));
			}
		}

		cout << res1 << ' ' << res2 << endl;
	}

	return 0;
}