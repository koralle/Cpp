#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const long double PI = (acos(-1));

int main(void){
    long double a, b, x;
    cin >> a >> b >> x;

    long double ans;
    long double mid = (a * a * b) / 2.0;

    if(x <= mid)
        ans = PI / 2.0 - atan((2.0 * x) / (a * b * b));
    else
        ans = atan(2.0 * (a * a * b - x) / (a * a * a));

    cout << setprecision(10) << ans * 180.0 / PI << endl;

    return 0;
}