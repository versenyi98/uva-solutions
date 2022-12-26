#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, tt = 0;
	while(cin >> n, n) {
		cout << "Case #" << ++tt << ":\n";

		int t[10000] = {0};
		int res = -1;
		for (int i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;

			while (a < 10000) {
				t[a]++;
				if (i == n - 1 && t[a] == n) {
					res = a;
					break;
				}
				a += c - b;
			}

		}

		if (res == -1) {
			cout << "Unknown bugs detected." << endl;
		} else {
			cout << "The actual year is " << res << "." << endl;
		}
		cout << endl;
	}

	return 0;
}