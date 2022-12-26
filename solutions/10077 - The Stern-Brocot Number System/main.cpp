#include <bits/stdc++.h>

using namespace std;

int main() {

    int U, D;

    while (cin >> U >> D, U != 1 || D != 1) {

        int current_U = 1;
        int current_D = 1;

        int last_LU = 0;
        int last_LD = 1;
        int last_RU = 1;
        int last_RD = 0;

        while (current_U != U || current_D != D) {
            if (U * current_D < D * current_U) {
                cout << "L";
                
                int temp_U = current_U;
                int temp_D = current_D;

                current_U += last_LU;
                current_D += last_LD;

                last_RU = temp_U;
                last_RD = temp_D;
            } else {
                cout << "R";;
                
                int temp_U = current_U;
                int temp_D = current_D;

                current_U += last_RU;
                current_D += last_RD;

                last_LU = temp_U;
                last_LD = temp_D;
            }
        }
        cout << endl;
    }
}