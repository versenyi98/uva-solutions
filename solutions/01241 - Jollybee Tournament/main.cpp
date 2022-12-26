#include <bits/stdc++.h>

using namespace std;

int main() {

	int test_cases;
	cin >> test_cases;

	while (test_cases--) {
		int n, m;
		cin >> n >> m;

		bool bit_set[(int)pow(2, n)];

		for (int i = 0; i < pow(2, n); i++) bit_set[i] = true;

		for (int i = 0; i < m; i++) {
			int t;
			cin >> t;
			bit_set[t - 1] = false;
		}

		int size_ = pow(2, n);
		int wo = 0;
		while (size_) {
			size_ = size_ / 2;
			for (int i = 0; i < size_; i++) {
				if (bit_set[i * 2] != bit_set[i * 2 + 1]) {
					wo++;
					bit_set[i] = true;
				} else {
					bit_set[i] = bit_set[i * 2];
				}
			}
		}

		cout << wo << endl;
	}

	return 0;
}