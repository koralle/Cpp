#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {

    string input_str;
    cin >> input_str;

    int min_753 = 1000 ;
    for(unsigned int i = 0; i < input_str.size() - 2; i++ ) {
        int tmp = (input_str[i] - '0') * 100 + (input_str[i+1] - '0') * 10 + (input_str[i+2] - '0');

        min_753 = min(min_753, abs(tmp - 753));
    }

    cout << min_753 << endl;
    return 0;
}
