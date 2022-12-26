#include <bits/stdc++.h>

using namespace std;

int main() {

    int tc;
    string str;
    cin >> tc;
    getline(cin, str);
    getline(cin, str);

    for (int ttt = 0; ttt < tc; ttt++) {
        int A[25][25];
        if (ttt) cout << endl;
        int j = 0;
        int len = 0;
        while (getline(cin, str) && str.length()) {
            for (int i = 0; i < str.length(); i++) {
                A[j][i] = (str[i]  == '1' ? 1 : -20000);

                if (j > 0) A[j][i] += A[j - 1][i];
                if (i > 0) A[j][i] += A[j][i - 1];
                if (i > 0 && j > 0) A[j][i] -= A[j - 1][i - 1];
            }
            len = str.length();
            j++;
        }
        
        int mxx = INT_MIN;
        for (int i = 0; i < len; i++) {
            for (j = 0; j < len; j++) {
                for (int k = i; k < len; k++) {
                    for (int l = j; l < len; l++) {
                        int mx = A[k][l];

                        if (i > 0) mx -= A[i - 1][l];
                        if (j > 0) mx -= A[k][j - 1];
                        if (i > 0 && j > 0) mx += A[i - 1][j - 1];
                        mxx = max(mx, mxx);
                    }
                }
            }
        }
        cout << max(0, mxx) << endl;
    }
}