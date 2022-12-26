#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n, n) {
		vector<string> str;
		str.resize(n);

		for (int i = 0; i < n; i++) {
			cin >> str[i];
		}

		sort(str.begin(), str.end());

		string res = "";
		bool closed = false;
		for (int i = 0; i < str[n / 2 - 1].length(); i++) {
			string test = str[n / 2 - 1].substr(0, i + 1);
			if (test >= str[n / 2 - 1] && test < str[n / 2]) {
				res = test;
				closed = true;
				break;
			}

			if (isalpha(test.back() + 1)) {
				test.back()++;
				if (test >= str[n / 2 - 1] && test < str[n / 2]) {
					res = test;
					closed = true;
					break;
				}
			}
		}
		cout << res << endl;
	}

	return 0;
}