#include <bits/stdc++.h>

using namespace std;

vector<long long> pos;
string str = "";

void gen() {

    long long count = 0;
    long long ccount = 0;
    long long curr = 1;

    while (count < 2147483647) {
        str += to_string(curr);
        ccount += log10(curr) + 1;
        curr++;
        count += ccount;

        pos.push_back(count);
    }
}


int main() {
    int tc;
    cin >> tc;
    gen();
    
    long long t;
    while (cin >> t) {
        auto it = lower_bound(pos.begin(), pos.end(), t) - 1;
        if (it < pos.begin()) {
            cout << str[t - 1] << endl;
        } else {
            cout << str[t - *it - 1] << endl;
        }
    }
}