#include <bits/stdc++.h>

using namespace std;

int main() {

	string line;

	while (getline(cin, line)) {

		list<char> l;
		list<char>::iterator it = l.begin();
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '[') {
				it = l.begin();
			} else if (line[i] == ']') {
				it = l.end();
			} else {
				l.insert(it, line[i]);
			}
		}

		for (auto i : l) {
			cout << i;
		}
		cout << endl;
	}

	return 0;
}