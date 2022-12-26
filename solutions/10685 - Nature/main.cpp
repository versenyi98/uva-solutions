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

		int get_parent(int s) {
			if (parent[s] == s) return s;

			int res = get_parent(parent[s]);
			parent[s] = res;

			return res;
		}

		bool is_same_set(int a, int b) {
			return get_parent(a) == get_parent(b);
		}

		void join(int a, int b) {
			int ap = get_parent(a);
			int bp = get_parent(b);
			if (ap == bp) return;

			int sa = get_size(a);
			size[bp] += sa;
			size[ap] = 0;

			parent[ap] = bp;
		}

		int get_size(int a) {
			return size[get_parent(a)];
		}
	private:
		vector<int> parent;
		vector<int> size;
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m;

	while(cin >> n >> m, n || m) {
		unordered_map<string, int> idx;
		string str;

		for (int i = 0; i < n; i++) {
			cin >> str;
			idx[str] = i;
		}

		UFDS ufds(n);

		int maximum = 1;
		string a, b;

		for (int i = 0; i < m; i++) {
			cin >> a >> b;

			int idxa = idx[a];
			int idxb = idx[b];

			ufds.join(idxa, idxb);
			maximum = max(maximum, ufds.get_size(idxb));
		}

		cout << maximum << endl;
	}

	return 0;
}