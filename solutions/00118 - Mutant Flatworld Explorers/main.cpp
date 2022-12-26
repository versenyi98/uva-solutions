#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> coordinate;

map<char, int> direction;
map<int, char> direction_r;

map<int, pair<int, int>> on_forward;
map<char, int> turn;

map<coordinate, bool> has_token;

int max_x, max_y;
coordinate current_coord;
int current_orientation;

#define f first
#define s second

int step() {
    coordinate next_coord = current_coord;
    next_coord = {current_coord.first + on_forward[current_orientation].first,
            current_coord.second + on_forward[current_orientation].second};

    if (next_coord.f < 0 || next_coord.f > max_x || next_coord.s < 0 || next_coord.s > max_y) {
        if (has_token[current_coord]) return 0;
        has_token[current_coord] = true;

        cout << current_coord.f << " " << current_coord.s << " " << direction_r[current_orientation] << " LOST" << endl;
        return -1;
    }

    current_coord = next_coord;
    return 0;
}

int main() {

    direction['N'] = 0;
    direction['E'] = 1;
    direction['S'] = 2;
    direction['W'] = 3;

    direction_r[0] = 'N';
    direction_r[1] = 'E';
    direction_r[2] = 'S';
    direction_r[3] = 'W';

    on_forward[0] = {0, 1};
    on_forward[1] = {1, 0};
    on_forward[2] = {0, -1};
    on_forward[3] = {-1, 0};

    turn['L'] = 3;
    turn['R'] = 1;

    cin >> max_x >> max_y;

    int x, y;
    char o;
    while (cin >> x >> y >> o) {
        current_coord = {x, y};
        current_orientation = direction[o];

        string str;
        cin >> str;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'F') {
                int st = step();
                
                if (st == -1) break;
                if (i == str.length() - 1) {
                    cout << current_coord.f << " " << current_coord.s << " " << direction_r[current_orientation] << endl;
                }
            } else {
                current_orientation = (current_orientation + turn[str[i]]) % 4;
                if (i == str.length() - 1) {
                    cout << current_coord.f << " " << current_coord.s << " " << direction_r[current_orientation] << endl;
                }
                continue;
            }

            
        }
    }

}