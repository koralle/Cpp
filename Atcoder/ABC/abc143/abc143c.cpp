#include <iostream>
#include <string>

using namespace std;

int main(void){
    int N;
    cin >> N;

    string color_info;
    cin >> color_info;

    int slime_count = 1;
    char s = color_info[0];

    for (unsigned int i = 0; i < color_info.length(); i++){
        if (color_info[i] == s) continue;
        slime_count++;
        s = color_info[i];
    }

    cout << slime_count << endl;

    return 0;
}