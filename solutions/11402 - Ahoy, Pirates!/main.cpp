#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

class SegmentTree {
    int n;
    vector<int> st, A, lazy;

    int l(int p) {
        return p << 1;
    }

    int r(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int L, int R) {
        if (L == R) {
            st[p] = A[L];
        } else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);

            st[p] = st[l(p)] + st[r(p)];
        }
    }

    int flip(int x) {
        return 1 - x;
    }

    void propegate(int p, int L, int R) {
        if (lazy[p] == -1) return;
        if (lazy[p] == 1) {
            st[p] = R - L + 1;
        } else if (lazy[p] == 0) {
            st[p] = 0;
        } else if (lazy[p] == 2) {
            st[p] = (R - L + 1 - st[p]);
        }

        if (R != L) {
            if (lazy[p] < 2) {
                lazy[l(p)] = lazy[r(p)] = lazy[p];
            } else {
                lazy[l(p)] = flip(lazy[l(p)]);
                lazy[r(p)] = flip(lazy[r(p)]);
            }
        }

        lazy[p] = -1;
    }

    int RSQ(int p, int L, int R, int i, int j, int depth = 0) {
        propegate(p, L, R);

        if (i > j) return 0;
        if (L >= i && R <= j) return st[p];
        int m = (L + R) / 2;

        return RSQ(l(p), L, m, i, min(m, j), depth + 1) + RSQ(r(p), m + 1, R, max(m + 1, i), j, depth + 1);
    }

    void update(int p, int L, int R, int i, int j, int type) {
        propegate(p, L, R);
        if (i > j) return;

        // 0 - 0s
        // 1 - 1s
        // 2 - invert

        if (L >= i && R <= j) {
            lazy[p] = type;
            propegate(p, L, R);
        } else {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), type);
            update(r(p), m + 1, R, max(i, m + 1), j, type);

            st[p] = st[l(p)] + st[r(p)];
        }
    }

public:
    SegmentTree(int sz) : A(ceil(pow(2, log2(sz)))), n(ceil(pow(2, log2(sz)))), st(4 * n), lazy(4 * n, -1) {}

    SegmentTree(const string& s) : SegmentTree(s.length()) {
        for (int i = 0; i < s.length(); i++) {
            A[i] = (s[i] == '1' ? 1 : 0);
        }
        build(1, 0, n - 1);
    }

    void update(int i, int j, int type) {
        update(1, 0, n - 1, i, j , type);
    }

    int RSQ(int i, int j) {
        return RSQ(1, 0, n - 1, i, j);
    }

    int get(int i) {
        return A[i];
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    for (int tt = 0; tt < test_cases; tt++) {
        cout << "Case " << tt + 1 << ":" << endl;
        int n;
        cin >> n;

        int size = 0;

        int m;
        string str;
        string s = "";

        for (int i = 0; i < n; i++) {
            cin >> m >> str;
            for (int j = 0; j < m; j++) {
                s += str;
            }
            size += m * str.length();
        }
        SegmentTree segment_tree(s);
        int q;
        cin >> q;

        char ch;
        int a, b;
        int qn = 0;
        for (int i = 0; i < q; i++) {
            cin >> ch >> a >> b;

            if (ch == 'S') {
                cout << "Q" << ++qn << ": " << segment_tree.RSQ(a, b) << endl;
            } else if (ch == 'I') {
                segment_tree.update(a, b, 2);
            } else if (ch == 'E') {
                segment_tree.update(a, b, 0);
            } else {
                segment_tree.update(a, b, 1);
            }
        }
    }

    return 0;
}