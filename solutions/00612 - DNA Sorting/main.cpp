#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	auto unsortedness = [] (string a) {
		int res = 0;

		for (int i = 0; i < a.length(); i++) {
			for (int j = i + 1; j < a.length(); j++) {
				if (a[i] > a[j]) res++;
			}
		}

		return res;
	};

	for (int tc = 0; tc < test_cases; tc++) {
		if (tc) cout << endl;

		int n, m;
		cin >> n >> m;
		map<string, int> uns;
		vector<string> dna;
		dna.resize(m);

		for (int i = 0; i < m; i++) {
			cin >> dna[i];
			uns[dna[i]] = unsortedness(dna[i]);
		}

		stable_sort(dna.begin(), dna.end(), [&] (string a, string b) {
			return uns[a] < uns[b];
		});

		for (auto d: dna) {
			cout << d << endl;
		}
	}

	return 0;
}