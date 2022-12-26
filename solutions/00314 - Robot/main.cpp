#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int main() {

    int N, M;
    
    map<pair<string, string>, string> turn;

    turn[{"north", "l"}] = "west";
    turn[{"north", "r"}] = "east";

    turn[{"south", "l"}] = "east";
    turn[{"south", "r"}] = "west";

    turn[{"east", "l"}] = "north";
    turn[{"east", "r"}] = "south";

    turn[{"west", "l"}] = "south";
    turn[{"west", "r"}] = "north";

    while (cin >> N >> M, N || M) {
        map<pair<string, pair<int, int>>, bool> taken;
        queue<pair<pair<string, pair<int, int>>, int>> q;
        pair<int, int> starting_position;
        pair<int, int> ending_position;
        string orientation;

        int grid[50][50];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> grid[i][j];
            }
        }

        int x, y;
        cin >> y >> x;
        starting_position = {x, y};

        cin >> y >> x;
        ending_position = {x, y};

        cin >> orientation;

        q.push({{orientation, starting_position}, 0});

        while (!q.empty() && q.front().f.s != ending_position) {
            auto top = q.front();
            q.pop();

            if (taken[top.f]) continue;
            taken[top.f] = true;
            //cout << top.f.f << " " << top.f.s.f << " " << top.f.s.s << " " << top.s << endl;

            // turn left
            if (!taken[{turn[{top.f.f, "l"}], top.f.s}]) {
                q.push({{turn[{top.f.f, "l"}], top.f.s}, top.s + 1});
            }
            // turn right 
            if (!taken[{turn[{top.f.f, "r"}], top.f.s}]) {
                q.push({{turn[{top.f.f, "r"}], top.f.s}, top.s + 1});
            }
            // forward 1 2 3
            for (int i = 1; i <= 3; i++) {
                int posx = top.f.s.f;
                int posy = top.f.s.s;

                if (top.f.f == "north") {
                    posy -= i;
                } else if (top.f.f == "south") {
                    posy += i;
                } else if (top.f.f == "east") {
                    posx += i;
                } else if (top.f.f == "west") {
                    posx -= i;
                }

                if (posy >= N || posy <= 0) break;
                if (posx >= M || posx <= 0) break;              
                
                if (grid[posy - 1][posx - 1]) break;
                if (grid[posy - 1][posx    ]) break;
                if (grid[posy    ][posx - 1]) break;
                if (grid[posy    ][posx    ]) break;
                q.push({{top.f.f, {posx, posy}}, top.s + 1});
            }
        }

        if (q.empty()) {
            cout << -1 << endl;
        } else {
            cout << q.front().s << endl;
        }
    }
}