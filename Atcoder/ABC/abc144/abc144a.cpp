#include <iostream>
using namespace std;

int main(void){
    int A, B;
    cin >> A >> B;

    if ( (1 <= A && A <= 9) && (1 <= B && B <= 9)){
        cout << A * B << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}