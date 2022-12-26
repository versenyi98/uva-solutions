#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

struct footballer {
    string name;
    int att, def;

    bool operator< (const footballer& f) const {
        return name < f.name;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    for (int t = 0; t < test_cases; t++) {
        vector<footballer> footballers;

        for (int i = 0; i < 10; i++) {
            footballer f;
            cin >> f.name >> f.att >> f.def;
            footballers.push_back(f);
        }

        sort(footballers.begin(), footballers.end());

        vector<int> best_a = {0, 0, 0, 0, 0};
        vector<int> best_d = {0, 0, 0, 0, 0};
        int best_att = INT_MIN;
        int best_def = INT_MIN;

        for (int i = 0; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) {
                for (int k = j + 1; k < 10; k++) {
                    for (int l = k + 1; l < 10; l++) {
                        for (int m = l + 1; m < 10; m++) {
                            vector<int> current = {i, j, k, l, m};
                            vector<int> comp;
                            for (int c = 0; c < 10; c++) {
                                if (find(current.begin(), current.end(), c) == current.end()) {
                                    comp.push_back(c);
                                }
                            }

                            int curr_att = 0;
                            int curr_def = 0;

                            for (int o = 0; o < 5; o++) {
                                curr_att += footballers[current[o]].att;
                                curr_def += footballers[comp[o]].def;
                            }

                            if (curr_att > best_att || (curr_att == best_att && curr_def > best_def)) {
                                best_att = curr_att;
                                best_def = curr_def;
                                best_a = current;
                                best_d = comp;
                            }
                        }
                    }
                }
            }
        }
        cout << "Case " << t + 1 << ":" << endl;
        cout << "(";
        for (int i = 0; i < 5; i++) {
            if (i) cout << ", ";
            cout << footballers[best_a[i]].name;
        }
        cout << ")" << endl << "(" ;
        for (int i = 0; i < 5; i++) {
            if (i) cout << ", ";
            cout << footballers[best_d[i]].name;
        }
        cout << ")" << endl;
    }

    return 0;
}