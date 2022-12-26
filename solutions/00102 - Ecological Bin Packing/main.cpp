#include <iostream>
#include <map>

using namespace std;

int main() {

    while (true) {
        int n[9];

        int i;
        for (i = 0; i < 9 && scanf("%d", &n[i]) == 1; i++) {}
        if (!i) break;

        map<string, int> m;
        m["BCG"] = n[3] + n[6] + n[2] + n[8] + n[1] + n[4];
        m["BGC"] = n[3] + n[6] + n[1] + n[7] + n[2] + n[5];
        m["CBG"] = n[5] + n[8] + n[0] + n[6] + n[1] + n[4];
        m["CGB"] = n[5] + n[8] + n[1] + n[7] + n[0] + n[3];
        m["GBC"] = n[4] + n[7] + n[0] + n[6] + n[2] + n[5];
        m["GCB"] = n[4] + n[7] + n[2] + n[8] + n[0] + n[3];

        unsigned int minimal = -1;
        string m_string;

        for (auto i : m) {
            if (i.second < minimal) {
                minimal = i.second;
                m_string = i.first;
            }
        }
        
        cout << m_string << " " << minimal << endl;
    }
}