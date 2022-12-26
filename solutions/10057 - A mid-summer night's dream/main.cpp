#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	while (cin >> n) {
		map<int, int> occurance;

		int numbers[n];
		for (int i = 0; i < n; i++) {
			cin >> numbers[i];
			occurance[numbers[i]]++;
		}

		sort(numbers, numbers + n);

		if (n % 2 == 1) {
			cout << numbers[n / 2] << " " << occurance[numbers[n / 2]] << " " << 1 << endl;
		} else {
			int occ = occurance[numbers[n / 2 - 1]];
			if (numbers[n / 2 - 1] != numbers[n / 2 ])
				occ += occurance[numbers[n / 2]];

			cout << numbers[n / 2 - 1] << " " << occ << " " << numbers[n / 2] - numbers[n / 2 - 1] + 1 << endl;

		}
	}

	return 0;
}