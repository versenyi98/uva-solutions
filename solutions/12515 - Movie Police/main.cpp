#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<string> s;
    string st;

    for (int i = 0; i < n; i++) {
        cin >> st;
        s.push_back(st);
    }

    for (int i = 0; i < q; i++) {
        int minii = INT_MAX;
        int ind = 0;

        string qq;
        cin >> qq;

        for (int j = 0; j < s.size(); j++) {
            if (s[j].length() < qq.length()) continue;
            for (int k = 0; k <= s[j].length() - qq.length(); k++) {
                int cc = 0;
                for (int l = 0; l < qq.length(); l++) {
                    cc += (s[j][k + l] != qq[l]);
                }

                if (cc < minii) {
                    minii = cc;
                    ind = j;
                }
            }
        }

        cout << ind + 1 << endl;
    }

    return 0;
}