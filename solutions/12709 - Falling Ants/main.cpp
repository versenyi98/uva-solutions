#include <bits/stdc++.h>

using namespace std;

struct ant {
	int L, W, H;

	bool operator<(const ant& a) const {
		if (H == a.H) {
			return L * W * H > a.L * a.W * a.H;
		}

		return H > a.H;
	}
};

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n, n) {
		vector<ant> ants;
		ant a;
		while (n--) {
			cin >> a.L >> a.W >> a.H;
			ants.push_back(a);
		}

		sort(ants.begin(), ants.end());
		ant first = ants[0];

		cout << first.W * first.H * first.L << endl;
	}

	return 0;
}