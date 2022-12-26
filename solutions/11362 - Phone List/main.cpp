#include <bits/stdc++.h>

using namespace std;

class TRIE {

public:
    bool has_end = false;
    char charachter;
    vector<TRIE*> childs;

    TRIE(char ch, bool has_end) : charachter(ch), has_end(has_end) {

    }

    ~TRIE() {
        for (auto i : childs) delete i;
    }

    void print(int dp = 0) {
        for (int i = 0; i < dp * 2; i++) cout << '-';
        cout << charachter << endl;
        for (auto i : childs) {
            i->print(dp + 1);
        }
    }
};

int main() {

    int TC;
    cin >> TC;

    for (int i = 0; i < TC; i++) {
        int N;
        cin >> N;
        TRIE* root = new TRIE(' ', false);
        TRIE* tree = root;
        string number;

        bool wrong = false;
        for (int j = 0; j < N; j++) {
            cin >> number;
            
            for (int k = 0; k < number.length(); k++) {
                bool has_child = false;
                for (auto l : tree->childs) {
                    if (l->charachter == number[k]) {

                        if (l->has_end) {
                            wrong = true;
                        }

                        if (k == number.length() - 1) {
                            wrong = true;
                        }

                        has_child = true;
                        tree = l;
                        break;
                    }
                }

                if (!has_child) {
                    tree->childs.push_back(new TRIE(number[k], k == number.length() - 1));
                    tree = tree->childs.back();
                }
            }
            tree = root;
        }
        if (wrong) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}