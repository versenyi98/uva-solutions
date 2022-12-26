#include <bits/stdc++.h>

using namespace std;

int main() {

	stack<string> st;

	int n;
	cin >> n;

	string action;
	while (n--) {
		cin >> action;

		if (action == "Test") {
			if (st.size()) {
				cout << st.top() << endl;
			} else {
				cout << "Not in a dream" << endl;
			}
		} else if (action == "Kick") {
			if (st.size()) st.pop();
		} else {
			cin >> action;
			st.push(action);
		}
	}

	return 0;
}