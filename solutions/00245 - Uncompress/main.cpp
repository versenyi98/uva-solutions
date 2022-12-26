#include <bits/stdc++.h>

using namespace std;

int main() {

    string line;
    vector<string> list_of_words;

    while (getline(cin, line) && line.compare("0") != 0) {
        int last_i = 0;
        int i = 0;

        while (i < line.length() && i < line.length()) {
            if (isalpha(line[i])) {
                while (isalpha(line[i])) {
                    i++;
                }

                if (i != last_i) {
                    string word = line.substr(last_i, i - last_i);
                    if (find(list_of_words.begin(), list_of_words.end(), word) == list_of_words.end()) {
                        list_of_words.push_back(word);
                    }
                    cout << word;
                }
            } else if (isdigit(line[i])) {
                while (isdigit(line[i]) && i < line.length()) {
                    i++;
                }

                int ind = stoi(line.substr(last_i, i - last_i));
                string save = list_of_words[list_of_words.size() - ind];
                cout << save;
                for (int j = list_of_words.size() - ind + 1; j < list_of_words.size(); j++) {
                    list_of_words[j - 1] = list_of_words[j];
                }
                list_of_words[list_of_words.size() - 1] = save;
            } else {
                cout << line[i];
                i++;
            }
            last_i = i;
        }

        cout << endl;

    }
}
