#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;

	while (n--) {
		string line;
		cin >> line;

		int count[26] = {0};

		for (auto c : line) {
			count[c - 'A']++;
		}
		cout << min(count['M' - 'A'], min(count[0] / 3, min(count['R' - 'A'] / 2, min(count['G' - 'A'], min(count['I' - 'A'], count['T' - 'A']))))) << endl;
	}

	return 0;
}