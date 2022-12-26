#include <bits/stdc++.h>

using namespace std;

int main() {

    double N, L, W;

    while (cin >> N >> L >> W) {

        vector<pair<double, double>> sprinklers;
        double p, r;
        for (int i = 0; i < N; i++) {
            cin >> p >> r;
            if (r >= W/2) sprinklers.push_back({p - sqrt(pow(r, 2) - pow(W/2, 2)), p + sqrt(pow(r, 2) - pow(W/2, 2))});
        }

        sort(sprinklers.begin(), sprinklers.end());

        double current_left = 0;
        double current_right = 0;

        int i = 0;
        int counter = 0;

        //for (auto i : sprinklers) {
        //    cout << i.first << " " << i.second << endl;
        //}

        while (i < sprinklers.size() && current_right <= L) {
            bool good = false;
            while (i < sprinklers.size() && sprinklers[i].first <= current_left) {
                current_right = max(current_right, sprinklers[i].second);
                i++;
                good = true;
            }
            
            if (!good) {
                counter = -1;
                break;
            }

            counter++;
            current_left = current_right;
        }
        if (current_right < L) {
            counter = -1;
        }
        cout << counter << endl;
    }
}