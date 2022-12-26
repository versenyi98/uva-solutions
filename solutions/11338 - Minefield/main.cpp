#include <bits/stdc++.h>

#define f first
#define s second
#define INF 1000000000

using namespace std;

typedef pair<double, double> pdd;

struct ds {
    int dist = -INF;

    ds& operator=(const int& num) {
        dist = num;
        return *this;
    }

    bool operator<(const int& num) const {
        return dist < num;       
    }

    bool operator==(const int& num) const {
        return dist == num;       
    }
};

double distance_(pdd a, pdd b) {
    return sqrt(pow(a.f - b.f, 2) + pow(a.s - b.s, 2));
}

int main() {

    string first_line;
    size_t space;
    while (getline(cin, first_line), space = first_line.find(' '), first_line[0] != '*') { 

        int rows, columns;
        int safe_pos;
        double max_walk;

        vector<pdd> safe_poses;
        map<pdd, vector<pair<double, pdd>>> dist_from_others;
        priority_queue<pair<double, pdd>> pq;
        map<pdd, ds> dist;

        rows = stoi(first_line.substr(0, space));
        columns = stoi(first_line.substr(space + 1));

        cin >> safe_pos;

        double x, y;
        safe_poses.push_back({0, 0});
        safe_poses.push_back({rows, columns});
        for (int i = 0; i < safe_pos; i++) {
            cin >> x >> y;      
            safe_poses.push_back({x, y});
        }
        cin >> max_walk;
        getline(cin, first_line);

        for (int i = 0; i < safe_pos + 2; i++) {           
            for (int j = i + 1; j < safe_pos + 2; j++) {
                double dd = distance_(safe_poses[i], safe_poses[j]);
                if (dd > 1.50) continue;
                
                dist_from_others[safe_poses[i]].push_back({dd, safe_poses[j]});
                dist_from_others[safe_poses[j]].push_back({dd, safe_poses[i]});

            }            
        }
        dist[{0, 0}] = 0;

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto top = pq.top();
            //cout << top.f << " " << top.s.f << " " << top.s.s << endl;
            pq.pop();

            for (auto i : dist_from_others[top.s]) {
                if (top.f - i.f < -max_walk) continue;
                if (dist[i.s] < top.f - i.f) {
                    dist[i.s] = top.f - i.f;
                    pq.push({top.f - i.f, i.s});
                }
            }
        }

        if (dist[{rows, columns}] == -INF) {
            cout << "Boom!" << endl;
        } else {
            cout << "I am lucky!" << endl;
        }
    }
}
