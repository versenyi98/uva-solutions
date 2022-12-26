#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n, n) {
		int arr[n];
		while (cin >> arr[0], arr[0]) {
			for (int i = 1; i < n; i++) cin >> arr[i];
			int ind = 0;

			stack<int> s;
			for (int i = 0; i < n; i++) {
				s.push(i + 1);
				while (s.size() && s.top() == arr[ind]) {
					s.pop();
					ind++;
				}
			}
			if (ind == n) {
				cout << "Yes" << endl;
			} else {
				cout << "No" << endl;
			}
		}
		cout << endl;
	}

	return 0;
}