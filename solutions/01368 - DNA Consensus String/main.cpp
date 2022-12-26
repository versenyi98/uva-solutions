#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	map<char, int> cti;	cti['A'] = 0; cti['C'] = 1; cti['G'] = 2; cti['T'] = 3;
	char itc[4]; itc[0] = 'A'; itc[1] = 'C'; itc[2] = 'G'; itc[3] = 'T';

	int test_cases;
	cin >> test_cases;

	while (test_cases--) {
		int n, k;
		cin >> n >> k;

		int count[k][4] = {0};
		int maxi[k] = {0};
		string line;

		for (int i = 0; i < n; i++) {
			cin >> line;
			for (int j = 0; j < k; j++) {
				count[j][cti[line[j]]]++;
				maxi[j] = max(maxi[j], count[j][cti[line[j]]]);
			}
		}

		int sum = 0;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < 4; j++) {
				if (maxi[i] == count[i][j]) {
					cout << itc[j];
					sum += (n - count[i][j]);
					break;
				}
			}
		}
		cout << endl << sum << endl;
	}


	return 0;
}