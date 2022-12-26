#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define MINUS_INF -1000000000

struct ut {

    int ff;
    int ss;
    string tt;

    inline bool operator< (const ut u) const {

        if (ff == u.ff) {
            return ss < u.ss;
        } 
        return ff < u.ff;
    }
};

int main() {

    int varosok_szama;
    while (cin >> varosok_szama, varosok_szama) {
        map<string, vector<pair<string, pair<int, int>>>> kapcsolat;

        string varos;

        while (varosok_szama--) {
            cin >> varos;
        }

        int vonalak;
        int elozo_ido, jelen_ido;
        string elozo_varos, jelen_varos;
        
        cin >> vonalak;

        while (vonalak--) {
            int vonal_hossz;
            cin >> vonal_hossz;

            for (int i = 0; i < vonal_hossz; i++) {
                cin >> jelen_ido >> jelen_varos;
                if (i) kapcsolat[elozo_varos].push_back({jelen_varos, {elozo_ido, jelen_ido}});

                elozo_varos = jelen_varos;
                elozo_ido = jelen_ido;
            }
        }

        int kezdes;
        string indulas, erkezes;
        cin >> kezdes >> indulas >> erkezes;

        // mikor ér oda, mikor indult, hova
        priority_queue<ut> pq;

        ut u;
        u.ff = -kezdes;
        u.ss = -1;
        u.tt = indulas;

        pq.push(u);

        while (!pq.empty() && pq.top().tt != erkezes) {
            auto top = pq.top();
            pq.pop();

            for (auto i : kapcsolat[top.tt]) {
                if (top.ff < -i.s.f) continue;
                ut u1;
                u1.ff = -i.s.s;
                u1.ss = top.ss == -1 ? i.s.f : top.ss;
                u1.tt = i.f;

                pq.push(u1);
            }
        }

        if (pq.empty()) {
            cout << "No connection" << endl;
        } else {
            printf("%.4d %.4d\n", pq.top().ss, -pq.top().ff);
        }
    }
}