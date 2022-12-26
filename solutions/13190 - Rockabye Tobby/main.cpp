#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	for (int i = 0; i < test_cases; i++) {

		int n, k;
		cin >> n >> k;

		priority_queue<pair<pair<int, int>, pair<int, string>>, vector<pair<pair<int, int>, pair<int, string>>>, greater<pair<pair<int, int>, pair<int, string>>>> pq;

		while (n--) {
			string medicine;
			int freq;

			cin >> medicine >> freq;

			pq.push({{freq, -n}, {freq, medicine}});
		}

		while (k--) {
			auto top = pq.top();
			pq.pop();

			cout << top.first.first << ' ' << top.second.second << endl;
			pq.push({{top.first.first + top.second.first, top.first.second}, top.second});
		}
	}

	return 0;
}