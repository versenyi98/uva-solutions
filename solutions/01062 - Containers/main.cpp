#include <bits/stdc++.h>

using namespace std;

int main() {

	char st[26];
	int test_cases = 1;
	string line;

	while (cin >> line, line != "end") {
		cout << "Case " << test_cases++ << ": ";
		for (int i = 0; i < 26; i++) st[i] = 'Z';

		int max_ind = 0;

		for (int i = 0; i < line.length(); i++) {
			for (int j = 0; j < 26; j++) {
				if (line[i] <= st[j]) {
					st[j] = line[i];
					max_ind = max(j, max_ind);
					break;
				}
			}
		}

		cout << max_ind + 1 << endl;
	}

	return 0;
}