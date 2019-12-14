#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;

    for (int i = 1; i <= 9; i++){
        for (int j = i; j <= 9; j++){
            if (i * j == N) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}