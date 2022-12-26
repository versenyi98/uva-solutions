#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;

	while (scanf("%d", &n), n) {
		int arr[n];

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}

		sort(arr, arr + sizeof(arr) / sizeof(arr[0]));

		for (int i = 0; i < n; i++) {
			if (i) putchar(' ');
			printf("%d", arr[i]);
		}
		puts("");
	}

	return 0;
}