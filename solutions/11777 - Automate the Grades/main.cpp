#include <bits/stdc++.h>

using namespace std;

int main() {

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int t1, t2, finals, att, c[3];

		cin >> t1 >> t2 >> finals >> att;
		for (int j = 0; j < 3; j++) cin >> c[j];
		sort(c, c + 3);

		double res = t1 + t2 + finals + att + (c[2] + c[1]) / 2.0;

		cout << "Case " << i + 1 << ": ";
		if (res >= 90) {
			cout << 'A';
		} else if (res >= 80) {
			cout << 'B';
		} else if (res >= 70) {
			cout << 'C';
		} else if (res >= 60) {
			cout << 'D';
		} else {
			cout << 'F';
		}
		cout << endl;
	}

	return 0;
}