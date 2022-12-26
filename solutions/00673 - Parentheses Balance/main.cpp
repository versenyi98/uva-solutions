#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;

	string line;
	cin >> n;
	getline(cin, line);

	while (n--) {
		getline(cin, line);
		stack<char> st;

		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '(') {
				st.push(')');
			} else if (line[i] == '[') {
				st.push(']');
			} else if (line[i] == ']' || line[i] == ')') {
				if (st.size() && st.top() == line[i]) {
					st.pop();
				} else {
					st.push(line[i]);
					break;
				}
			} else {
				st.push(line[i]);
				break;
			}
		}

		if (st.size()) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}

	return 0;
}