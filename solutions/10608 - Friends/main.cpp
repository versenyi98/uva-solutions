#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

class UFDS {
    public:
        UFDS(int n) {
            parent.resize(n);
            size.resize(n);

            max_size = 0;

            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
                max_size = 1;
            }
        }

        int get_parent(int n) {
            return parent[n] == n ? n : parent[n] = get_parent(parent[n]);
        }

        void join(int i, int j) {
            int ip = get_parent(i);
            int jp = get_parent(j);

            if (ip == jp) {
                return;
            }

            size[ip] += size[jp];
            size[jp] = 0;

            parent[jp] = ip;
            max_size = max(max_size, size[ip]);
        }

        int get_max() {
            return max_size;
        }

    private:
        vector<int> parent;
        vector<int> size;
        int max_size;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n, m;
        cin >> n >> m;

        int a, b;
        UFDS ufds(n + 1);
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            ufds.join(a, b);
        }
        cout << ufds.get_max() << endl;
    }

    return 0;
}