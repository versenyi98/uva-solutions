#include <bits/stdc++.h>

using namespace std;

int main() {

    int tc = 0;
    cin >> tc;

    string line;
    getline(cin, line);

    while (tc--) {

        getline(cin, line);

        vector<pair<int, string>> perm;

        getline(cin, line);

        int pos;
        while (pos = line.find(' '), pos != string::npos) {
            perm.push_back({stoi(line.substr(0, pos)), ""});
            line = line.substr(pos + 1);
        }
        perm.push_back({stoi(line), ""});
        int cc = 0;
        getline(cin, line);
        while (pos = line.find(' '), pos != string::npos) {
            perm[cc++].second = line.substr(0, pos);
            line = line.substr(pos + 1);
        }
        perm[cc++].second = line;
        sort(perm.begin(), perm.end());
        for (auto i : perm) {
            cout << i.second << endl;
        }
        if (tc) cout << endl;
    }
}