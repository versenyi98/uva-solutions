#include <bits/stdc++.h>

using namespace std;

int main() {

    string line;
    map<char, int> char_to_int;

    char_to_int['A'] = 0;
    char_to_int['B'] = 1;
    char_to_int['C'] = 2;
    char_to_int['D'] = 3;
    char_to_int['E'] = 0;
    char_to_int['F'] = 1;
    char_to_int['G'] = 2;
    char_to_int['H'] = 0;
    char_to_int['I'] = 0;
    char_to_int['J'] = 2;
    char_to_int['K'] = 2;
    char_to_int['L'] = 4;
    char_to_int['M'] = 5;
    char_to_int['N'] = 5;
    char_to_int['O'] = 0;
    char_to_int['P'] = 1;
    char_to_int['Q'] = 2;
    char_to_int['R'] = 6;
    char_to_int['S'] = 2;
    char_to_int['T'] = 3;
    char_to_int['U'] = 0;
    char_to_int['V'] = 1;
    char_to_int['W'] = 0;
    char_to_int['X'] = 2;
    char_to_int['Y'] = 0;
    char_to_int['Z'] = 2;
    
    while (cin >> line) {
        int last = -1;
        for (auto i : line) {
            if (char_to_int[i] && char_to_int[i] != last) {
                cout << char_to_int[i];
                last = char_to_int[i];
            }

            if (!char_to_int[i]) {
                last = char_to_int[i];
            }
        }
        cout << endl;
    }
}