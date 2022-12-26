#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    while (true) {

        map<int, int> correct_order;
        vector<int> correct_dp;
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            correct_order[num] = i + 1;
        }

        for (int i = 1; i <= n; i++) {
            correct_dp.push_back(correct_order[i]);
        }

        string line;
        getline(cin, line);
        while (getline(cin, line)) {
            
            if (line.find(' ') == string::npos) break;

            vector<int> values;
            vector<int> actual_values;
            vector<int> points;

            for (int i = 0; i < n - 1; i++) {
                values.push_back(stoi(line.substr(0, line.find(' '))));
                points.push_back(1 );
                line = line.substr(line.find(' ') + 1);
            }
            values.push_back(stoi(line));
            points.push_back(1);

            actual_values.resize(values.size(), 0);
            for (int i = 0; i < values.size(); i++) {
                actual_values[values[i] - 1] = i + 1;
            }

            int dp[21][21];
            for (int i = 0; i <= actual_values.size(); i++) {
                dp[i][0] = 0;
                dp[0][i] = 0;
            }

            // longest common subsequence dp
            for (int i = 1; i <= actual_values.size(); i++) {
                for (int j = 1; j <= actual_values.size(); j++) {
                    if (actual_values[i - 1] == correct_dp[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }

            cout << dp[actual_values.size()][actual_values.size()] << endl;
        }

        if (line.length()) {
            n = stoi(line);
        } else {
            break;
        }
    }
}