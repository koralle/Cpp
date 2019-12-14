#include <stack>
#include <iostream>
using namespace std;

int main(void) {
    stack<int> s;

    // push
    s.push(1);
    s.push(2);
    s.push(3);


    // top and pop
    cout << s.top() << endl; //3
    s.pop();
    cout << s.top() << endl; //3
    s.pop();
    cout << s.top() << endl; //3
    s.pop();

    return 0;
}