#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	for (int tt = 0; tt < test_cases; tt++) {
		int n, q;
		int res[230] = {0};
		cin >> n >> q;

		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;

			for (int j = 0; j < 230; j++) {
				res[j] = max(res[j], j & a);
			}
		}

		for (int i = 0; i < q; i++) {
			int qq;
			cin >> qq;
			cout << res[qq] << endl;
		}
	}
	return 0;
}