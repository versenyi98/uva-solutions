#include <bits/stdc++.h>

using namespace std;

int w[20];
int sum;
int sz;

bool possible (int i = 0, int v = 0) {

    if (i == sz) {
        return v * 2 == sum;
    }

    return possible(i + 1, v) || possible(i + 1, v + w[i]);
}

int main() {
    int tt;
    cin >> tt;

    string str;
    getline(cin, str);

    for (int ttt = 0; ttt < tt; ttt++) {
        getline(cin, str);

        sz = 0;
        sum = 0;
        while (str.find(' ') != string::npos) {
            w[sz++] = stoi(str.substr(0, str.find(' ')));
            str = str.substr(str.find(' ') + 1);
            sum += w[sz - 1];
        }
        w[sz++] = stoi(str);
        sum += w[sz - 1];

        cout << (possible() ? "YES\n" : "NO\n");
    }
}