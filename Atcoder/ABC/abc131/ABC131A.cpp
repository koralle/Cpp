#include <iostream>
using namespace std;

int main(){
    string security_code;
    cin >> security_code;

    if (security_code[0] == security_code[1]){
        cout << "Bad" << endl;
        return 0;
    }
    if (security_code[1] == security_code[2]){
        cout << "Bad" << endl;
        return 0;
    }
    if (security_code[2] == security_code[3]){
        cout << "Bad" << endl;
        return 0;
    }

    cout << "Good" << endl;

    return 0;
}
