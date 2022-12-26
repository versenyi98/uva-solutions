#include <bits/stdc++.h>

using namespace std;

map<string, bool> taken;
map<string, bool> possible;

bool dp(string str) {

    if (str == "") return true;

    char save = str[0];
    int consec = 1;
    int begin = 0;
    
    if (taken[str]) return possible[str];
    taken[str] = true;

    for (int i = 1; i <= str.length(); i++) {
        if (i < str.length() && str[i] == save) {
            consec++;
        } else {

            if (consec >= 2) {
                for (int j = 2; j <= consec; j++) {
                    possible[str] = possible[str] || dp(str.substr(0, begin) + str.substr(begin + j));
                    if (possible[str]) return possible[str];
                }
            }

            begin = i;
            save = str[i];
            consec = 1;
        }
    }

    return false;
}

int main() {
    int n; cin >> n;
    string str;
    while (n--) {
        cin >> str;
        cout << dp(str) << endl;
    }
}