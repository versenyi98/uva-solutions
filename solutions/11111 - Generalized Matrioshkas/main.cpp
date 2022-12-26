#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	string line;

	while (getline(cin, line)) {

		stack<int> brace;
		stack<int> capacity;
		int current = INT_MAX;

		stringstream ss;
		ss << line;

		int temp;
		int counter = 0;
		while (ss >> temp) {
			if (brace.size() == 0 && counter++) {
				brace.push(-1);
				break;
			}

			if (brace.size() == 0) {
				brace.push(-temp);
				capacity.push(-temp);

				if (temp > 0) break;
				continue;
			}

			if (temp < 0) {
				capacity.top() += temp;
				if (capacity.top() <= 0) {
					break;
				}
				brace.push(-temp);
				capacity.push(-temp);
			} else {
				if (brace.top() == temp) {
					brace.pop();
					capacity.pop();
				} else {
					break;
				}
			}
		}
		if (brace.size()) {
			cout << ":-( Try again." << endl;
		} else {
			 cout << ":-) Matrioshka!" << endl;
		}
	}

	return 0;
}