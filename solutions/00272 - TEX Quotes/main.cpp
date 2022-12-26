#include <bits/stdc++.h>

using namespace std;

int main() {

    int counter = 0;
    string line;

    while (getline(cin, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '"') {
                counter++;
                if (counter % 2 == 0) {
                    cout << "''";
                } else {
                    cout << "``";
                }
            } else {
                cout << line[i];
            }
        }
        cout << endl;
    }
}