#include <bits/stdc++.h>

using namespace std;

map<char, char> char_to_int;

int main() {

    std::ios_base::sync_with_stdio(false);

    char_to_int['A'] = '2';
    char_to_int['B'] = '2';
    char_to_int['C'] = '2';

    char_to_int['D'] = '3';
    char_to_int['E'] = '3';
    char_to_int['F'] = '3';

    char_to_int['G'] = '4';
    char_to_int['H'] = '4';
    char_to_int['I'] = '4';

    char_to_int['J'] = '5';
    char_to_int['K'] = '5';
    char_to_int['L'] = '5';

    char_to_int['M'] = '6';
    char_to_int['N'] = '6';
    char_to_int['O'] = '6';

    char_to_int['P'] = '7';
    char_to_int['R'] = '7';
    char_to_int['S'] = '7';

    char_to_int['T'] = '8';
    char_to_int['U'] = '8';
    char_to_int['V'] = '8';

    char_to_int['W'] = '9';
    char_to_int['X'] = '9';
    char_to_int['Y'] = '9';

    int test_cases;
    cin >> test_cases;
    
    for (int tc = 0; tc < test_cases; tc++) {
        int num;
        cin >> num;
        vector<pair<string, int>> numbers;
        map<string, int> occ;

        for (int i = 0; i < num; i++) {
            string line;
            cin >> line;

            string res = "";

            for (auto j : line) {
                if (j == '-') continue;
                if (isalpha(j)) {
                    res += char_to_int[toupper(j)];
                    continue;
                }
                res += j;
            }
            occ[res]++;
        }

        for (auto i : occ) {
            if (i.second == 1) continue;
            numbers.push_back({i.first, i.second});
        }

        sort(numbers.begin(), numbers.end());

        if (tc) cout << endl;       
        for (auto i : numbers) {
            cout << i.first.substr(0, 3) << "-" << i.first.substr(3) << " " << i.second << endl;
        }
        if (numbers.size() == 0) cout << "No duplicates." << endl;
    }
}