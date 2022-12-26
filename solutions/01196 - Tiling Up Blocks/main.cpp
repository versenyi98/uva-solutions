#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    int tc = 0;
    while (cin >> n) {
        tc++;
        if (n == 0) {
            cout << "*\n";
            break;
        }
        int mm = 0;

        vector<pair<int, int>> v;
        vector<int> val;
        int l, m;
        for (int i = 0; i < n; i++) {
            cin >> l >> m;
            val.push_back(1);
            mm = max(mm, 1);
            v.push_back({l, m});
        }

        sort(v.begin(), v.end(), [] (pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        for (int i = v.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < v.size(); j++) {
                if (v[i].first <= v[j].first && v[i].second <= v[j].second) {
                    val[i] = max(val[i], val[j] + 1);
                    mm = max(val[i], mm);
                }
            }
        }
        
        cout << mm << endl;
    }
}