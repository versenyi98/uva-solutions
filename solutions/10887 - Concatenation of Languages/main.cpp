#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	for (int i = 0; i < test_cases; i++) {
		int n, m;
		cin >> n >> m;
		string first[n];
		string temp;
		unordered_set<string> s;
		getline(cin, temp);
		for (int j = 0; j < n; j++) {
			getline(cin, first[j]);
		}

		for (int j = 0; j < m; j++) {
			getline(cin, temp);
			for (int k = 0; k < n; k++) {
				s.insert(first[k] + temp);
			}
		}

		cout << "Case " << i + 1 << ": " << s.size() << endl;
	}

	return 0;
}