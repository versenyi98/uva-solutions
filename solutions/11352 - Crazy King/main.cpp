#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

struct triplet_ {
    int ff;
    int ss;
    int tt;
};

// A* gives wrong answer -> BFS used
int countHeur(pair<int, int> a, triplet_ b) {
    return -(abs(a.f - b.ff) + abs(a.s - b.ss) + b.tt);
}

int main() {

    int tc;
    cin >> tc;

    while (tc--) {

        int rows, cols;
        map<pair<int, int>, bool> taken;
        pair<int, int> A, B;
        queue<pair<int, triplet_>> pq;

        cin >> rows >> cols;

        int knight_x[] = {-2, -1, -2, -1, +2, +1, +2, +1};
        int knight_y[] = {-1, -2, +1, +2, +1, +2, -1, -2};
        
        string table[100];

        for (int i = 0; i < rows; i++) {
            cin >> table[i];

            if (table[i].find('A') != string::npos) A = {i, table[i].find('A')};
            if (table[i].find('B') != string::npos) B = {i, table[i].find('B')};
            for (int j = 0; j < table[i].size(); j++) {
                if (table[i][j] != 'Z') continue;
                
                for (int k = 0; k < 8; k++) {
                    taken[{i + knight_x[k], j + knight_y[k]}] = true;
                }
                taken[{i, j}] = true;
            }
        }

        triplet_ AA;

        AA.ff = A.f;
        AA.ss = A.s;
        AA.tt = 0;

        taken[A] = false;
        taken[B] = false;

        pq.push({0, AA});

        while (!pq.empty() && (pq.front().s.ff != B.f || pq.front().s.ss != B.s)) {
            auto top = pq.front();
            pq.pop();

            if (taken[{top.s.ff, top.s.ss}]) continue;
            if (top.s.ff < 0 || top.s.ss >= cols || top.s.ss < 0 || top.s.ff >= rows) continue;
            taken[{top.s.ff, top.s.ss}] = true;

            top.s.tt++;

            top.s.ff++;
            pq.push({countHeur(B, top.s), top.s});

            top.s.ss++;
            pq.push({countHeur(B, top.s), top.s});

            top.s.ss-=2;
            pq.push({countHeur(B, top.s), top.s});

            top.s.ff--;
            pq.push({countHeur(B, top.s), top.s});
            
            top.s.ss+=2;
            pq.push({countHeur(B, top.s), top.s});

            top.s.ff--;
            pq.push({countHeur(B, top.s), top.s});

            top.s.ss--;
            pq.push({countHeur(B, top.s), top.s});

            top.s.ss--;
            pq.push({countHeur(B, top.s), top.s});
        }

        if (pq.empty()) {
            cout << "King Peter, you can't go now!\n";
        } else {
            cout << "Minimal possible length of a trip is " << pq.front().s.tt << endl;
        }
    }
}