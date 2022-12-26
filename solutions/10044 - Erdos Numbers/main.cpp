#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main() {

    int n;

    cin >> n;

    for (int tt = 0; tt < n; tt++) {
        int books, queries;
        string str;

        map<string, set<string>> connections;
        map<string, int> erdos_number;
        map<string, bool> taken;

        queue<pair<string, int>> q;

        cin >> books >> queries;
        getline(cin, str);

        for (int i = 0; i < books; i++) {
            vector<string> authors;

            getline(cin, str);

            int comma_counter = 0;
            int last_comma = 0;
            for (int j = 0; j < str.size(); j++) {
                if (str[j] == ',') comma_counter++;
                if (comma_counter == 2) {
                    comma_counter = 0;
                    authors.push_back(str.substr(last_comma, j - last_comma));
                    last_comma = j + 2;
                }
                if (str[j] == ':') {
                    authors.push_back(str.substr(last_comma, j - last_comma));
                    break;
                }
            }

            for (int j = 0; j < authors.size(); j++) {
                for (int k = j + 1; k < authors.size(); k++) {
                    connections[authors[j]].insert(authors[k]);
                    connections[authors[k]].insert(authors[j]);
                }
            }
        }

        q.push({"Erdos, P.", 0});

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            if (taken[top.f]) continue;
            taken[top.f] = true;
            erdos_number[top.f] = top.s;

            for (auto i : connections[top.f]) {
                if (taken[i]) continue;
                q.push({i, top.s + 1});
            }
        }
    
        cout << "Scenario " << tt + 1 << endl;
        for (int i = 0; i < queries; i++) {
            getline(cin, str);
            cout << str << " ";

            if (str != "Erdos, P." && erdos_number[str] == 0) {
                cout << "infinity\n";
            } else {
                cout << erdos_number[str] << endl;
            }
        }    
    }
} 