#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n, k;

	while (cin >> n >> k) {
		int arr[n] = {0};

		while (k--) {
			int num;
			cin >> num;

			arr[num - 1] = 1;
		}

		bool first = true;

		for (int i = 0; i < n; i++) {
			if (!arr[i]) {
				first = false;
				cout << i + 1 << ' ';
			}
		}

		if (first) cout << '*';
		cout << endl;
	}

	return 0;
}