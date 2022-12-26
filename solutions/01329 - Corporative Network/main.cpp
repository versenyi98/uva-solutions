#include <bits/stdc++.h>

using namespace std;

class UFDS {

	public:
		UFDS(int n) {
			parent.resize(n);
			distance.resize(n);

			for (int i = 0; i < n; i++) {
				parent[i] = i;
				distance[i] = 0;
			}
		}

		int get_parent(int n) {
			if (parent[n] == n) return n;

			int res = get_parent(parent[n]);
			distance[n] += distance[parent[n]];
			parent[n] = res;
			return res;
		}

		void join(int n, int m) {
			parent[n] = m;
			distance[n] = abs(n - m) % 1000;
		}

		int get_distance(int n) {
			return distance[n];
		}

	private:
		vector<int> parent;
		vector<int> distance;
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int test_cases;

	cin >> test_cases;

	for (int tt = 0; tt < test_cases; tt++) {
		int n;
		cin >> n;

		UFDS ufds(n + 1);
		char opt;

		while (cin >> opt && opt != 'O') {
			if (opt == 'E') {
				int q;
				cin >> q;
				ufds.get_parent(q);
				cout << ufds.get_distance(q) << endl;
			} else {
				int a, b;
				cin >> a >> b;
				ufds.join(a, b);
			}
		}
	}

	return 0;
}