#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;
    
    for (int tc = 0; tc < test_cases; tc++) {
        
        int N, K;
        cin >> N >> K;

        bool good[N];
        for (int i = 0; i < N; i++) {
            good[i] = false;
        }

        for (int i = 0; i < K; i++) {
            int num;
            cin >> num;
            int l[num], r[num];
            char op;

            for (int j = 0; j < num; j++) cin >> l[j];
            for (int j = 0; j < num; j++) cin >> r[j];
            cin >> op;

            if (op == '=') {
                for (int j = 0; j < num; j++) {
                    good[l[j] - 1] = true;
                    good[r[j] - 1] = true;
                }
            }
        }

        int sol = -1;

        for (int i = 0; i < N; i++) {
            if (!good[i] && sol == -1) {
                sol = i;
                continue;
            }

            if (!good[i] && sol != -1) {
                sol = -1;
                break;
            }
        }
        if (tc) cout << endl;
        cout << sol + 1 << endl;
    }
}