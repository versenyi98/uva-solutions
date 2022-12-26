#include <bits/stdc++.h> 

// R ed
// G reen
// B lue
// E mpty

using namespace std;

char table[10][15];

void rearrange() {

    for (int i = 0; i < 15; i++) {
        for (int j = 9; j >= 0; j--) {
            if (table[j][i] == 'E') {
                for (int jj = j; jj >= 0; jj--) {
                    if (table[jj][i] != 'E') {
                        table[j][i] = table[jj][i];
                        table[jj][i] = 'E';
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 15; i++) {
        int empty_counter = 0;
        for (int j = 0; j < 10; j++) {
            if (table[j][i] == 'E') {
                empty_counter++;
            }
        }

        if (empty_counter == 10) {
            bool is_empty = true;
            for (int ii = i + 1; ii < 15; ii++) {
                for (int jj = 0; jj < 10; jj++) {
                    if (table[jj][ii] != 'E') {
                        is_empty = false;
                        break;
                    }
                }

                if (!is_empty) {
                    for (int jj = 0; jj < 10; jj++) {
                        swap(table[jj][i], table[jj][ii]);
                    }
                    break;
                }
            }
        }
    }
}

int main() {

    int test_cases;
    cin >> test_cases;
    int maximum, row, column;
    for (int tt = 0; tt < test_cases; tt++) {
        if (tt) cout << endl;
        printf("Game %d:\n\n", tt + 1);

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 15; j++) {
                cin >> table[i][j];
            }
        }

        int move_counter = 1;
        int final_balls = 150;
        int points = 0;
        do {
            maximum = INT_MIN;
            row = INT_MAX;
            column = INT_MAX;

            bool visited[10][15];

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 15; j++) {
                    visited[i][j] = false;
                }
            }

            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 15; j++) {
                    if (visited[i][j] == false && table[i][j] != 'E') {
                        char ball = table[i][j];
                        int bot_most = (10 - i);
                        int lef_most = j;
                        int counter = 0;

                        queue<pair<int, int>> q;
                        q.push({i, j});

                        while (q.size()) {
                            auto front = q.front();
                            q.pop();

                            int f = front.first;
                            int s = front.second;

                            if (f < 0 || f >= 10 || s < 0 || s >= 15 || visited[f][s] || table[f][s] != ball) continue;
                            counter++;
                            visited[f][s] = true;
                            if (s < lef_most || (s == lef_most && (10 - f) < bot_most)) {
                                lef_most = s;
                                bot_most = (10 - f);
                            }

                            q.push({f + 1, s});
                            q.push({f - 1, s});
                            q.push({f, s + 1});
                            q.push({f, s - 1});
                        }
                        if (counter > maximum || (counter == maximum && (lef_most < column || (lef_most == column && bot_most < row)))) {
                            maximum = counter;
                            column = lef_most;
                            row = bot_most;
                        }

                    }
                }

            }
            if (maximum < 2) break;

            char removed = table[(10 - row)][column];
            final_balls -= maximum;
            points += (maximum - 2) * (maximum - 2);

            queue<pair<int, int>> q;
            q.push({10 - row, column});
            while (q.size()) {
                auto front = q.front();
                q.pop();

                int f = front.first;
                int s = front.second;

                if (f < 0 || f >= 10 || s < 0 || s >= 15 || table[f][s] != removed) continue;
                table[f][s] = 'E';

                q.push({f + 1, s});
                q.push({f - 1, s});
                q.push({f, s + 1});
                q.push({f, s - 1});
            }
            rearrange();
            printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", move_counter++, row, column + 1, maximum, removed, (maximum - 2) * (maximum - 2));

        } while (true);
        if (final_balls == 0) points += 1000;
        printf("Final score: %d, with %d balls remaining.\n", points, final_balls);
    }
    return 0;
}