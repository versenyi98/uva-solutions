#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    for (int tt = 0; tt < test_cases; tt++) {

        bool solved[3][10001];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 10001; j++) {
                solved[i][j] = false;
            }
        }

        vector<int> someone_solved;
        for (int i = 0; i < 3; i++) {
            int num;
            cin >> num;

            for (int j = 0; j < num; j++) {
                int solve_id;
                cin >> solve_id;
                solved[i][solve_id] = true;

                someone_solved.push_back(solve_id);
            }
        }

        sort(someone_solved.begin(), someone_solved.end());
        auto it = unique(someone_solved.begin(), someone_solved.end()); 
        someone_solved.resize(distance(someone_solved.begin(),it));

        vector<int> unique_solve[3];

        for (auto i : someone_solved) {
            bool one_solved = false;
            int who_was_it = -1;

            for (int j = 0; j < 3; j++) {
                if (solved[j][i]) {
                    if (one_solved) {
                        one_solved = false;
                        break;
                    } else {
                        one_solved = true;
                        who_was_it = j;
                    }
                }
            }

            if (one_solved) {
                unique_solve[who_was_it].push_back(i);
            }
        }
        int max_size = INT_MIN;
        for (int i = 0; i < 3; i++) max_size = max(max_size, (int) unique_solve[i].size());

        cout << "Case #" << tt + 1 << ":\n";
        for (int i = 0; i < 3; i++) {
            if (unique_solve[i].size() == max_size) {
                cout << i + 1 << ' ' << max_size;
                for (auto j : unique_solve[i]) {
                    cout << ' ' << j;
                }
                cout << endl;
            }
        }

    }



}