#include <bits/stdc++.h>

using namespace std;

vector<long long int> LIS;
vector<long long int>NUMBERS;
vector<long long int> lis;

void lis_f(int i) {

    int j = 0;
    while (j < LIS.size() && NUMBERS[i] > LIS[j]) j++;

    if (j == LIS.size()) {
        LIS.push_back(NUMBERS[i]);
    } else if (NUMBERS[i] < LIS[j]) {
        LIS[j] = NUMBERS[i];
    }

    lis.push_back(j);
}

int main() {

    long long int number;

    while (cin >> number) {
        NUMBERS.push_back(number);
    }

    for (int i = 0; i < NUMBERS.size(); i++) lis_f(i);
    cout << LIS.size() << endl << "-" << endl;

    long long int actual = LONG_LONG_MAX;
    std::stack<int> st;
    int sz = LIS.size() - 1;
    
    for (int i = NUMBERS.size() - 1; i >= 0; i--) {
        if (lis[i] == sz && NUMBERS[i] < actual) {
            st.push(NUMBERS[i]);
            actual = NUMBERS[i];
            sz--;
        }
    }

    while (st.size()) {
        cout << st.top() << endl;
        st.pop();
    }
} 