#include <queue>
#include <iostream>
using namespace std;

int main(void){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();

    return 0;
}

