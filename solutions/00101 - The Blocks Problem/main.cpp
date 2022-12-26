#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    int table[n][n];
    int size_[n];
    map<int, pair<int, int>> m;

    for (int i = 0; i < n; i++) {
        table[i][0] = i;
        size_[i] = 1;
        m[i] = make_pair(i, 0);
    }

    string line;
    getline(cin, line);

    while (getline(cin, line), line != "quit") {
        int from, to;
        string op1, op2;

        auto lline = line;

        int sp = line.find(' ');
        op1 = line.substr(0, sp);
        line = line.substr(sp + 1);

        sp = line.find(' ');
        from = stoi(line.substr(0, sp));
        line = line.substr(sp + 1);
        
        sp = line.find(' ');
        op2 = line.substr(0, sp);
        line = line.substr(sp + 1);

        to = stoi(line);
        
        if (op1.compare("move") == 0) {
            int f = m[from].first;
            int s = m[from].second;
            int ff = m[to].first;
            int ss = m[to].second;

            if (ff == f) continue;

            // put everthing away from "from"
            for (int i = size_[f] - 1; i > s; i--) {
                table[table[f][i]][size_[table[f][i]]] = table[f][i];
                m[table[f][i]] = make_pair(table[f][i], size_[table[f][i]]);
                size_[table[f][i]]++;
                size_[f]--;
            }

            if (op2.compare("onto") == 0) {
                // put everything away from "to"
                for (int i = size_[ff] - 1; i > ss; i--) {
                    table[table[ff][i]][size_[table[ff][i]]] = table[ff][i];
                    m[table[ff][i]] = make_pair(table[ff][i], size_[table[ff][i]]);
                    size_[table[ff][i]]++;
                    size_[ff]--;
                }
            }


            // put "from" to "to"
            table[ff][size_[ff]] = from;
            m[from] = make_pair(ff, size_[ff]);
            size_[ff]++;
            size_[f]--;
        } else {
            int f = m[from].first;
            int s = m[from].second;
            int ff = m[to].first;
            int ss = m[to].second;

            if (ff == f) continue;

            if (op2.compare("onto") == 0) {
                // put everything away from "to"
                for (int i = size_[ff] - 1; i > ss; i--) {
                    table[table[ff][i]][size_[table[ff][i]]] = table[ff][i];
                    m[table[ff][i]] = make_pair(table[ff][i], size_[table[ff][i]]);
                    size_[table[ff][i]]++;
                    size_[ff]--;
                }
            }

            for (int i = s; i < size_[f]; i++) {
                table[ff][size_[ff]] = table[f][i];
                m[table[f][i]] = make_pair(ff, size_[ff]);
                size_[ff]++;
            }
            size_[f] -= (size_[f] - s);
        }

    }
            for (int i = 0; i < n; i++) {
                cout << i << ":";
                for (int j = 0; j < size_[i]; j++) {
                    cout << ' ' << table[i][j];
                }
                cout << endl;
            }
}