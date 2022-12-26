#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<pair<string, string>> in_lib, borrow, ret;

    map<string, string> auth;   

    string line;
    while (getline(cin, line), line.compare("END")) {
        auto p = line.find_last_of('"');
        auto title = line.substr(0, p + 1);
        auto author = line.substr(p + 5);

        auth[title] = author;
        in_lib.push_back({author, title});
    }
    sort(in_lib.begin(), in_lib.end());
                
    while (getline(cin, line), line.compare("END")) {

        if (line.compare("SHELVE") == 0) {
            sort(ret.begin(), ret.end());
            reverse(ret.begin(), ret.end());
            while (ret.size()) {
                auto back = ret.back();
                ret.pop_back();

                auto ind = distance(in_lib.begin(), upper_bound(in_lib.begin(), in_lib.end(), back));
                if (ind > 0) {
                    cout << "Put " << back.second << " after " << in_lib[ind - 1].second << endl;
                } else {
                    cout << "Put " << back.second << " first" << endl;
                }     

                in_lib.insert(in_lib.begin() + ind, back);
            }
            cout << "END\n";
        } else {
            auto pos = line.find(' ');

            auto action = line.substr(0, pos);
            auto book = line.substr(pos + 1);

            if (action == "BORROW") {
                borrow.push_back({auth[book], book});
                in_lib.erase(find(in_lib.begin(), in_lib.end(), make_pair(auth[book], book)));
            } else {
                ret.push_back({auth[book], book});
                borrow.erase(find(borrow.begin(), borrow.end(), make_pair(auth[book], book)));
            }
        }
    }
}