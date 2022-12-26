#include <bits/stdc++.h>

using namespace std;

int main() {

	int test_cases;
	cin >> test_cases;

	for (int tt = 0; tt < test_cases; tt++) {
		int R, C, M, N;
		cin >> R >> C >> M >> N;

		map<char, int> occurance;
		int max_occurance = INT_MIN;
		char c;

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cin >> c;
				occurance[c]++;
				max_occurance = max(max_occurance, occurance[c]);
			}
		}

		int max_counter = 0;

		for (auto i : occurance) {
			if (i.second == max_occurance) {
				max_counter += i.second;
			}
		}

		cout << "Case " << tt + 1 << ": " << max_counter * M + (R * C - max_counter) * N << endl;

	}

	return 0;
}