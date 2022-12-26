#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	while (test_cases--) {
		int n, m;
		unordered_map<int, int> m1, m2;
		unordered_set<int> s;
		int temp;

		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			cin >> temp;
			m1[temp]++;
			s.insert(temp);
		}

		for (int i = 0; i < m; i++) {
			cin >> temp;
			m2[temp]++;
			s.insert(temp);
		}

		int count = 0;

		for (auto i : s) {
			count += abs(m1[i] - m2[i]);
		}

		cout << count << endl;
	}

	return 0;
}