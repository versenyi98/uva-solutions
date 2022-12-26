#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

const string goal = "111110111100 110000100000";
int moves[] = {-11, -7, -9, -3, +3, +9, +7, +11};

int count(string str) {
    int counter = 0;

    for (int i = 0; i < 25; i++) {
        if (str[i] == goal[i]) {
            counter++;
        }
    }

    return counter;
}

int main() {
    int n;

    cin >> n;
    string str;
    getline(cin, str);
    for (int nn = 0; nn < n; nn++) {
        
        map<string, bool> taken;
        queue<pair<string, int>> q;

        string state = "";

        for (int i = 0; i < 5; i++) {
            getline(cin, str);
            state += str;
        }

        q.push({state, 0});

        while (!q.empty() && q.front().f != goal) {
            auto top = q.front();
            q.pop();

            if (count(top.f) + 11 - top.s < 25) continue;
            if (taken[top.f]) continue;

            for (int i = 0; i < 8; i++) {
                string next_state = top.f;
                int pos = top.f.find(' ');

                if (pos + moves[i] < 0 || pos + moves[i] >= 25) continue;

                next_state[pos] = next_state[pos + moves[i]];
                next_state[pos + moves[i]] = ' ';

                if (taken[next_state]) continue;
                q.push({next_state, top.s + 1});
            }
        }
        if (q.empty()) {
            cout << "Unsolvable in less than 11 move(s)." << endl;
        } else {
            cout << "Solvable in " << q.front().s << " move(s)." << endl;
        }
    }    
}