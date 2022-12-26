#include <bits/stdc++.h>

using namespace std;

int main() {

    int ready;
    int case_ = 0;
    while (cin >> ready, ready >= 0) {
        int ready_[12];
        int needed[12];
        cout << "Case " << ++case_ << ":" << endl;
        for (int i = 0; i < 12; i++) cin >> ready_[i];
        for (int i = 0; i < 12; i++) cin >> needed[i];

        for (int i = 0; i < 12; i++) {
            if (ready >= needed[i]) {
                cout << "No problem! :D\n";
                ready += ready_[i] - needed[i];
            } else {
                cout << "No problem. :(\n";
                ready += ready_[i];
            }
        }
    }
}