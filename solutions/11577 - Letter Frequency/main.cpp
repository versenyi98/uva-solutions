#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	string line;

	cin >> test_cases;
	getline(cin, line);

	while (test_cases--) {
		getline(cin, line);

		int freq[26] = {0};
		int maxi = 0;

		for (auto c : line) {
			if (isalpha(c)) {
				freq[tolower(c) - 'a']++;
				maxi = max(freq[tolower(c) - 'a'], maxi);
			}
		}

		for (int i = 0; i < 26; i++) {
			if (maxi == freq[i]) {
				cout << (char)('a' + i);
			}
		}
		cout << endl;
	}

	return 0;
}