#include <bits/stdc++.h>

using namespace std;

void print_shape(vector<pair<int, int>> a) {
    for (auto j : a) {
        cout << "{" << j.first << ", " << j.second << "} ";
    }
    cout << endl;
}

void print_shapes(vector<vector<pair<int, int>>> a) {
    for (auto i : a) {
        print_shape(i);
    }
    cout << endl;
}

bool do_I_wanna_know(vector<vector<pair<int, int>>>& a, vector<vector<pair<int, int>>>& b) {

    bool found[b.size()];

    for (int i = 0; i < b.size(); i++) {
        found[i] = false;
    }

    for (int sh = 0; sh < a.size(); sh++) {
        bool found_for_this_shape = false;
        vector<pair<int, int>> shape, para_shape;

        for (auto i : a[sh]) {
            shape.push_back(i);
            para_shape.push_back({i.first, i.second * - 1});
        } 

        //print_shape(shape);

        for (int i = 0; !found_for_this_shape && i < 4; i++) {
            for (int j = 0; j < shape.size(); j++) {
                int f = shape[j].second;
                int s = shape[j].first * -1;

                int fp = para_shape[j].second;
                int sp = para_shape[j].first * -1;

                shape[j] = {f, s};
                para_shape[j] = {fp, sp};
            }

            sort(shape.begin(), shape.end());
//            print_shape(shape);
            sort(para_shape.begin(), para_shape.end());
//            print_shape(para_shape);

            for (int j = 0; !found_for_this_shape && j < b.size(); j++) {
                if (found[j]) continue;
                if (b[j].size() != shape.size()) continue;

                pair<int, int> diff = {b[j][0].first - shape[0].first, b[j][0].second - shape[0].second};
                pair<int, int> piff = {b[j][0].first - para_shape[0].first, b[j][0].second - para_shape[0].second};

                int cs = 0, cp = 0;

                for (int k = 0; k < shape.size(); k++) {
                    if (b[j][k].first - shape[k].first == diff.first &&  b[j][k].second - shape[k].second == diff.second) {
                        cs++;
                    }

                    if (b[j][k].first - para_shape[k].first == piff.first &&  b[j][k].second - para_shape[k].second == piff.second) {
                        cp++;
                    }
                }

                if (cp == shape.size() || cs == shape.size()) {
                    found[j] = true;
                    found_for_this_shape = true;
                }
            }
        }
    }

    for (int i = 0; i < b.size(); i++) {
        if (!found[i]) return false;
    }

    return true;
}

int main() {

    int test_cases;
    cin >> test_cases;

    for (int tt = 0; tt < test_cases; tt++) {
        int n, m, p;
        cin >> n >> m >> p;

        int table_a[n][m];
        int table_b[n][m];
        vector<vector<pair<int, int>>> a_shapes, b_shapes;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                table_a[i][j] = 0;
                table_b[i][j] = 0;
            }
        }

        for (int i = 0; i < p; i++) {
            int x, y;
            cin >> x >> y;

            table_a[x][y] = 1;
        }

        for (int i = 0; i < p; i++) {
            int x, y;
            cin >> x >> y;

            table_b[x][y] = 1;
        }
       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (table_a[i][j] == 1) {
                    vector<pair<int, int>> shapes;
                    int origin_i = i;
                    int origin_j = j;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (q.size()) {
                        auto ff = q.front();
                        q.pop();
                        int f = ff.first;
                        int s = ff.second;

                        if (f < 0 || f == n || s < 0 || s == m || table_a[f][s] == 0) continue;
                        table_a[f][s] = 0;
                        shapes.push_back({f - origin_i, s - origin_j});

                        q.push({f + 1, s});
                        q.push({f, s + 1});
                        q.push({f, s - 1});
                        q.push({f - 1, s});
                    }
                    a_shapes.push_back(shapes);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (table_b[i][j] == 1) {
                    vector<pair<int, int>> shapes;
                    int origin_i = i;
                    int origin_j = j;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (q.size()) {
                        auto ff = q.front();
                        q.pop();
                        int f = ff.first;
                        int s = ff.second;

                        if (f < 0 || f == n || s < 0 || s == m || table_b[f][s] == 0) continue;
                        table_b[f][s] = 0;
                        shapes.push_back({f - origin_i, s - origin_j});

                        q.push({f + 1, s});
                        q.push({f, s + 1});
                        q.push({f, s - 1});
                        q.push({f - 1, s});
                    }
                    b_shapes.push_back(shapes);
                }
            }
        }

        sort(a_shapes.begin(), a_shapes.end(), [](vector<pair<int, int>> a, vector<pair<int, int>> b) {
            return a.size() < b.size();
        });
        
        sort(b_shapes.begin(), b_shapes.end(), [](vector<pair<int, int>> a, vector<pair<int, int>> b) {
            return a.size() < b.size();
        });
       
        for (int i = 0; i < b_shapes.size(); i++) {
            sort(b_shapes[i].begin(), b_shapes[i].end());
        }

        //print_shapes(b_shapes);

        if (do_I_wanna_know(a_shapes, b_shapes)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}