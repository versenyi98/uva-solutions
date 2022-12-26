#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	while (cin >> n && n) {
		vector<string> numbers;
		string line;
		for (int i = 0; i < n; i++) {
			cin >> line;
			numbers.push_back(line);
		}

		sort(numbers.begin(), numbers.end(), [=] (string a, string b) {
			string ab = a + b;
			string ba = b + a;

			return ab > ba;
		});

		for (auto s : numbers) cout << s;
		cout << endl;
	}

	return 0;
}