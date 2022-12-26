#include <bits/stdc++.h>

using namespace std;

int poww(int n, int k) {
	if (k == 1) return n;
	return n * pow(n, k - 1);
}

int main() {

	int test_cases;
	cin >> test_cases;

	while (test_cases--) {

		vector<int> v;
		uint64_t price = 0;

		int num;
		while (cin >> num, num) {
			v.push_back(num);
		}

		sort(v.begin(), v.end(), greater<int>());

		for (int i = 0; i < v.size() && price <= 5000000; i++) {
			price += 2 * poww(v[i], i + 1);
		}
		if (price > 5000000) {
			cout << "Too expensive\n";
			continue;
		}
		cout << price << endl;
	}

	return 0;
}