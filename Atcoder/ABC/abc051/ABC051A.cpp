#include <iostream>
#include <string>
using namespace std;

int main(){
    string input_str;

    cin >> input_str;

    input_str[5] = ' ', input_str[13] = ' ';

    cout << input_str << endl;

    return 0;
}
