#include <bits/stdc++.h>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m;

	while (cin >> n >> m) {
		unordered_map<int, int> occurance;
		unordered_map<int, unordered_map<int, int>> position;
		int number;
		for (int i = 0; i < n; i++) {
			cin >> number;

			position[number][++occurance[number]] = i + 1;
		}

		for (int i = 0; i < m; i++) {
			int pos, num;
			cin >> pos >> num;
			cout << position[num][pos] << endl;
		}
	}

	return 0;
}