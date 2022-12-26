#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	set<string> words;

	string line;
	while (getline(cin, line)) {
		for (int i = 0; i < line.length(); i++) {
			if (isalpha(line[i])) {
				int start = i;
				int end = i;

				while (end < line.size() && isalpha(line[end])) {
					line[end] = tolower(line[end]);
					end++;
				}
				words.insert(line.substr(start, end - start));
				i = end - 1;
			}
		}
	}
	for (auto s : words) cout << s << endl;

	return 0;
}