#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	scanf("%d", &test_cases);

	for (int tt = 0; tt < test_cases; tt++) {

		int n;
		scanf("%d", &n);
		unordered_set<int> stamps[n];
		unordered_map<int, int> owners;

		for (int i = 0; i < n; i++) {
			int m;
			scanf("%d", &m);

			for (int j = 0; j < m; j++) {
				int l;
				scanf("%d", &l);

				stamps[i].insert(l);
			}

			for (auto j : stamps[i]) owners[j]++;
		}

		int total_unique = 0;

		for (auto i : owners) {
			if (i.second == 1) total_unique++;
		}

		printf("Case %d:", tt + 1);
		for (int i = 0; i < n; i++) {
			int counter = 0;

			for (auto j : stamps[i]) {
				if (owners[j] == 1) {
					counter++;
				}
			}
			printf(" %.6f%%", (double) counter / (double) total_unique * 100.00);
		}
		printf("\n");
	}

	return 0;
}