#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	int tc = 0;
	while (cin >> n, n) {
		cout << "Case " << ++tc << ": ";
		int a[n], b[n], c, sl[n], aw[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i] >> c;
			
			if (c - 1 < a[i]) {
				// awake
				aw[i] = a[i] - c + 1;
				sl[i] = -1;
			} else {
				// sleep
				aw[i] = -1;
				sl[i] = a[i] + b[i] - c + 1;
			}
		}

		int cc = 0;
		while (true) {
			int awake = 0;

			for (int i = 0; i < n; i++) {
				if (aw[i] > 0) awake++;
			}

			if (awake == n) break;

			for (int i = 0; i < n; i++) {
				if (sl[i] > 0) {
					sl[i]--;
					if (sl[i] == 0) {
						sl[i] = -1;
						aw[i] = a[i];
					}
				} else {
					aw[i]--;
					if (aw[i] == 0) {
						if (awake >= n - awake) {
							aw[i] = a[i];
							continue;
						}
						aw[i] = -1;
						sl[i] = b[i];
					}
				}
			}
			cc++;
			if (cc > 1000) break;
		}

		if (cc > 1000) {
			cout << "-1" << endl;
			continue;
		}
		cout << cc + 1 << endl;

	}

	return 0;
}