#include <bits/stdc++.h>

using namespace std;

int main() {

	string line;

	while (cin >> line) {

		vector<string> permutations = {line};

		string prev = line;
		string next = line;

		for (int i = 0; i < 10; i++) {
			prev_permutation(prev.begin(), prev.end());
			next_permutation(next.begin(), next.end());
			permutations.push_back(prev);
			permutations.push_back(next);
		}

		vector<pair<int, string>> res;

		for (auto i : permutations) {
			int dist = 0;
			int min_dist = INT_MAX;
			for (int j = 0; j < (int) i.length() - 1; j++) {
				min_dist = min(min_dist, abs(i[j] - i[j + 1]));
			}

			res.push_back({min_dist, i});
		}

		sort(res.begin(), res.end(), [] (pair<int, string> a, pair<int, string> b) {
			if (a.first != b.first) return a.first < b.first;
			return a.second > b.second;
		});

		cout << res.back().second << res.back().first<< endl;
	}

	return 0;
}