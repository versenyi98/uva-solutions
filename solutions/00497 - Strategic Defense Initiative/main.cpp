#include <bits/stdc++.h>

using namespace std;

int main() {

    string line;
    int tc;
    cin >> tc;
    cin.ignore();
    cin.ignore();

    for (int tt = 0; tt < tc; tt++) {
        vector<int> numbers;

        while (getline(cin, line) && line != "") {
            int number;
            stringstream ss(line);
            ss >> number;
            numbers.push_back(number);
        }
        vector<int> lis(numbers.size(), 1);
        vector<int> next_index(numbers.size(), -1);

        int mx = INT_MIN, mx_pos = 0;

        for (int i = numbers.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[j] > numbers[i]) {
                    if (lis[j] + 1 > lis[i]) {
                        next_index[i] = j;
                        lis[i] = lis[j] + 1;
                    }
                }
            }
            if (lis[i] > mx) {
                mx = lis[i];
                mx_pos = i;
            }
        }
        if (tt) cout << endl;
        cout << "Max hits: " << mx << endl;
        while (true) {
            cout << numbers[mx_pos] << endl;
            mx_pos = next_index[mx_pos];
            if (mx_pos == -1) break;
        }
    }
    return 0;
}