#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define MINUS_INF -1000000000

map<string, pair<string, string>> language_of_word;
map<string, vector<string>> words_for_language;
map<string, int> dist;

string from, to;
int word_count;

//                  dist      current_word current_lang
priority_queue<pair<int, pair<string, string>>> pq;

int main() {

    while (cin >> word_count, word_count) {
        pq = priority_queue<pair<int, pair<string, string>>>();
        words_for_language.clear();
        language_of_word.clear();

        cin >> from >> to;

        string lang1, lang2, word;
        for (int i = 0; i < word_count; i++) {
            cin >> lang1 >> lang2 >> word;

            language_of_word[word] = {lang1, lang2};
            words_for_language[lang1].push_back(word);
            words_for_language[lang2].push_back(word);

            dist[word] = MINUS_INF;
        }

        for (auto i : words_for_language[from]) {
            dist[i] = -i.length();
            pq.push({-i.length(), {i,
                language_of_word[i].s == from ?
                    language_of_word[i].f :
                    language_of_word[i].s}}
            );
        }

        while (!pq.empty() && pq.top().s.s != to) {
            auto current = pq.top();
            pq.pop();

            for (auto i : words_for_language[current.s.s]) {
                if (i[0] == current.s.f[0]) continue;

                if (dist[i] < dist[current.s.f] - i.length()) {
                    dist[i] = dist[current.s.f] - i.length();
                    pq.push({dist[i], {i, language_of_word[i].s == current.s.s ? language_of_word[i].f : language_of_word[i].s}});
                }
            }
        }

        if (pq.empty()) {
            cout << "impossivel\n";
        } else {
            cout << pq.top().f * -1 << endl;
        }
    } 
}