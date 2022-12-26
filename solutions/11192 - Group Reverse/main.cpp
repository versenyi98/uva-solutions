#include <bits/stdc++.h>

using namespace std;

int main() {

    int G;
    while (cin >> G, G) {
        string word;
        cin >> word;

        for (int i = 0; i < G; i++) {
            reverse(word.begin() + i * (word.length() / G), word.begin() + (i + 1) * (word.length() / G));
        }
        cout << word << endl;
    }
}