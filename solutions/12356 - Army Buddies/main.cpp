#include <bits/stdc++.h>

using namespace std;

int main() {

    int S, B;

    while (cin >> S >> B, S || B) {

        set<int> s;
        for (int i = 0; i < S; i++) {
            s.insert(i + 1);
        }

        for (int i = 0; i < B; i++) {
            int L, R;
            cin >> L >> R;
    
            s.erase(s.lower_bound(L), ++s.lower_bound(R));
            auto l = s.lower_bound(L);
            auto r = s.lower_bound(R);

            if (l != s.begin()) {
                cout << *(--l) << ' ';
            } else {
                cout << "* ";
            }

            if (r != s.end()) {
                cout << *r << endl;
            } else {
                cout << "*\n";
            }
        }
        cout << "-" << endl;
    }
}