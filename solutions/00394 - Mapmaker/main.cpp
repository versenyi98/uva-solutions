#include <bits/stdc++.h>

using namespace std;

int main() {

    int N, R;
    cin >> N >> R;

    string names[N];
    map<string, int> index_on_name;
    int base[N], dimension[N], size_in_bytes[N];
    vector<int> C[N];
    vector<pair<int, int>> bounds[N];
    
    for (int i = 0; i < N; i++) {
        cin >> names[i] >> base[i] >> size_in_bytes[i] >> dimension[i];
        index_on_name[names[i]] = i;
        for (int j = 0; j < dimension[i]; j++) {
            int l, u;
            cin >> l >> u;
            bounds[i].push_back({l, u});
        }
    }
    
    for (int i = 0; i < N; i++) {

        C[i].push_back(size_in_bytes[i]);

        for (int d = dimension[i] - 1; d >= 1; d--) {
            C[i].push_back(C[i].back() * (bounds[i][d].second - bounds[i][d].first + 1));
        }
        reverse(C[i].begin(), C[i].end());
    }
    
    for (int i = 0; i < R; i++) {
        string name;
        cin >> name;
        int ii = index_on_name[name];
        int val = base[ii];
        vector<int> q;
        for (int j = 0; j < dimension[ii]; j++) {
            int index_;
            cin >> index_;
            q.push_back(index_);
            val += (index_ - bounds[ii][j].first) * C[ii][j];
        }
        cout << name;
        cout << "[";
        for (int i = 0; i < q.size(); i++) {
            if (i) cout << ", ";
            cout << q[i];
        }
        cout << "] = " << val << endl;
    }
}