#include <bits/stdc++.h>

using namespace std;

int main() {

	vector<int> positions;

	int n;
	cin >> n;
	string c[n];
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		if (c[i] != "?") {
			positions.push_back(i);
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int pos;
		cin >> pos;
		pos--;

		int min_dist = INT_MAX;
		int pos_ = 0;

		for (int i = 0; i < positions.size(); i++) {
			if (abs(positions[i] - pos) < min_dist) {
				min_dist = abs(positions[i] - pos);
				pos_ = positions[i];
			} else if (abs(positions[i] - pos) == min_dist) {
				cout << "middle of " << c[pos_] << " and " << c[positions[i]] << endl;
				min_dist = -1;
				break;
			} else {
				break;
			}
		}

		if (min_dist == -1) {
			continue;
		}

		if (pos_ - pos < 0) {
			for (int i = 0; i < min_dist; i++) {
				cout << "right of ";
			}
			cout << c[pos_] << endl;
		} else {
			for (int i = 0; i < min_dist; i++) {
				cout << "left of ";
			}
			cout << c[pos_] << endl;		}
	}
	return 0;
}