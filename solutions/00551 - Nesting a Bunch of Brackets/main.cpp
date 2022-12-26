#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	string line;
	while (getline(cin, line)) {

		stack<char> st;

		int len = 0;
		bool bad = false;
		for (int i = 0; i < line.length(); i++) {
			len++;
			if (line[i] == '(') {
				if (i != line.length() - 1 && line[i + 1] == '*') {
					st.push('*');
					i++;
				} else {
					st.push(')');
				}
			} else if (line[i] == '{') {
				st.push('}');
			} else if (line[i] == '[') {
				st.push(']');
			} else if (line[i] == '<') {
				st.push('>');
			} else if ((line[i] == '*' && i != line.length() - 1 && line[i + 1] == ')') || line[i] == '>' || line[i] == ')' || line[i] == ']' || line[i] == '}') {
				if (st.size() && st.top() == line[i]) {
					st.pop();
					if (line[i] == '*') i++;
				} else {
					cout << "NO " << len << endl;
					bad = true;
					break;
				}
			}
		}

		if (bad) continue;

		if (!st.size()) {
			cout << "YES\n";
		} else {
			cout << "NO " << len + 1 << endl;
		}


	}

	return 0;
}