#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	string line;

	getline(cin, line);

	for (int tt = 0; tt < test_cases; tt++) {

		unordered_map<int, string> m;
		unordered_set<string> words;

		int cc = 0;
		while (getline(cin, line), line != "END") {

			for (int i = 0; i < line.length(); i++) {
				if (isalpha(line[i])) {
					int beg = i;
					int end = i;
					while (end < line.length() && isalpha(line[end])) {
						end++;
					}
					i = end - 1;

					string w = line.substr(beg, end - beg);
					m[cc++] = w;
					words.insert(w);
				}
			}
		}

		unordered_map<string, bool> involved;
		unordered_map<string, int> last_occ;

		int beg = 0, end = -1;
		int beg_store = -100000, end_store = 100000;
		int counter = 0;
		while (true) {
			while (counter != words.size()) {
				end++;
				if (end == cc) break;
				if (!involved[m[end]]) {
					involved[m[end]] = true;
					counter++;
				}
				last_occ[m[end]] = end;
			}

			if (end == cc) break;

			if (end_store - beg_store > end - beg) {
				end_store = end;
				beg_store = beg;
			}

			while (counter == words.size()) {
				if (last_occ[m[beg]] == beg) {
					if (end_store - beg_store > end - beg) {
						end_store = end;
						beg_store = beg;
					}
					counter--;
					involved[m[beg]] = false;
				}
				beg++;
			}
		}

		cout << "Document " << tt + 1 << ": " << beg_store + 1 << " " << end_store + 1 << endl;
	}

	return 0;
}