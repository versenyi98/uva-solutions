#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1000000];
uint64_t res;

void merge(int l, int m, int r) {

	int nl = m - l + 1;
	int nr = r - m ;

	int larr[nl];
	int rarr[nr];

	for (int i = 0; i < nl; i++) larr[i] = arr[l + i];
	for (int i = 0; i < nr; i++) rarr[i] = arr[m + 1 + i];

	int li = 0;
	int ri = 0;
	int ki = l;

	while (li < nl && ri < nr) {
		if (larr[li] <= rarr[ri]) {
			arr[ki++] = larr[li++];
		} else {
			res += nl - li;
			arr[ki++] = rarr[ri++];
		}
	}

	while (li < nl) {
		arr[ki++] = larr[li++];
	}

	while (ri < nr) {
		arr[ki++] = rarr[ri++];
	}

}

void merge_sort(int l, int r) {

	if (l == r) {
		return;
	}

	int m = (l + r) >> 1;
	merge_sort(l, m);
	merge_sort(m + 1, r);
	merge(l, m, r);

}

int main() {

	std::ios_base::sync_with_stdio(false);

	while (cin >> n, n) {
		for (int i = 0; i < n; i++) cin >> arr[i];
		res = 0;
		merge_sort(0, n - 1);
		cout << res << endl;
	}

	return 0;
}