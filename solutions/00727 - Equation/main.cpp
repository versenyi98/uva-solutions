#include <bits/stdc++.h>

using namespace std;

string postfix(const string& str) {

	if (str.length() == 1) return str;

	int brackets = 0;

	int stored_pos = -1;
	int stored_depth = INT_MAX;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			brackets++;
		} else if (str[i] == ')') {
			brackets--;
		} else if (str[i] == '+' || str[i] == '-') {
			if (stored_pos < i && stored_depth >= brackets) {
				stored_pos = i;
				stored_depth = brackets;
			}

			if (stored_depth == brackets && (str[stored_pos] == '*' || str[stored_pos] == '/')) {
				stored_pos = i;
				stored_depth = brackets;
			}
		} else if (str[i] == '*' || str[i] == '/') {
			if (stored_pos < i && stored_depth >= brackets && (stored_pos == -1 || str[stored_pos] == '*' || str[stored_pos] == '/')) {
				stored_pos = i;
				stored_depth = brackets;
			}

			if (stored_depth > brackets) {
				stored_pos = i;
				stored_depth = brackets;
			}
		} else if (isdigit(str[i]) && stored_pos == -1) {
			stored_pos = i;
		}
	}

	// Avoid shitty input
	if (stored_pos == -1) return "";
	if (isdigit(str[stored_pos])) return string(1, str[stored_pos]);

	return postfix(str.substr(stored_depth, stored_pos - stored_depth)) + postfix(str.substr(stored_pos + 1, str.length() - stored_pos - 1 - stored_depth)) + str[stored_pos];
}

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string line;
	getline(cin, line);
	getline(cin, line);

	for (int i = 0; i < n; i++) {
		string infix = "";
		while (getline(cin, line) && line.length()) {
			infix += line;
		}

		if (i) cout << endl;
		cout << postfix(infix) << endl;

	}

	return 0;
}