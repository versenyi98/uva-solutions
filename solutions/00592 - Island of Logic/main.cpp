#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    int test_cases = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    map<string, int> mm;
    map<int, string> mmm;
    mmm[0] = "divine";
    mmm[1] = "evil";
    mmm[2] = "human";
    mm["day"] = 0;
    mm["night"] = 1;

    mm["divine"] = 0;
    mm["evil"] = 1;
    mm["human"] = 2;

    while (cin >> n, n) {

        cout << "Conversation #" << ++test_cases << endl;

        vector<vector<string>> statements;

        for (int i = 0; i < n; i++) {
            string a, b, c, d, e = "";
            cin >> a >> b >> c >> d;
            if (d == "not") {
                cin >> e;
            } else {
                e = d;
                d = "";
            }
            e = e.substr(0, e.length() - 1);
            statements.push_back({a, b, c, d, e});
        }
        vector<vector<int>> goodies;

        for (int A = 0; A < 3; A++) {
            for (int B = 0; B < 3; B++) {
                for (int C = 0; C < 3; C++) {
                    for (int D = 0; D < 3; D++) {
                        for (int E = 0; E < 3; E++) {
                            for (int w = 0; w < 2; w++) {
                                vector<int> states = {A, B, C, D, E, w};
                                bool valid = true;
                                for (int i = 0; i < statements.size(); i++) {
                                    int person = statements[i][0][0] - 'A';

                                    if (statements[i][1] == "I") {
                                        if (statements[i][3] == "not") {
                                            if (statements[i][4] == "lying") {
                                                valid = true;
                                                continue;
                                            }
                                            valid = (statements[i][4] != "divine" && states[person] == 0) || (statements[i][4] == "evil" && states[person] == 1) || (states[person] == 2 && ((w == 0 && statements[i][4] != "human") || (w == 1 && statements[i][4] == "human"))) || statements[i][4] == "lying";
                                        } else {
                                            if (statements[i][4] == "lying") {
                                                valid = false;
                                                break;
                                            }
                                            valid = (statements[i][4] == "divine" && states[person] == 0) || (statements[i][4] != "evil" && states[person] == 1) || (states[person] == 2 && ((w == 0 && statements[i][4] == "human") || (w == 1 && statements[i][4] != "human")));
                                        }
                                    } else if (statements[i][1] == "It") {
                                        valid = (states[person] == 0 && mm[statements[i][4]] == w) || (states[person] == 1 && mm[statements[i][4]] != w) || (states[person] == 2 && mm[statements[i][4]] == 0);
                                    } else {
                                        int other = statements[i][1][0] - 'A';
                                        if (statements[i][3] != "not") {
                                            if (statements[i][4] == "lying") {
                                                valid = ((states[person] == 0 || states[person] == 2 && w == 0) && (states[other] == 1 || (states[other] == 2 && w == 1))) || ((states[person] == 1 || states[person] == 2 && w == 1) && (states[other] == 0 || (states[other] == 2 && w == 0)));
                                            } else {
                                                valid = ((states[person] == 0 || states[person] == 2 && w == 0) && states[other] == mm[statements[i][4]]) || ((states[person] == 1 || (states[person] == 2 && w == 1)) && states[other] != mm[statements[i][4]]);
                                            }
                                        } else {
                                            if (statements[i][4] == "lying") {
                                                valid = ((states[person] == 0 || states[person] == 2 && w == 0) && (states[other] != 1 && (states[other] != 2 || w != 1))) || ((states[person] == 1 || states[person] == 2 && w == 1) && (states[other] != 0 && (states[other] != 2 || w != 0)));
                                            } else {
                                                valid = ((states[person] == 0 || states[person] == 2 && w == 0) && states[other] != mm[statements[i][4]]) || ((states[person] == 1 || (states[person] == 2 && w == 1)) && states[other] == mm[statements[i][4]]);
                                            }
                                        }
                                    }

                                    if (!valid) break;
                                }

                                if (valid) {
                                    goodies.push_back(states);
                                }
                            }
                        }
                    }
                }
            }
        }

        if (goodies.size() == 0) {
            cout << "This is impossible." << endl << endl;
            continue;
        }

        int cc = 0;
        for (int i = 0; i < 6; i++) {
            int val = goodies[0][i];
            bool good = true;
            for (int j = 1; j < goodies.size(); j++) {
                good = goodies[j][i] == val;
                if (!good) break;
            }

            if (good) {
                cc++;
                if (i == 5) {
                    cout << "It is " << (val == 1 ? "night" : "day") << "." << endl;
                } else {
                    cout << (char)('A' + i) << " is " << mmm[val] << "." << endl;
                }
            }
        }

        if (cc == 0) {
            cout << "No facts are deducible." << endl;
        }
        cout << endl;
    }

    return 0;
}