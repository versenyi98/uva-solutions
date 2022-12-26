#include <bits/stdc++.h>

using namespace std;

int main() {

	int test_cases;
	cin >> test_cases;

	while (test_cases--) {
		int n;
		cin >> n;
		int number;

		priority_queue<int> red, blue;

		while (n--) {
			cin >> number;

			if (number < 0) {
				red.push(-number);
			} else {
				blue.push(number);
			}
		}

		int last = INT_MAX;

		int currently_red = red.top() > blue.top();
		int len = 0;
		while (true) {
			if ((currently_red && red.empty()) || (!currently_red && blue.empty())) {
				break;
			}

			if (currently_red) {
				while (red.size() && red.top() > last) {
					red.pop();
				}

				if (red.size()) {
					last = red.top();
					red.pop();
					len++;
				} else {
					break;
				}
			} else {
				while (blue.size() && blue.top() > last) {
					blue.pop();
				}

				if (blue.size()) {
					last = blue.top();
					blue.pop();
					len++;
				} else {
					break;
				}
			}
			currently_red = !currently_red;
		}

		cout << len << endl;
	}

	return 0;
}