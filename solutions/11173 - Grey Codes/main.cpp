#include <bits/stdc++.h>

using namespace std;

int main() {

	int test_cases;
	scanf("%d", &test_cases);

	while (test_cases--) {
		int n, m;
		scanf("%d %d", &n, &m);

		int res = 0;
		for (int i = n; i > 0; i--) {
			res <<= 1;
			if (m >= pow(2, i - 1)) {
				m = pow(2, i) - 1 - m;
				res++;
			}
		}
		printf("%d\n", res);
	}

	return 0;
}