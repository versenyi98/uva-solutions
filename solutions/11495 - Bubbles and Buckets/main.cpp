#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100000];
uint64_t res = 0;

void merge(int l, int m, int r) {
	int nl = m - l + 1;
	int nr = r - m;

	int larr[nl];
	int rarr[nr];
	for (int i = 0; i < nl; i++) larr[i] = arr[l + i];
	for (int i = 0; i < nr; i++) rarr[i] = arr[m + 1 + i];

	int li = 0;
	int ri = 0;
	int ki = l;

	while (li < nl && ri < nr) {
		if (larr[li] <= rarr[ri]) {
			arr[ki] = larr[li];
			li++;
		} else {
			arr[ki] = rarr[ri];
			ri++;
			res += nl - li;
		}
		ki++;
	}

	while (li < nl) {
		arr[ki] = larr[li];
		li++;
		ki++;
	}

	while (ri < nr) {
		arr[ki] = rarr[ri];
		ri++;
		ki++;
	}
}

void merge_sort(int l, int r) {
	int m;

	if (l < r) {
		m = (r + l) / 2;
		merge_sort(l, m);
		merge_sort(m + 1, r);
		merge(l, m, r);
	}

}

int main() {

	while (cin >> n, n) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		res = 0;
		merge_sort(0, n - 1);
		if (res % 2 == 1) {
			cout << "Marcelo" << endl;
		} else {
			cout << "Carlos" << endl;
		}
	}

	return 0;
}