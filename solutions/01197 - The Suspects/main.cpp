#include <bits/stdc++.h>

using namespace std;

class UFDS {

	public:
		UFDS(int n) {
			parent.resize(n);
			size.resize(n);

			for (int i = 0; i < n; i++) {
				parent[i] = i;
				size[i] = 1;
			}
		}

		int get_parent(int n) {
			if (parent[n] == n) return n;

			int res = get_parent(parent[n]);
			parent[n] = res;

			return res;
		}

		bool is_same_set(int n, int m) {
			return get_parent(n) == get_parent(m);
		}

		void join(int n, int m) {
			int np = get_parent(n);
			int mp = get_parent(m);
			if (np == mp) return;
			int ns = get_size(n);

			size[mp] += ns;
			size[np] = 0;

			parent[np] = mp;
		}

		int get_size(int n) {
			return size[get_parent(n)];
		}

	private:
		vector<int> parent;
		vector<int> size;
};


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;

	while (cin >> n >> m, n || m) {
		UFDS ufds(n);

		for (int i = 0; i < m; i++) {
			int nm;
			cin >> nm;

			int base;
			int friend_;
			for (int i = 0; i < nm; i++) {
				if (i) {
					cin >> friend_;
					ufds.join(base, friend_);
				} else {
					cin >> base;
				}
			}
		}

		cout << ufds.get_size(0) << endl;
	}

	return 0;
}