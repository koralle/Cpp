#include <bits/stdc++.h>
using namespace std;

int main(void){
    string _input;
    cin >> _input;

    if(_input == "Sunny") cout << "Cloudy" << endl;
    else if(_input == "Cloudy") cout << "Rainy" << endl;
    else if(_input == "Rainy") cout << "Sunny" << endl;

    return 0;
}