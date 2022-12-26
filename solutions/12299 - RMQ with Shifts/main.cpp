#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

class SegmentTree {
    private:
        int n;
        vector<int> st, A, lazy;

        int l(int p) { return p << 1; }
        int r(int p) { return (p << 1) + 1; }

        int conquer(int a, int b) {
            if (a == -1) return b;
            if (b == -1) return a;

            return min(a, b);
        }

        void build(int p, int L, int R) {
            if (R == L) {
                st[p] = A[L];
            } else {
                int m = (L + R) / 2;
                build(l(p), L, m);
                build(r(p), m + 1, R);

                st[p] = conquer(st[l(p)], st[r(p)]);
            }
        }

        void propagate(int p, int L, int R) {
            if (lazy[p] != -1) {
                st[p] = lazy[p];
                if (L != R) {
                    lazy[l(p)] = lazy[r(p)] = lazy[p];
                } else {
                    A[L] = lazy[p];
                }
                lazy[p] = -1;
            }
        }

        int RMQ(int p, int L, int R, int i, int j) {
            propagate(p, L, R);
            if (i > j) return -1;
            if (L >= i && R <= j) return st[p];
            int m = (L + R) / 2;
            return conquer( RMQ(l(p), L,        m, i,               min(m, j)),
                            RMQ(r(p), m + 1,    R, max(i, m + 1),   j));
        }

        void update(int p, int L, int R, int i, int j, int val) {
            propagate(p, L, R);
            if (i > j) return;
            if (L >= i && R <= j) {
                lazy[p] = val;
                propagate(p, L, R);
            } else {
                int m = (L + R) / 2;
                update(l(p), L, m, i, min(m, j), val);
                update(r(p), m + 1, R, max(i, m + 1), j, val);

                int lsubtree = (lazy[l(p)] != -1 ? lazy[l(p)] : st[l(p)]);
                int rsubtree = (lazy[r(p)] != -1 ? lazy[r(p)] : st[r(p)]);

                st[p] = (lsubtree <= rsubtree ? st[l(p)] : st[r(p)]);
            }
        }

    public:
        SegmentTree(int sz) : n(sz), st(4 * n), lazy(4 * n, -1) {}

        SegmentTree(const vector<int>& v) : SegmentTree(v.size()) {
            A = v;
            build(1, 0, n - 1);
        }

        void update(int i, int j, int val) {
            update(1, 0, n - 1, i, j , val);
        }

        int RMQ(int i, int j) {
            return RMQ(1, 0, n - 1, i, j);
        }

        int get(int i) {
            return A[i];
        }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    SegmentTree segment_tree(v);

    string operation;
    for (int i = 0; i < m; i++) {
        cin >> operation;
        if (operation.find("shift") != string::npos) {
            int br_o = operation.find("(");
            string cut = operation.substr(br_o + 1);

            stringstream ss;
            ss << cut;

            vector<int> v, a;
            int idx;
            char ch;

            while (ss >> idx >> ch) {
                v.push_back(idx - 1);
                a.push_back(segment_tree.get(idx - 1));
            }

            for (int j = 0; j < v.size(); j++) {
                segment_tree.update(v[j], v[j], a[(j + 1) % v.size()]);
            }
        } else {
            int br_o = operation.find("(");
            int br_c = operation.find(")");
            int comma = operation.find(",");
            int L = stoi(operation.substr(br_o + 1, comma - br_o - 1));
            int R = stoi(operation.substr(comma + 1, br_c - comma - 1));

            cout << segment_tree.RMQ(L - 1, R - 1) << endl;
        }
    }

    return 0;
}