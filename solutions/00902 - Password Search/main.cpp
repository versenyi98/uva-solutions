#include <bits/stdc++.h>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	int n;

	while (cin >> n) {

		string res = "";
		unordered_map<string, int> m;
		int mx = 0;
		string password = "";
		string line;
		cin >> line;
		for (int i = 0; i < line.length(); i++) {

			password.push_back(line[i]);

			if (password.length() > n) password = password.substr(1);
			if (password.length() == n) {
				m[password]++;
				if (m[password] > mx) {
					mx = m[password];
					res = password;
				}
			}
		}

		cout << res << endl;
	}

	return 0;
}