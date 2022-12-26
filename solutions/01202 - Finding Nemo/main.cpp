#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

int main() {

    int walls, doors;
    while (cin >> walls >> doors, walls != -1 || doors != -1) {
        int v[200][200];
        int h[200][200];
//        map<pair<pair<int, int>, pair<int, int>>, int> v;
//        map<pair<pair<int, int>, pair<int, int>>, int> h;
        int d[200][200];
        for (int i = 0; i < 200; i++) {
            for (int j = 0; j < 200; j++) {
                v[i][j] = 0;
                h[i][j] = 0;
                d[i][j] = -1000000000;
            }
        }

        int x, y, dir, len;
        for (int i = 0; i < walls; i++) {
            cin >> x >> y >> dir >> len;

            if (dir) {
                for (int j = 1; j <= len; j++) {
                    v[y + j - 1][x] = 1;
                }
            } else {
                for (int j = 1; j <= len; j++) {
                    h[y][x + j - 1] = 1;
                }
            }
        }

        for (int i = 0; i < doors; i++) {
            cin >> x >> y >> dir;
            if (dir) {
                v[y][x] = 2;
            } else {
                h[y][x] = 2;
            }
        }
        

        double nemo_x, nemo_y;
        cin >> nemo_x >> nemo_y;
        int nx, ny;

        nx = floor(nemo_x);
        ny = floor(nemo_y);
        d[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, 0}});
        
        int minimum = INT_MAX;

        while (pq.size()) {
            auto top = pq.top();
            pq.pop();

            int x_, y_, door_;

            //up
            x_ = top.s.f;
            y_ = top.s.s + 1;
            if (y_ == 200) {
                minimum = min(minimum, top.f);
            } else {
                door_ = (top.f - (h[y_][x_] == 2));
                if (door_ > d[y_][x_] && h[y_][x_] != 1) {
                    d[y_][x_] = door_;
                    pq.push({door_, {x_, y_}});
                }
            }
            
            //down
            x_ = top.s.f;
            y_ = top.s.s - 1;
            door_ = (top.f - (h[y_ + 1][x_] == 2));
            if (y_ < 0) {
                minimum = min(minimum, door_);    
            } else if (door_ > d[y_][x_] && h[y_ + 1][x_] != 1) {
                d[y_][x_] = door_;
                pq.push({door_, {x_, y_}});
            }

            //right
            x_ = top.s.f + 1;
            y_ = top.s.s;
            
            if (x_ == 200) {
                minimum = min(top.f, minimum);
            } else {
                door_ = (top.f - (v[y_][x_] == 2));
                if (x_ < 200 && door_ > d[y_][x_] && v[y_][x_] != 1) {
                    //cout << "\tri " << x_ << " " << y_ << " " << door_ << endl;
                    d[y_][x_] = door_;
                    pq.push({door_, {x_, y_}});
                }
            
            }
            
            //left
            x_ = top.s.f - 1;
            y_ = top.s.s;
            door_ = (top.f - (v[y_][x_ + 1] == 2));
            if (x_ < 0) {
                minimum = min(minimum, door_);
            } else if (door_ > d[y_][x_] && v[y_][x_ + 1] != 1) {
                d[y_][x_] = door_;
                pq.push({door_, {x_, y_}});
            }
         
        }
        /*
        for (int i = 10; i >= 0; i--) {
            for (int j = 0; j < 10; j++) {
                cout << d[i][j] << "\t";
            }
            cout << endl;
        }
        */
        if (ny < 0 || ny >= 200 || nx < 0 || nx >= 200) {
            cout << minimum << endl;
        } else if (d[ny][nx] == -1000000000) {
            cout << -1 << endl;
        } else {
            cout << -d[ny][nx] << endl;
        }
        
    }



    return 0;

}