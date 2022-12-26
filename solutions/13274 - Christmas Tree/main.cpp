#include <bits/stdc++.h>

using namespace std;

int N, K;
int cost[1000];
vector<int> childs[1000];
vector<int> conn[1000];
bool taken[1000];

// cost = size_of_good_tree
void count_cost(int act) {
    taken[act] = true;
    for (auto i : conn[act]) {
        if (!taken[i]) {
            taken[i] = true;
            childs[act].push_back(i);
            count_cost(i);    
        }
    }
    
    if (childs[act].size() < K) {
        cost[act] = 1;
    } else {
        sort(childs[act].begin(), childs[act].end(), [] (int a, int b) {
            return cost[a] < cost[b];
        });

        int cc = 1;

        for (int i = childs[act].size() - K; i < childs[act].size(); i++) {
            cc += cost[childs[act][i]];
        }

        cost[act] = cc;
    }
}

int main() {

    int test_cases;
    cin >> test_cases;

    for (int tc = 1; tc <= test_cases; tc++) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            childs[i].clear();
            conn[i].clear();
            taken[i] = false;   
        }

        int from, to;
        for (int i = 0; i < N - 1; i++) {
            cin >> from >> to;
            conn[from - 1].push_back(to - 1);
            conn[to - 1].push_back(from - 1);

        }

        count_cost(0);
/*
        for (int i = 0; i < N; i++) {
            cout << i + 1 << ": " << cost[i] << endl;
            for (auto j : childs[i]) cout << " " << j + 1;
            cout << endl;
        }
*/
        cout << "Case " << tc << ": " << cost[0] << endl; 
    }
}
