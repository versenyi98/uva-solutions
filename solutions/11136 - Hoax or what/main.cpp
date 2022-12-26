#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	while (scanf("%d\n", &n), n) {

		multiset<int, greater<int>> ms;

		uint64_t sum = 0;
		int num;
		while (n--) {
			int m;
			scanf("%d", &m);

			while (m--) {
				scanf("%d", &num);
				ms.insert(num);
			}

			sum += *ms.begin() - *--ms.end();
			ms.erase(ms.begin());
			ms.erase(--ms.end());
		}

		printf("%lu\n", sum);
	}

	return 0;
}