#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second;

struct trip {
    int ff, ss, tt;
};

int main() {

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {

        int rows, cols;
        int fire[1000][1000];

        trip J, F;
        string maze[1000];

        queue<trip> fire_q;
        queue<trip> joe_q;

        cin >> rows >> cols;

        for (int i  = 0; i < rows; i++) {
            cin >> maze[i];
            for (int j = 0; j < cols; j++) {
                fire[i][j] = -1;
                if (maze[i][j] == 'J') {
                    J.ff = i;
                    J.ss = j;
                    J.tt = 0;

                    joe_q.push(J);
                } else if (maze[i][j] == 'F') {
                    F.ff = i;
                    F.ss = j;
                    F.tt = 0;

                    fire_q.push(F);
                }
            }
        }

        while (!fire_q.empty()) {
            trip top = fire_q.front();
            fire_q.pop();

            if (top.ff < 0 || top.ff >= rows || top.ss < 0 || top.ss >= cols || fire[top.ff][top.ss] != -1 || maze[top.ff][top.ss] == '#') continue;

            fire[top.ff][top.ss] = top.tt;

            top.tt++;

            top.ss++;
            fire_q.push(top);

            top.ss-=2;
            fire_q.push(top);

            top.ss++;
            top.ff++;
            fire_q.push(top);

            top.ff-=2;
            fire_q.push(top);
        }

        while (!joe_q.empty()) {
            trip top = joe_q.front();
            //cout << top.ff << " " << top.ss << " " << top.tt << endl;
            //cout << rows << " " << cols << endl;
            if (top.ff < 0 || top.ff >= rows || top.ss < 0 || top.ss >= cols) break;

            if (maze[top.ff][top.ss] == '#' || (fire[top.ff][top.ss] <= top.tt && fire[top.ff][top.ss] != -1)) {
                joe_q.pop();
                continue;
            }

            joe_q.pop();

            fire[top.ff][top.ss] = top.tt;

            top.tt++;

            top.ss++;
            joe_q.push(top);

            top.ss-=2;
            joe_q.push(top);

            top.ss++;
            top.ff++;
            joe_q.push(top);

            top.ff-=2;
            joe_q.push(top);
        }
        
        if (joe_q.empty()) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << joe_q.front().tt << endl;
        }
    }
}