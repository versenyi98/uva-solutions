#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    int tt = 0;

    while (cin >> n) {
        tt++;
        string original[n], created[n];
        char rot90[n][n], rot180[n][n], rot270[n][n], vert_ref[n][n];
        char vert_ref90[n][n], vert_ref180[n][n], vert_ref270[n][n];
        
        for (int i = 0; i < n; i++) {
            cin >> original[i] >> created[i];

        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rot90[j][n - 1 - i] = original[i][j]; 
                rot180[n - 1 - i][n - j - 1] = original[i][j];
                rot270[n - 1 - j][i] = original[i][j];
                vert_ref[n - 1 - i][j] = original[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vert_ref90[j][n - 1 - i] = vert_ref[i][j]; 
                vert_ref180[n - 1 - i][n - j - 1] = vert_ref[i][j];
                vert_ref270[n - 1 - j][i] = vert_ref[i][j];
            }
        }

        bool pr = true;
        bool r90 = true;
        bool r180 = true;
        bool r270 = true;
        bool v = true;
        bool vr90 = true;
        bool vr180 = true;
        bool vr270 = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pr = pr && (created[i][j] == original[i][j]);
                r90 = r90 && (created[i][j] == rot90[i][j]);
                r180 = r180 && (created[i][j] == rot180[i][j]);
                r270 = r270 && (created[i][j] == rot270[i][j]);
                v = v && (created[i][j] == vert_ref[i][j]);
                vr90 = vr90 && (created[i][j] == vert_ref90[i][j]);
                vr180 = vr180 && (created[i][j] == vert_ref180[i][j]);
                vr270 = vr270 && (created[i][j] == vert_ref270[i][j]);
            }
        }

        if (pr) {
            cout << "Pattern " << tt << " was preserved." << endl;
            continue;
        }
        if (r90) {
            cout << "Pattern " << tt << " was rotated 90 degrees." << endl;
            continue;
        }
        if (r180) {
            cout << "Pattern " << tt << " was rotated 180 degrees." << endl;
            continue;
        }

        if (r270) {
            cout << "Pattern " << tt << " was rotated 270 degrees." << endl;
            continue;
        }

        if (v) {
            cout << "Pattern " << tt << " was reflected vertically." << endl;
            continue;
        }

        if (vr90) {
            cout << "Pattern " << tt << " was reflected vertically and rotated 90 degrees." << endl;
            continue;
        }

        if (vr180) {
            cout << "Pattern " << tt << " was reflected vertically and rotated 180 degrees." << endl;
            continue;
        }

        if (vr270) {
            cout << "Pattern " << tt << " was reflected vertically and rotated 270 degrees." << endl;
            continue;
        }
        cout << "Pattern " << tt << " was improperly transformed." << endl;
    }
}