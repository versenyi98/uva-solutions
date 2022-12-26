#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;

	while (cin >> n) {

		vector<int> v;
		for (int i = 0; i < pow(2, n); i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}

		vector<int> potent;
		for (int i = 0; i < pow(2, n); i++) {
			int pot = 0;
			for (int j = 0; j < n; j++) {
				pot += v[i ^ (1 << j)];
			}
			potent.push_back(pot);
		}

		int maximal = 0;
		for (int i = 0; i < pow(2, n); i++) {
			int pot = 0;
			for (int j = 0; j < n; j++)
				maximal = max(maximal, potent[i] + potent[i ^ (1 << j)]);
		}


		cout << maximal << endl;
	}

	return 0;
}