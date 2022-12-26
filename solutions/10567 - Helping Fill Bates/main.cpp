#include <bits/stdc++.h>

using namespace std;

int toInt(char c) {
    if (isupper(c)) {
        return 26 + c - 'A';
    }
    return c - 'a';
}

int main() {
    
    vector<vector<int>> vvi;
    vvi.resize(52);

    string str;

    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        vvi[toInt(str[i])].push_back(i);
    }
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        string q;
        cin >> q;

        int ind = -1, start = 0;
        bool wrong = false;

        for (int j = 0; j < q.size(); j++) {
            auto low = upper_bound(vvi[toInt(q[j])].begin(), vvi[toInt(q[j])].end(), ind);

            ind = low  - vvi[toInt(q[j])].begin();
            if(low == vvi[toInt(q[j])].end()) wrong = true;

            ind = vvi[toInt(q[j])][ind];
            if(j == 0) start = ind;
        }
 
        if (!wrong) {
            printf("Matched %d %d\n", start, ind);
        } else printf("Not matched\n");
    }
}